from utils.readfile import read_adj
from utils.check import checkin


def bfs_dfs(adj, start, stop, type):
    OPEN = []
    CLOSE = []
    Tn = []
    Parent = [-1]*len(adj)  # [-1 -1 -1 -1 .... -1]

     # khoi tao gia tri
    OPEN.append(start)  # dua start vao cuoi OPEN

    while len(OPEN) > 0:    # OPEN khac rong
        curr = OPEN.pop(0)  # lay ra o dau OPEN
        print(f"curr: {curr}")
        CLOSE.append(curr)
        print(f"CLOSE: {CLOSE}")

        if curr == stop:
            print(f"Tim thay duong di")
            path = []
            idx = stop
            while idx != -1:
                path.insert(0, idx)
                idx = Parent[idx]

            print(f"path: {path}")
            return

        # else: chua phai la dinh stop
        for neighbor in range(n):
            if adj[curr][neighbor] == 1 and checkin(OPEN, neighbor) == False and checkin(CLOSE, neighbor) == False:
                Tn.append(neighbor)     # dua vao tap dinh ke
                Parent[neighbor] = curr

        print(f"Tap dinh ke: {Tn}")
        if type == "BFS":
            OPEN = OPEN + Tn    # chen Tn vao cuoi OPEN
        else:   # DFS
            OPEN = Tn + OPEN    # chen Tn vao dau OPEN

        print(f"OPEN: {OPEN}")
        Tn = []     # reset Tn
        print(f"Parent: {Parent}")

    print("Khong tim thay duong di")


if __name__ == '__main__':
    n, adj = read_adj('inputs/dfs.adj')
    print(f"Number of nodes: {n}")
    for i in range(n):
        print(f"Node {i}: {adj[i]}")

    bfs_dfs(adj, 0, 6, "DFS")