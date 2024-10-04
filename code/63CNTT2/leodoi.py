from utils.check import checkin
from utils.graph import draw_graph
from utils.readfile import read_adj, read_h


def HillClimbingSearch(adj, start, stop):
    OPEN = []
    CLOSE = []
    Tn = []
    Parent = [-1] * (len(adj))

    # Step 0:
    OPEN.append(start)

    while len(OPEN) > 0:
        curr = OPEN.pop(0)
        print(f"curr: {curr}")
        CLOSE.append(curr)
        print(f"CLOSE: {CLOSE}")

        if curr == stop:
            print(f"Tim thay duong di {start} -> {stop}")
            path = []
            idx = stop
            while idx!= -1:
                path.insert(0, idx)     # chen vao dau path
                idx = Parent[idx]
            print(f"path: {path}")
            return

        for neighbor in range(len(adj)):
            if adj[curr][neighbor] == 1 and checkin(OPEN, neighbor) == False and checkin(CLOSE, neighbor) == False:
                Tn.append(neighbor)
                Parent[neighbor] = curr

        # Sap xep Tn tang dan theo h
        Tn_sorted = sorted(Tn, key=lambda x: h[x][1], reverse=False)
        Tn = Tn_sorted
        print(f"Tn_sorted: {Tn}")

        # Chen Tn vao dau OPEN
        OPEN = Tn + OPEN
        print(f"OPEN: {OPEN}")

        # Reset Tn
        Tn = []

    # OPEN = 0
    print(f"Khong tim thay duong di {start} -> {stop}")


if __name__ == '__main__':
    n, adj = read_adj('inputs/leodoi.adj')
    h = read_h('inputs/leodoi.h')
    print(f"Number of nodes: {n}")
    print(f"Heuristic: {h}")
    print(f"Adjacency list: ")
    for i in range(n):
        print(f"{adj[i]}")

    # Ve do thi
    draw_graph(adj, "undirected")

    HillClimbingSearch(adj, 0, 6)
