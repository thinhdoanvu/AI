def readmtk(filename):
    with open(filename) as f:
        sodinh = int(f.readline().strip())
        print(sodinh)
        adj=[]
        for i in range(sodinh):
            line = list(map(int, f.readline().split()))
            print(line)
            adj.append(line)
    return sodinh, adj

def timbac(sodinh,adj):
    d = [0]*sodinh
    for i in range(sodinh):
        for j in range(sodinh):
            if adj[i][j] == 1:
                d[i]+=1
    print(f"bac cua do thi: {d}")
    return d
    
def tomau(sodinh, adj, d):
    # print(adj)
    dinh=[]
    mamau = 0
    # CLOSE = []
    
    for i in range(sodinh):
        dinh.append(i)
    color = [-1]*sodinh
    print(f"color = {color}")
    
    dinh = sorted(dinh, key = lambda x: d[x], reverse = True)
    print(f"dinh giam dan theo bac: {dinh}")
    
    while len(dinh)>0:
        n = dinh.pop(0)
        print(f"n = {n}")
        # CLOSE.append(n)
        # print(f"CLOSE = {CLOSE}")
        color[n] = mamau
        # tim cac dinh khong ke voi n, chua to mau
        flag = []
        for i in range(sodinh):
            if adj[n][i] == 0 and color[i] == -1:
                color[i] = mamau 
                flag.append(i)
        mamau +=1 # tang mamau len mau ke tiep
        print(f"tap cac dinh khong ke voi {n} la: {flag}")
        
        # xoa cac dinh chua to mau nhung ke nhau, gan color = -1
        for i in range(len(flag)):
            for j in range(i+1,len(flag)):
                if adj[flag[i]][flag[j]] == 1: # co 2 dinh ke nhau trong tap chua to 
                    print(flag[j])
                    color[flag[j]] = -1
                    
        # xoa cac dinh da tomau
        for i in flag:
            if i in dinh:
                dinh.remove(i)
        print(f"color = {color}")
    return True

if __name__ == "__main__":
    sodinh, adj = readmtk("tomau.mtk")
    d = timbac(sodinh,adj)
    tomau(sodinh,adj,d)