#include<stdio.h>
#define INPUT "BFS_DFS_1.txt"
#define MAX 20

//khai bao bien
FILE *fp;
int N;
int n;
int a[MAX][MAX];//ma tran ke
int visited[MAX];//dinh da xet
int OPEN[MAX];//dinh tiem nang
int Tn[MAX];//dinh ke dinh dang xet
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


void BFS(int a[][MAX], int start, int goal){
    //khoi tao mang visited, Tn, Parent
    init(visited,N);
    init(Tn,N);
    //Parent
    for(int i=0; i<N; i++){
        Parent[i]=-1;
    }

    int dem=0;

    OPEN[dem]=start;
    Tn[start]=-1;//dinh da duoc dua vao OPEN
    Parent[start]=-1;

    printf("Dinh xuat phat: %d\n",start);
    printf("Dinh ket thuc: %d\n",goal);
    //lay n ra khoi OPEN
    while(dem>=0){
        //lay ra o dau danh sach
        n=OPEN[0];
        printf("\nDinh dang xet: %d\n",n);
        //dich chuyen toan bo danh sach len dau
        for(int j=0; j<dem; j++){
            OPEN[j]=OPEN[j+1];
        }

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
            for(int i=0; i<N; i++){
                if(a[n][i]!=0 && visited[i]!=-1 && Tn[i]==0){
                    //chen vao cuoi danh sach
                    OPEN[dem++]=i;
                    Tn[i]=-1;
                    //luu tru nut cha
                    Parent[i]=n;
                }
            }
            printf("\nOPEN: \n");
            inmang(OPEN,dem);
            printf("\nParent:\n");
            inmang(Parent,N);
         dem--;   
        }
        
    }
    	
}

int main(){
    input();
    printf("Cac dinh cua do thi: \n");
    in_mtk(a,N);
    printf("\nBreath First Search:\n");
    BFS(a,0,5);
    return 0;
}