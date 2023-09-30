#include<stdio.h>
#include<limits.h>

#define INPUT "nhanhcan.inp"
#define H "nhanhcan.h"
#define maxdinh 20

int dinh[maxdinh][maxdinh];
int n;
int h[maxdinh];
FILE *fp;

void inmatran(int a[][maxdinh], int n){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			printf("%5d",a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void inmang(int a[], int n){
	for(int i=0; i<n; i++){
		printf("%5d",a[i]);
	}
}

void readfile(){
	fp=fopen(INPUT, "r");	
	if(fp==NULL){
		printf("File not found");
	}
	else{
		fscanf(fp,"%d",&n);
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				fscanf(fp,"%d",&dinh[i][j]);
			}
		}
		fclose(fp);
	}
	//in ra ma tran input
	inmatran(dinh,n);
	
	//Doc file ham luong gia
	fp=fopen(H, "r");	
	if(fp==NULL){
		printf("File not found");
	}
	else{
		for(int i=0; i<n; i++){
			
			fscanf(fp,"%d",&h[i]);
		}
		fclose(fp);
	}
	//in ra ma cac gia tri uoc luong heuristic
	inmang(h,n);
}

void khoitaomang(int a[], int n){
	for(int i=0; i<n; i++){
		a[i]=0;
	}
}

void nhanhcan(int start, int goal){
	int min=INT_MAX;
	int dem=0;
	int u;//dinh hien tai dang xet
	int OPEN[maxdinh];
	int g[n];
	int f[n];
	int father[n];
	khoitaomang(g,n);
	khoitaomang(f,n);
	//Khoi tao
	OPEN[dem++]=start;
	
	while(dem!=0){//Buoc 2.1
		dem--;
		u=OPEN[dem];//Buoc 2.2
		printf("\nu=%d",u);
		printf("\nmin = %d",min);
		printf("\ndem = %d",dem);
		//xet u=goal
		if(u==goal){
			//ktra f(u)<min
			printf("\nf[u] = %d",f[u]);
			if(f[u]<min){
				min=f[u];//cap nhat lai min
			}
		}
		else{//u!=goal tiep tuc
			if(f[u] < min){//f[u] con nho hon min
				int L[n];
				int demL=0;
				for(int i=0; i<n; i++){//duyet qua cac dinh v co connect voi u
					if(dinh[u][i]!=0){//co ket noi
						printf("\nke %d: %d  ",u,i);
						g[i]=g[u]+dinh[u][i];
						f[i]=g[i]+h[i];				
						L[demL++]=i;
					}
				}
				printf("\nL chua sort:");inmang(L,demL);
				//sort L tang dan theo f (nguoc voi thuat toan: chen dau): chen cuoi
				for(int i=0; i<demL-1; i++){
					for(int j=i+1; j<demL; j++){
						if(f[L[i]]>f[L[j]]){
							int tam=L[i];
							L[i]=L[j];
							L[j]=tam;
						}
					}
				}
				//in mang L
				printf("\nL sorted: ");inmang(L,demL);
				//chen L vao cuoi danh sach OPEN
				int cuoi=dem;
				dem=dem+demL;
				for(int i=cuoi; i<dem; i++){
					OPEN[i]=L[--demL];
				}
			}
			else{//fu>min
				//quay lai while
			}
			//in gia tri cua mang
			printf("\ng: ");inmang(g,n);
			printf("\nf: ");inmang(f,n);
			printf("\nOPEN: ");inmang(OPEN,dem);
			//printf("\ndem = %d",dem);break;
		}
		//quay lai buoc 2.1
		//lay u tu cuoi danh sach OPEN
		//<=> tro lai vong lap while
		
		//break;
	}
	//het while: dem=0
	printf("\nKet thuc");
}


int main(){
	readfile();
	nhanhcan(0,7);
	return 0;
}
