#include<stdio.h>
// #define MTK "Leodoi_1.mtk"
// #define H "Leodoi_1.h"
// #define MTK "Leodoi_2.mtk"
// #define H "Leodoi_2.h"
#define MTK "Leodoi_3.mtk"
#define H "Leodoi_3.h"
#define MAX 100

int sodinh;
FILE* fp;
int mtk[MAX][MAX];
int h[MAX];

void inmt(int mt[][MAX], int size){
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            printf("%2d",mt[i][j]);
        }
        printf("\n");
    }
}

void inmang(int mang[], int size){
    for(int i=0; i<size; i++){
        printf("%d  ",mang[i]);
    }
}

void readmtk(){
    fp=fopen(MTK,"r");
    if(fp==NULL){
        printf("file not found\n");
        return;
    }
    else{
        fscanf(fp,"%d",&sodinh);
        for(int i=0; i<sodinh; i++){
            for(int j=0; j<sodinh; j++){
                fscanf(fp,"%d",&mtk[i][j]);
            }
        }
        fclose(fp);
    }
    //in ra cac gia tri
    printf("\nSo dinh cua do thi:  %d",sodinh);
    printf("\nMa tran ke cua do thi:\n"); inmt(mtk,sodinh);
}

void readh(){
    fp=fopen(H,"r");
    if(fp==NULL){
        printf("file not found\n");
        return;
    }
    else{
        fscanf(fp,"%d",&sodinh);
        for(int i=0; i<sodinh; i++){
            fscanf(fp,"%d",&h[i]);
        }
        fclose(fp);
    }
    //in ra trong so cua cac dinh
    printf("Trong so h: "); inmang(h,sodinh);
}

void init(int mang[], int size, int value){
    for(int i=0; i<size; i++){
        mang[i]=value;
    }
}

void swap(int &x, int &y){
    int tam=x; x=y; y=tam;
}

void HillClimbingSearch(int start, int goal){
    int OPEN[MAX];
    int CLOSE[MAX];
    int Tn[MAX];
    int n;
    int dem;
    int cha[MAX];
    //khoi tao cac gia tri
    dem=0;
    OPEN[dem]=start;
    init(CLOSE,sodinh,0);
    init(Tn,sodinh,0);
    init(cha,sodinh,-1);


    while(dem>=0){
        n=OPEN[dem--];
        printf("\nDinh dang xet: %d",n);
        CLOSE[n]=-1;
        printf("\nCLOSE: ");inmang(CLOSE,sodinh);
        Tn[n]=-1;
        if(n==goal){
            printf("\nTim thay duong di tu %d -> %d",start, goal);
            //in ra cac nut co gia tri cua cha
            printf("\nGia tri cac nut cha: ");inmang(cha,sodinh);
            //in ra duong di
            int len=0;
            int path[MAX];
            for (int i = goal; i != -1; i = cha[i]) {
                path[len++] = i;
            }
            printf("\nDuong di tu %d den %d: ", start, goal);
            for (int i = len - 1; i >= 0; i--) {
                printf("%d ", path[i]);
            }
            return;
        }
        else{
            //tim cac dinh ke cua n: chua xet (chua co trong CLOSE && chua co trong OPEN)
            int lentam=0;//so phan tu cua mang tam
            int tam[MAX];//mang chua trong so

            for(int i=0; i<sodinh; i++){
                if(mtk[n][i]!=0 && CLOSE[i]!=-1 && Tn[i]!=-1){
                    tam[lentam++]=i;
                    Tn[i]=-1;
                    cha[i]=n;
                }
            }
            printf("\nTn: ");inmang(Tn,sodinh);
            //sap xep giam dan cac dinh theo trong so h va chen cuoi OPEN[] vi khi ta lay ra cung tu cuoi
            for(int i=0; i<lentam; i++){
                for(int j=i+1; j<lentam; j++){
                    if(h[tam[i]]<h[tam[j]]){
                        //doi cho cho tam
                        swap(tam[i],tam[j]);
                    }
                }
            }
            printf("\ntam sau SX: ");inmang(tam,lentam);
            //chen cac phan tu cua tam vao OPEN
            //vi tam la day giam nen ta chen tu dau tam -> OPEN tang dan theo so luong
            for(int i=0; i<lentam; i++){
                OPEN[++dem]=tam[i];//vi n=OPEN[dem--] nen dem = -1
            }
            printf("\nOPEN: ");inmang(OPEN,dem+1);
        }
    }
}

int main(){
    readmtk();
    readh();
    //INPUT 1
    // HillClimbingSearch(0,7);
    //INPUT2
    //HillClimbingSearch(0,8);
    //INPUT3
    HillClimbingSearch(0,13);
    return 0;
}