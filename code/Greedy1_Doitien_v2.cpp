#include<stdio.h>
#define INPUT "doitien_1.inp"
#define MAX 100

//bien toan cuc
int sotien;
int soto;
int mg[MAX];
FILE *fp;
int VET[MAX];

void init(int m[], int size, int value){
    for(int i=0; i<size; i++){
        m[i]=value;
    }
}

void inmang(int m[], int size){
  for(int i=0; i<size; i++){
    printf("%d  ",m[i]);
  }
}

void swap(int* x, int* y){
    int tam=*x;
    *x = *y;
    *y = tam;
}

void sortgiam(int m[], int size){
    for(int i=0; i<size-1; i++){
        for(int j=i+1; j<size; j++){
            if(m[i]<m[j]){
                swap(&m[i],&m[j]);
            }
        }
    }
    inmang(m,size);
}

void Greedy1(){
    init(VET,soto,0);
    printf("\nDay sau khi sap xep: ");
    sortgiam(mg,soto);
    for(int i=0; i<soto; i++){
        if(sotien>=mg[i]){
            sotien = sotien - mg[i];
            VET[i]=1;
            printf("\nSo tien con lai: %d",sotien);
        }
    }
    if(sotien>0){
        printf("\nKhong doi duoc");
    }
    else{
        printf("\nDoi thanh cong");
        printf("\nCac to tien da doi duoc: ");
        //inmang(VET,soto);
        for(int i=0; i<soto; i++){
            if(VET[i]==1){
                printf("%d  ",mg[i]);
            }
        }
    }
}

void readfile(){
    fp=fopen(INPUT,"r");
    if(fp==NULL){
        printf("File not found");
    }
    else{
        fscanf(fp,"%d",&sotien);
        printf("\nSo tien can doi: %d", sotien);
        fscanf(fp,"%d",&soto);
        printf("\nSo to tien cho truoc: %d", soto);
        for(int i=0; i<soto; i++){
            fscanf(fp,"%d",&mg[i]);
        }
        printf("\nMenh gia cho tung loai tien: \n");
        inmang(mg,soto);
        fclose(fp);
    }
}

int main(){
    readfile();
    Greedy1();
    return 0;
}