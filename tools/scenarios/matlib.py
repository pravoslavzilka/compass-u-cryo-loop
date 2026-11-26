"""Read a Dymola result.mat (format 1.1, transposed) into {name: (time, values)} / constants."""
import numpy as np, scipy.io as sio

class Result:
    def __init__(self, path):
        m = sio.loadmat(path)
        nm = m['name']; N = len(nm[0])
        self.names = [''.join(nm[j][i] for j in range(len(nm))).strip() for i in range(N)]
        self.idx = {n: i for i, n in enumerate(self.names)}
        self.di = m['dataInfo']; self.d1 = m['data_1']; self.d2 = m['data_2']
        self.time = self.d2[0, :].astype(float)
    def get(self, name):
        i = self.idx[name]; f = int(self.di[0, i]); c = int(self.di[1, i])
        sign = -1.0 if c < 0 else 1.0; c = abs(c) - 1
        if f == 1:   # constant over the run
            return np.full_like(self.time, sign * float(self.d1[c, 0]))
        return sign * self.d2[c, :].astype(float)
    def has(self, n): return n in self.idx
