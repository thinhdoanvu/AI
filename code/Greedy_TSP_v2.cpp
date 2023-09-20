#include<stdio.h>
#include<limits.h>
#define MAX 100
#define INPUT "TSP.inp"

//khai bao bien
FILE *fp;
int sodinh;
int mtk[MAX][MAX];
int vet[MAX];

void inmt(int mt[][MAX], int size){
    for(int i=0; i<sodinh; i++){
        for(int j=0; j<sodinh; j++){
            printf("%7d",mt[i][j]);
        }
        printf("\n");
    }
}

void readfile(){
    fp=fopen(INPUT,"r");
    if(fp==NULL){
        printf("File not found");
        return;
    }
    else{
        fscanf(fp,"%d",&sodinh);
        printf("So dinh can duyet: %d",sodinh);
        for(int i=0; i<sodinh; i++){
            for(int j=0; j<sodinh; j++){
                fscanf(fp,"%d",&mtk[i][j]);
            }
        }
        printf("\nMa tran ke: \n");inmt(mtk,sodinh);
        fclose(fp);
    }
}

void init(int mang[], int size, int value){
    for(int i=0; i<size; i++){
        mang[i]=value;
    }
}

void inmang(int mang[], int size){
    for(int i=0; i<size; i++){
        printf("%d  ",mang[i]);
    }
}


void TSP(int start){
    int n = start;
    int thutuduyet = 1;
    //khoi tao gia tri cua vet: cac dinh da duoc duyet
    init(vet,sodinh,0);
    vet[n]=thutuduyet++;
    //danh sach cac dinh can xem xet
    int Tn[MAX];
    //sodinh da duyet
    int duyet = 1;

    printf("\nDinh xuat phat = %d",n);
    while(duyet<sodinh){
        //tim dinh ke dinh dang xet co trong so be nhat va chua tung duoc duyet
        int GTmin=INT_MAX;
        int posmin;
        for(int i=0; i<sodinh; i++){
            if(i!=n && vet[i]==0 && GTmin>mtk[n][i]){
                GTmin = mtk[n][i];
                posmin=i;
            }
        }
        n=posmin;
        vet[n]=thutuduyet++;
        printf("\nDinh ke tiep: %d",n);
        printf("\nVET: ");inmang(vet,sodinh);
        duyet++;
    }
}

void swap(int &x, int &y){
    int tam=x;x=y;y=tam;
}

void induongdi(){
    //sap xep mang vet theo thu tu tang dan
    int duongdi[MAX];
    for(int i=0; i<sodinh; i++){
        duongdi[i]=i+1;
    }
    for(int i=0; i<sodinh-1;i++){
        for(int j=i+1; j<sodinh; j++){
            if(vet[i]>vet[j]){
                swap(vet[i],vet[j]);
                swap(duongdi[i],duongdi[j]);
            }
        }
    }
    printf("\nDuong di: ");inmang(duongdi,sodinh);
}
int main(){
    readfile();
    TSP(0);
    induongdi();
    return 0;
}