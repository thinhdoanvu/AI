#include<stdio.h>
//#define dinh_input "Astar_graph.inp"
//#define h_input "Astar_graph.h"
#define dinh_input "Astar_graph2.inp"
#define h_input "Astar_graph2.h"
#define maxdinh 20//so dinh toi da

//khai bao bien
int dinh[maxdinh][maxdinh];
int h[maxdinh];
int n;//so dinh
FILE *fp;//con tro tap tin

void readfile(){
	//doc ma tran trong so cua cac dinh
	fp=fopen(dinh_input,"r");
	if(fp==NULL) printf("File not found");
	fscanf(fp,"%d",&n);
	printf("So dinh: %d",n);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			fscanf(fp,"%d",&dinh[i][j]);	
		}
	}
	fclose(fp);//dong tap tin dinh_input

	//gia tri uoc luong heuristic cac dinh tu i - K
	fp=fopen(h_input,"r");
	if(fp==NULL) printf("File not found");
	fscanf(fp,"%d",&n);
	for(int i=0; i<n; i++){
		fscanf(fp,"%d",&h[i]);	
	}
	fclose(fp);//dong tap tin h_input
	
	//in ra ma tran trong so cac dinh
	printf("\nTrong so cua ma tran:\n");
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			printf("%5d",dinh[i][j]);
		}
		printf("\n");
	}
	
	//in ra gia tri cac heuristic
	printf("gia tri uoc luong: \n");
	for(int i=0; i<n; i++){
		printf("%5d",h[i]);
	}
}

void inmang(int a[], int size){
	for(int i=0; i<size; i++){
		printf("%3d",a[i]);
	}
	printf("\n");
}

void khoitao(int a[], int size, int byte){
	for(int i=0; i<size; i++){
		a[i]=byte;
	}
}
void Astar_Search(int start, int goal){
	printf("\nDuong di ngan nhat A(0) den K(11) la:\n");
	int OPEN[maxdinh];
	int CLOSE[maxdinh];
	int g[maxdinh];
	int f[maxdinh];
	int father[maxdinh];
	khoitao(g,n,-1);
	khoitao(f,n,-1);
	khoitao(CLOSE,n,-1);
	khoitao(father,n,-1);
	
	int dem=0;
	int numclose=0;
	g[start] = 0;
	f[start] = h[start];
	
	//OPEN = rong
	//khoi tao dinh dau tien
	int u=start;
	while(u!=goal){
		printf("\nu = %d\n",u);
		if(dem<0){
			printf("\nKhong tim thay duong duong di ngan nhat tu %d den %d",start,goal);
		}
		else{
			CLOSE[numclose]=u;
			father[numclose] = u;//father(v') = u
			numclose++;
			int visited[n];
			khoitao(visited,n,-1);
			for(int i=0; i<n; i++){//duyet qua cac dinh
				if(dinh[u][i]!=0){//2 dinh ke nhau co duong di
					g[i]=g[u]+dinh[u][i];
					f[i]=g[i]+h[i];
					visited[i]=1;
				}
			}
			printf("visited[]: ");
			inmang(visited,n);
			//kiem tra cac dinh trong OPEN co trung voi cac dinh da dua vao tap g[] hoac f[] chua
			for(int i=0; i<n; i++){//v trong visited
				for(int j=0; j<dem; j++){//v' trong OPEN
					if(visited[i]==1 && OPEN[j]==visited[i]){
						if(f[i] < f[j]){//f(v)<f(v')
							g[j] = g[i];//g(v')=g(v)
							f[j] = f[i];//f(v')=f(v)
//							father[j] = u;//father(v') = u
						}
					}
				}
			}
			//kiem tra cac dinh trong CLOSE co trung voi cac dinh da dua vao tap g[] hoac f[] chua
			for(int i=0; i<n; i++){//v trong visited
				for(int j=0; j<numclose; j++){//v' trong CLOSE
					if(visited[i]==1 && CLOSE[j]==visited[i]){
						if(f[i] < f[j]){//f(v)<f(v')
							g[j] = g[i];//g(v')=g(v)
							f[j] = f[i];//f(v')=f(v)
//							father[j] = u;//father(v') = u
						}
					}
				}
			}
			//chen cac dinh v khong thuoc OPEN va CLOSE vao OPEN
			for(int i=0; i<n; i++){
				if(visited[i]==1){
					OPEN[dem++]=i;
				}
			}
			//sap xep OPEN theo thu tu giam dan
			for(int i=0; i<dem-1; i++){
				for(int j=i+1; j<dem; j++){
					if(f[OPEN[i]] < f[OPEN[j]]){
						int tam = OPEN[i];
						OPEN[i] = OPEN[j];
						OPEN[j]=tam;
					}
				}
			}
		}
//		break;
		printf("OPEN[]: ");
		inmang(OPEN,dem);
		printf("g[]:");
		inmang(g,n);
		printf("f[]:");
		inmang(f,n);
		printf("CLOSE[]:");
		inmang(CLOSE,numclose);
		printf("father[]: ");
		inmang(father,numclose);
		//lay dinh u ra khoi OPEN (nam o cuoi)
		u=OPEN[--dem];
	}
	if(u==goal){
		printf("\nTim thay duong di ngan nhat tu %d den %d: ",start,goal);
	}
	//in duong di ngan ngan tu start toi goal
	for(int i=0; i<numclose; i++){
		printf("%d ->",father[i]);
	}
	printf("%d",goal);
	
}

int main(){
	readfile();
//	Astar_Search(0,10);
	Astar_Search(0,12);
	return 0;//exit
}
