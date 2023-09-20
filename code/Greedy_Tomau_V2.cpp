#include<stdio.h>
#define INPUT "Tomau.inp"
#define MAX 20

//bien toan cuc
int sodinh;
int mtk[MAX][MAX];
FILE *fp;
int bdt[MAX];
int V[MAX]={0,1,2,3,4,5,6};

void inmt(int a[][MAX], int col){
    for(int i=0; i<col;i++){
        for(int j=0; j<col; j++){
            printf("%d  ",a[i][j]);
        }
        printf("\n");
    }
}

void readfile(){
    fp = fopen(INPUT,"r");
    if(fp==NULL){
        printf("File not found");
    }
    else{
        fscanf(fp,"%d",&sodinh);
        printf("\nSo dinh cua do thi: %d",sodinh);
        //doc cac dinh cua do thi
        for(int i=0; i<sodinh;i++){
            for(int j=0; j<sodinh; j++){
                fscanf(fp,"%d",&mtk[i][j]);
            }
        }
        fclose(fp);
    }
    //in ra ma tran ke
    printf("\nMa tran ke cac thanh pho\n");
    inmt(mtk,sodinh);
}

void init(int mang[], int size, int value){
    for(int i=0;i<size; i++){
        mang[i]=value;
    }
}

void inmang(int mang[], int size){
    for(int i=0; i<size; i++){
        printf("%d  ",mang[i]);
    }
}

void bacdothi(){
    init(bdt,sodinh,0);
    printf("\nSo bac cua cac dinh:\n");
    for(int i=0; i<sodinh; i++){
        int count=0;
        for(int j=0; j<sodinh; j++){
        if(i!=j && mtk[i][j]!=0){
                count++;
            }
        }
        bdt[i]=count;
    }
    inmang(bdt,sodinh);
}

int timmax(int mang[], int size){
    int max = mang[0];
    int posmax=0;
    for(int i=1;i<size; i++ ){
        if(max<mang[i]){
            max=mang[i];
            posmax=i;
        }
    }
    return posmax;
}

void tomau(){
  printf("\nBac cua do thi: \n");
  inmang(bdt,sodinh);
  printf("\nThanh pho: \n");
  inmang(V,sodinh);
  printf("\nThanh pho co bac max = %d\n",V[timmax(bdt,sodinh)]);

  int COLOR[MAX]={0,0,0,0,0,0,0};
  for(int color=1; color<=3; color++){
    int max = timmax(bdt,sodinh);
    COLOR[V[max]]=color;
    bdt[V[max]]=-99;
    for(int i=0; i<sodinh; i++){
        if(mtk[V[max]][i]==0 && COLOR[i]==0){
            COLOR[V[i]]=color;
            bdt[V[i]]=-99;
        }
    }
    printf("\nCOLOR: \n");inmang(COLOR,sodinh);
    //printf("\nBac do thi: \n");inmang(bdt,sodinh);
    //printf("\nThanh pho: \n");inmang(V,sodinh);
    //printf("\nThanh pho co bac max = %d\n",V[timmax(bdt,sodinh)]);
  }
  
}


int main(){
    readfile();
    bacdothi();
    tomau();
    return 0;
}