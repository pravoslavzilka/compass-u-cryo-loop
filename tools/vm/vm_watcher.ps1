# Runs INSIDE the VM (PowerShell), in the logged-in desktop session.
# Watches <Root>\vm-inbox for a request file and runs a Dymola .mos script.
#
#   Start:   powershell -ExecutionPolicy Bypass -File Z:\compass-u-cryo-loop\tools\vm\vm_watcher.ps1
#   Request (from the host or the VM): create  <Root>\vm-inbox\run.request  containing
#       script=dymola-thermal-systems/CoilLoopCompassU/CS/auto_translate_log.mos
#       timeout_min=60
#     (both lines optional; the values shown are the defaults)
#   Cancel:  create  <Root>\vm-inbox\cancel   (kills the running Dymola, then the file is removed)
#   Stop the watcher: create  <Root>\vm-inbox\quit
#   State:   <Root>\vm-inbox\watcher_status.txt (heartbeat every poll), watcher.log

param(
  [string]$Root = "Z:\compass-u-cryo-loop",
  [string]$DymolaExe = "C:\Program Files\Dymola 2025x\bin64\Dymola.exe",  # CHECK this path in the VM
  [int]$PollSeconds = 3,
  [int]$DefaultTimeoutMin = 60,
  [string]$DefaultScript = "dymola-thermal-systems/CoilLoopCompassU/CS/auto_translate_log.mos"
)

$inbox   = Join-Path $Root "vm-inbox"
$request = Join-Path $inbox "run.request"
$running = Join-Path $inbox "run.request.running"
$cancel  = Join-Path $inbox "cancel"
$quit    = Join-Path $inbox "quit"
$status  = Join-Path $inbox "watcher_status.txt"
$logf    = Join-Path $inbox "watcher.log"
$wrapper = Join-Path $inbox "_wrapper.mos"
New-Item -ItemType Directory -Force -Path $inbox | Out-Null

function Log($m) { "$(Get-Date -Format 'yyyy-MM-dd HH:mm:ss')  $m" | Add-Content $logf }
function SetStatus($m) { "$m`r`nupdated: $(Get-Date -Format 'yyyy-MM-dd HH:mm:ss')" | Set-Content $status }
function KillDymola($p) {
  if ($p -and -not $p.HasExited) { Stop-Process -Id $p.Id -Force -ErrorAction SilentlyContinue }
  Get-Process dymosim -ErrorAction SilentlyContinue | Stop-Process -Force -ErrorAction SilentlyContinue
}

Log "watcher started, root=$Root"
while ($true) {
  if (Test-Path $quit) { Remove-Item $quit -Force; Log "quit"; SetStatus "STOPPED"; break }
  if (Test-Path $cancel) { Remove-Item $cancel -Force }   # stale cancel while idle

  # A request is taken only when it has been untouched for 2 s (writer finished).
  if ((Test-Path $request) -and ((Get-Date) - (Get-Item $request).LastWriteTime).TotalSeconds -gt 2) {
    try { Move-Item $request $running -Force -ErrorAction Stop } catch { Start-Sleep 1; continue }

    $opt = @{ script = $DefaultScript; timeout_min = "$DefaultTimeoutMin" }
    foreach ($line in Get-Content $running) {
      if ($line -match '^\s*(script|timeout_min)\s*=\s*(.+?)\s*$') { $opt[$matches[1]] = $matches[2] }
    }
    $script = (Join-Path $Root ($opt.script -replace '/', '\'))
    $timeout = [int]$opt.timeout_min

    # Only scripts inside the shared project folder may be run.
    $full = [System.IO.Path]::GetFullPath($script)
    if (-not $full.StartsWith([System.IO.Path]::GetFullPath($Root), [StringComparison]::OrdinalIgnoreCase) -or -not (Test-Path $full)) {
      Log "REJECTED request, script not found or outside root: $($opt.script)"
      SetStatus "REJECTED: $($opt.script)"
      Remove-Item $running -Force
      continue
    }

    $fwd = $full -replace '\\', '/'
    "RunScript(""$fwd"");`r`nexit();" | Set-Content $wrapper -Encoding ASCII

    Log "START $($opt.script) timeout=${timeout}min"
    SetStatus "RUNNING: $($opt.script) since $(Get-Date -Format 'HH:mm:ss'), timeout ${timeout} min"
    $p = Start-Process -FilePath $DymolaExe -ArgumentList @("/nosplash", "`"$wrapper`"") -PassThru
    $t0 = Get-Date
    $result = "FINISHED"
    while (-not $p.HasExited) {
      Start-Sleep -Seconds 2
      if (Test-Path $cancel)  { Remove-Item $cancel -Force; $result = "CANCELLED"; KillDymola $p; break }
      if (((Get-Date) - $t0).TotalMinutes -gt $timeout) { $result = "TIMEOUT"; KillDymola $p; break }
    }
    $min = [math]::Round(((Get-Date) - $t0).TotalMinutes, 1)
    Log "$result after $min min (exit code $($p.ExitCode))"
    SetStatus "IDLE. Last run: $result after $min min, $($opt.script)"
    Remove-Item $running -Force -ErrorAction SilentlyContinue
    continue
  }

  SetStatus "IDLE, waiting for $request"
  Start-Sleep -Seconds $PollSeconds
}
