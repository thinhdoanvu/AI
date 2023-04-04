#include<stdio.h>
#define dinh_input "Astar_graph.inp"
#define h_input "Astar_graph.h"
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

void Astar_Search(int start, int goal){
	printf("\nDuong di ngan nhat A(0) den K(11) la:\n");
	int OPEN[maxdinh];
	int CLOSE[maxdinh];
	int g[maxdinh];
	
}

int main(){
	readfile();
	Astar_Search(0,10);
	return 0;//exit
}
