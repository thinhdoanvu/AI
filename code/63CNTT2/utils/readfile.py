import os


def read_adj(filename):
    if not os.path.exists(filename):
        print("File not found")
        return None

    with open(filename, 'r') as f:
        n = int(f.readline().strip())
        adj = []
        for i in range(n):
            line = list(map(int, f.readline().strip().split()))
            adj.append(line)
    return n, adj

def read_h(filename):
    if not os.path.exists(filename):
        print("File not found")
        return None

    with open(filename, 'r') as f:
        n = int(f.readline().strip())
        h = []
        for i in range(n):
            line = list(map(int, f.readline().strip().split()))
            h.append(line)
    return h
