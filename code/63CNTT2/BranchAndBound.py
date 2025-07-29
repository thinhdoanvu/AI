def readmtk(filename):
    with open(filename) as f:
        sodinh = int(f.readline().strip())
        print(sodinh)
        adj=[]
        for i in range(sodinh):
            line = list(map(int, f.readline().split()))
            print(line)
            adj.append(line)
    return adj,sodinh

def readh(filename):
    with open(filename) as f:
        h = list(map(int, f.readline().split()))
        print(h)
    return h

def BranchandBound(sodinh,adj,h,start,stop):
    OPEN = [start]
    fmin = float('inf')
    flag = False
    g = [float('inf')]*sodinh
    f = [float('inf')]*sodinh
    g[start]=0
    f[start]=h[start]
    CHA = [-1]*sodinh
    CLOSE=[]
    print(f"g = {g}")
    print(f"f = {f}")
    print(f"CHA = {CHA}")
    
    while len(OPEN)>0:
        n = OPEN.pop(0)
        print(f"n = {n}")
        CLOSE.append(n)
        print(f"CLOSE = {CLOSE}")
        
        if n==stop:
            flag = True
            if f[n] < fmin:
                print(f"cap nhat fmin: {f[n]}")
                fmin = f[n]
        elif f[n] > fmin:
            print(f"f[{n}] > {fmin}: cat bo nhanh con")
        elif f[n] < fmin:
            print(f"tim cac dinh ke cua {n}: ")
            Tn=[] # reset Tn
            for i in range(sodinh):
                if adj[n][i] > 0: # co dinh ke tu n den i
                    # TH1: n khong thuoc (OPEN va CLOSE)
                    if i not in OPEN and i not in CLOSE:
                        print(f"{i} NOT in OPEN, {i} NOT in CLOSE")
                        g[i] = g[n]+ adj[n][i]
                        f[i] = g[i] + h[i]
                        Tn.append(i)
                        CHA[i] = n
                    # TH2: n thuoc OPEN nhung khong thuoc CLOSE
                    if i in OPEN and i not in CLOSE:
                        print(f"{i} in OPEN, {i} NOT in CLOSE")
                        gnew = g[n]+ adj[n][i]
                        fnew = gnew + h[i]
                        print(f"fnew = {fnew}")
                        if fnew < f[i]:
                            print(f"cap nhat f, g, cha")
                            f[i] = fnew
                            g[i] = gnew
                            CHA[i] = n
                            # Khong chen i vao Tn
                    # TH3: n thuoc CLOSE nhung khong thuoc OPEN
                    if i in CLOSE and i not in OPEN:
                        print(f"{i} in CLOSE, {i} NOT in OPEN")
                        gnew = g[n]+ adj[n][i]
                        fnew = gnew + h[i]
                        print(f"fnew = {fnew}")
                        if fnew < f[i]:
                            print(f"cap nhat f, g, cha")
                            f[i] = fnew
                            g[i] = gnew
                            CHA[i] = n
                            Tn.append(i)
                    # TH4: n thuoc (OPEN va CLOSE)
                    if i in CLOSE and i in OPEN:
                        print(f"{i} in CLOSE, {i} in OPEN")
                        gnew = g[n]+ adj[n][i]
                        fnew = gnew + h[i]
                        print(f"fnew = {fnew}")
                        if fnew < f[i]:
                            print(f"cap nhat f, g, cha")
                            f[i] = fnew
                            g[i] = gnew
                            CHA[i] = n
                            # khong chen vao Tn
            print(f"g = {g}")
            print(f"f = {f}")
            print(f"Tn = {Tn}")
            Tn = sorted(Tn, key = lambda x: f[x])
            OPEN = Tn + OPEN
            print(f"OPEN = {OPEN}")
            print(f"CHA = {CHA}")
    # het while
    if not flag:
        print(f"Khong tim thay duong di tu {start} den {stop}")
    else:
        print(f"Tim thay duong di tu {start} den {stop}")
        i = stop
        while i != -1:
            print(i, end = " <== ")
            i = CHA[i]
    
if __name__ == "__main__":
    adj,sodinh = readmtk("bb.mtk")
    h = readh("bb.h")
    BranchandBound(sodinh,adj,h,0,1)