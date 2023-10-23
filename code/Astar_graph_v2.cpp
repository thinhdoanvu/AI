#include<stdio.h>
#define MAX 100
#define MTK "Astar_graph2.inp"
#define H "Astar_graph2.h"

//khai bao bien
FILE *fp;
int mtk[MAX][MAX];
int sodinh;
int h[MAX];

void inmt(int mt[][MAX], int size){
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			printf("%d\t",mtk[i][j]);
		}
		printf("\n");
	}
}

void inmang(int m[], int size){
	for(int i=0; i<size; i++){
		printf("%d\t",m[i]);
	}	
}

void readfile_mtk(){
	fp=fopen(MTK,"r");
	if(fp==NULL){
		printf("File not found");
		return;
	}
	fscanf(fp,"%d",&sodinh);
	for(int i=0; i<sodinh; i++){
		for(int j=0; j<sodinh; j++){
			fscanf(fp,"%d",&mtk[i][j]);
		}
	}
	printf("%d\n",sodinh);
	inmt(mtk,sodinh);
	fclose(fp);
}

void readfile_h(){
	fp=fopen(H,"r");
	if(fp==NULL){
		printf("File not found");
		return;
	}
	fscanf(fp,"%d",&sodinh);
	for(int i=0; i<sodinh; i++){
		fscanf(fp,"%d",&h[i]);
	}
	inmang(h,sodinh);
	fclose(fp);
}

void Astar(int start, int goal){
	int OPEN[MAX];//tap dinh con lai
	int CLOSE[MAX];//tap dinh da xet
	int OPENED[MAX];//tap dinh ke da duoc xet
	int g[MAX];//tap chi phi den thoi diem hien tai
	int f[MAX];//chi phi tong the
	int CHA[MAX];//cac nut cha
	
	//khoi tao cac gia tri
	for(int i=0; i<sodinh; i++){
		CLOSE[i]=i;
		OPENED[i]=i;
		g[i]=0;
		f[i]=0;
		CHA[i]=-1;
	}
	int dem=0;//so luong cac dinh con lai
	OPEN[dem++]=start; //dem=1, OPEN[0]=start
	g[start]=0;
	f[start]=h[start];
	
	while(dem>=0){//con dinh trong OPEN thi con xet
		int n=OPEN[--dem];//lan dau tien thi n=start va dem=0
		printf("\nDinh dang xet: %d",n);
		CLOSE[n]=-1;
		OPENED[n]=-1;
		
		if(n==goal){
			printf("\nTim thay duong di tu %d -> %d", start, goal);
			printf("\nCHA[]: ");inmang(CHA,sodinh);
			int duongdi[MAX];
			int len=0;
			for(int i=goal; i!=-1; i=CHA[i]){
				duongdi[len++]=i;
			}
			printf("\n");
			for(int i=len-1; i>=0;i--){
				printf("%d ->",duongdi[i]);
			}
			return;
		}
		//nguoc lai, xet cac dinh ke cua n
		for(int i=0; i<sodinh; i++){
			if(mtk[n][i]!=0){
				//i thuoc ve OPENED va OPEN
				if(OPENED[i]==-1 && OPEN[i]==OPENED[i]){
					printf("\n%d thuoc ve CLOSE",i);
					int tam_g=g[n]+mtk[n][i];
					int tam_f=tam_g+h[i];
					printf("\ng[%d]=%d, f[%d]=%d",i,tam_g,i,tam_f);
					if(f[i]>tam_f){
						//cap nhat lai gia tri cua g,f
						g[i]=tam_g;
						f[i]=tam_f;
					}
				}
				else{
					//i thuoc ve CLOSE va OPENED
					if(OPENED[i]==-1 && CLOSE[i]==-1 && (OPENED[i]==CLOSE[i])){
						printf("\n%d thuoc ve CLOSE",i);
						int tam_g=g[n]+mtk[n][i];
						int tam_f=tam_g+h[i];
						printf("\ng[%d]=%d, f[%d]=%d",i,tam_g,i,tam_f);
						if(f[i]>tam_f){
							//cap nhat lai gia tri cua g,f
							g[i]=tam_g;
							f[i]=tam_f;
						}
					}
					else{
						//khong co dinh nao thuoc OPEN va CLOSE
						g[i]=g[n]+mtk[n][i];
						f[i]=g[i]+h[i];
						OPENED[i]=-1;
						OPEN[dem++]=i;
					 	CHA[i]=n;
						printf("\ng[%d]=%d, f[%d]=%d",i,g[i],i,f[i]);
					}
				}		
			}
		}
		
		//in ra cac gia tri
		printf("\nOPEN[] : ");inmang(OPEN,dem);
		printf("\nCLOSE[]: ");inmang(CLOSE,sodinh);
		printf("\nOPEND[]: ");inmang(OPENED,sodinh);
		printf("\nh[]: ");inmang(h,sodinh);
		printf("\ng[]: ");inmang(g,sodinh);
		printf("\nf[]: ");inmang(f,sodinh);
		//sap xep OPEN theo thu tu giam dan = lay cuoi danh sach OPEN
		for(int i=0; i<dem-1; i++){
			for(int j=i+1; j<dem; j++){
				if(f[OPEN[i]] < f[OPEN[j]]){
					int tam=OPEN[i];
					OPEN[i]=OPEN[j];
					OPEN[j]=tam;
				}
			}
		}
		printf("\nOPEN[sort] : ");inmang(OPEN,dem);
	}
}


//chuong trinh chinh
int main(){
	readfile_mtk();
	printf("\nUoc luong chi phi:\n");
	readfile_h();
	Astar(0,10);
	return 0;
}
