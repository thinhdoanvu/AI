#include<stdio.h>
#include<math.h>
#define maxdinh 3

#define INPUT "Astar.res"
//khai bao bien
FILE *fp;
int S[maxdinh][maxdinh];
int n;//so hang/cot

void readfile(){
	fp=fopen(INPUT,"r");	
	if(fp==NULL){
		printf("File not found");
	}
	else{
		fscanf(fp,"%d",&n);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				fscanf(fp,"%d",&S[i][j]);
			}
		}
	}
	fclose(fp);
}

void inmang(int a[][maxdinh]){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			printf("%3d",a[i][j]);	
		}
		printf("\n");
	}
}

int h(int a1[][maxdinh], int a2[][maxdinh]){
	int distance=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			printf("\n--dis: %d\n",distance);
			distance=distance + abs(a1[i][j] - a2[i][j]);
		}
	}	
	//return distance;
}

int find(int a[][maxdinh]){
	int row = -1;
	int col = -1;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(a[i][j]==0){
				row = i;
				col = j;
				break;
			}
		}
	}
	if(row!= -1 && col!= -1){
		return(row*3+col);//vi tri tinh tu trai qua phai tu tren tinh xuong
	}
	else{
		return -1;
	}
}

void puzzle(){
	int g=0;
	int row = (find(S)/3);
	int col = (find(S)%3);
	printf("\nVi tri so 0 trong S: (%d,%d)",row,col);
}

int main(){
	printf("Puzzle khoi tao: \n");
	readfile();
	inmang(S);
	printf("\nPuzzle ket qua: \n");
	int E[3][3]={{1,2,3},{4,5,6},{7,8,0}};
	inmang(E);
	//tim vi tri cua so 0
	puzzle();
	//tinh khoang cach cua manhattan
	printf("\nKhoang cach manhattan: %d",h(S,E));
	return 0;
}
