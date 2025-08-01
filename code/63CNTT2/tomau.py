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

def tomau(sodinh,adj):
    bac = [0]*sodinh
    for i in range(sodinh):
        for j in range(sodinh):
            if adj[i][j]==1:
                bac[i]+=1
    print(f"bac do thi: {bac}")
    
    # tao ra danh sach cac dinh 
    OPEN = []
    for i in range(sodinh):
        OPEN.append(i)
    print(f"OPEN = {OPEN}")
    
    # sap xep cac dinh giam dan theo bac 
    OPEN = sorted(OPEN, key=lambda x: bac[x], reverse = True)
    print(f"OPEN sorted by bac: {OPEN}")
    
    # tao ra danh sach mau theo dinh
    color = [-1]*sodinh
    print(f"color = {color}")
    
    # to cho den khi het dinh 
    mau=0
    while len(OPEN)>0:
        n = OPEN.pop(0)
        print(f"n = {n}")
        color[n] = mau
        
        # tim cac dinh khong ke voi n va chua duoc to mau 
        Tn=[]
        for i in range(sodinh):
            if adj[n][i]==0 and color[i]==-1:
                Tn.append(i)
        print(f"cac dinh khong ke voi {n} va chua to mau {Tn}")
        
        # xoa cac dinh ke nhau trong Tn
        for i in Tn:
            for j in Tn:
                if i!=j and adj[i][j]==1:
                    Tn.remove(j)
            print(f"Tn sau khi xoa dinh ke nha: {Tn}")
            
        # to mau cho cac dinh trong Tn
        for i in Tn:
            color[i] = mau
            OPEN.remove(i)
        print(f"color = {color}")
        
        # tang mau cho dinh tiep theo
        mau+=1
    # het dinh:
    print(f"danh sach cac dinh theo mau to: {color}")
    

if __name__=="__main__":
    adj,sodinh = readmtk("tomau.adj")
    tomau(sodinh,adj)
