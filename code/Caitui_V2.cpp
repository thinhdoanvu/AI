#include<stdio.h>
#define INPUT "caitui1.input"
#define MAX 50

FILE* fp;
int Pmax;
int n;
int P[MAX], W[MAX];
float CS[MAX];

void inmang(int m[], int size){
    for(int i=0; i<size; i++){
        printf("%d  ",m[i]);
    }
}

void readfile(){
  fp=fopen(INPUT,"r");
  if(fp==NULL){
    printf("File not found");
  }
  else{
    //so do vat
    fscanf(fp,"%d",&n);
    //Pmax
    fscanf(fp,"%d",&Pmax);
    //doc gia tri cua P va W trong input
    int mang[MAX];
    for(int i=0; i<2*n; i++){
        fscanf(fp,"%d",&mang[i]);
    }
    //trich ra thong tin cho P[] va W[]
    int dem=0;
    for(int i=0;i<2*n; i=i+2){
        W[dem] = mang[i];
        P[dem++]=mang[i+1];
    }
    //trong so cac vat co P/W
    for(int i=0; i<n; i++){
        CS[i]=(float)P[i]/W[i];
    }
    fclose(fp);
  }
    //in ra cac gia tri
    printf("\nSo do vat: %d",n);
    printf("\nPmax = %d",Pmax);
    printf("\nGia tri cac do vat: ");inmang(P,n);
    printf("\nTrong luong cac do vat: ");inmang(W,n);
    printf("\nP[]/W[]: ");
    for(int i=0; i<n; i++){
        printf("%.2f  ",CS[i]);
    }
    printf("\n");
}

void swap(int *x, int *y){
    int tam=*x;
    *x=*y;
    *y=tam;
}

void swap2(float *x, float *y){
    float tam=*x;
    *x=*y;
    *y=tam;
}

void sapxeptang(){
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(CS[i] < CS[j]){
                swap2(&CS[i],&CS[j]);
                swap(&P[i],&P[j]);
                swap(&W[i],&W[j]);
            }
        }
    }
    printf("\nSau khi sap xep giam dan:");
    printf("\nGia tri cac do vat: ");inmang(P,n);
    printf("\nTrong luong cac do vat: ");inmang(W,n);
    printf("\nP[]/W[]: ");
    for(int i=0; i<n; i++){
        printf("%.2f  ",CS[i]);
    }
}

void init(int mang[], int size, int value){
    for(int i=0; i<size; i++){
        mang[i]=value;
    }
}

void Greedy(){
    int Value=0;
    int VET[n];
    init(VET,n,-1);
    for(int i=0;i<n; i++){
        printf("\nTrong luong con lai: %d",Pmax);
        if(Pmax>=W[i]){
            Pmax-=W[i];
            Value+=P[i];
            VET[i]=1;
        }
    }

    printf("\nGia tri cua tui sau khi lay: %d",Value);
    printf("\nVET: ");inmang(VET,n);
}

int main(){
    readfile();
    sapxeptang();
    Greedy();
    return 0;
}
