import sys
import numpy as np

read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

def from_read(dtype=np.int64):
    return np.fromstring(read().decode(), dtype=dtype, sep=' ')

def from_readline(dtype=np.int64):
    return np.fromstring(readline().decode(), dtype=dtype, sep=' ')

N = int(readline())
E = [(u - 1, v - 1, w & 1) for u, v, w in from_read().reshape(-1, 3)]

G = [[] for i in range(N)]
for u, v, w in E:
    G[u].append((v, w))
    G[v].append((u, w))

color = [0] * N
stack = [0]
parent = [0] * N 
while stack:
    u = stack.pop()
    for v, w in G[u]:
        if v == parent[u]:
            continue
        parent[v] = u
        color[v] = color[u] ^ w
        stack.append(v)

print('\n'.join(map(str, color)))