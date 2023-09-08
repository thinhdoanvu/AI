#include<stdio.h>
#define INPUT "BFS_DFS_1.txt"
#define MAX 20

//khai bao bien
FILE *fp;
int N;
int a[MAX][MAX];
int visited[MAX];
int T[MAX];
int OPEN[MAX];
int Parent[MAX];//danh sach cac nut cha

void init(int mang[], int size){
    for(int i=0; i<size; i++){
        mang[i]=0;
    }
}

void input(){
    fp = fopen(INPUT,"r");
    if(fp == NULL){
        printf("File not found\n");
    }
    else{
        fscanf(fp,"%d",&N);
        printf("So dinh cua do thi: %d\n",N);
        //doc tung dinh cua do thi
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                fscanf(fp,"%d",&a[i][j]);
            }
        }
        fclose(fp);
    }
}

void in_mtk(int a[][MAX], int size){
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            printf("%d  ",a[i][j]);
        }
        printf("\n");
    }
}

void inmang(int mang[], int size){
    for(int i=0; i<size; i++){
        printf("%d  ",mang[i]);
    }
    printf("\n");
}

//chen dinh moi vao cuoi danh sanh va lay ra tu cuoi DS
void DFS(int a[][MAX], int start, int goal){
    //khoi tao mang visited
    init(visited,N);
    //Parent
    for(int i=0; i<N; i++){
        Parent[i]=-1;
    }

    int n;
    int dem=0;

    OPEN[dem++]=start;
    Parent[start]=-1;
    printf("Dinh xuat phat: %d\n",start);
    printf("Dinh ket thuc: %d\n",goal);
    //lay n ra khoi OPEN tu cuoi danh sach
    while(dem!=0){
        n=OPEN[dem--];
        printf("\nDinh dang xet: %d\n",n);

        //dua dinh da xet vao visited
        visited[n]=-1;

        if(n==goal){
            printf("\nTim thay duong di tu %d den %d\n",start,goal);
            // In ra duong di bang cach in nguoc danh sach tu start
            int path[n], len = 0;
            for (int i = goal; i != -1; i = Parent[i]) {
                path[len++] = i;
            }
            printf("\nDuong di tu %d den %d: ", start, goal);
            for (int i = len - 1; i >= 0; i--) {
                printf("%d ", path[i]);
            }
            return;
        }
        else{
            //dua cac dinh ke cua n vao danh sach OPEN
            for(int i=0; i<N; i++){
                //neu dinh dang xet co ket noi voi dinh khac va chua duoc xet
                if(a[n][i]!=0 && visited[i]!=-1){
                    OPEN[dem++]=i;   
                    //luu tru nut cha
                    Parent[i]=n;
                }
            }
            
            printf("\nDanh sach OPEN:\n");
            inmang(OPEN,dem);
            
            printf("\nDanh sach dinh da xet: \n");
            inmang(visited,N);

            dem--;
        }
    }
}

int main(){
    input();
    printf("Cac dinh cua do thi: \n");
    in_mtk(a,N);
    printf("\nDepth First Search:\n");
    DFS(a,0,5);
    return 0;
}