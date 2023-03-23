#include<stdio.h>
#include<math.h>
#define maxdinh 3

#define INPUT "Astar.inp"
//khai bao bien
FILE *fp;
int S[maxdinh][maxdinh];
int E[3][3]={{1,2,3},{4,5,6},{7,8,0}};
int n;//so hang/cot
int g=0;

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
			distance+= abs(a1[i][j] - a2[i][j]);
		}
	}	
	return distance;
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

void swap(int &x, int &y){
	int tam=x;
	x=y;
	y=tam;
}

void duplicate(int a[][maxdinh], int b[][maxdinh]){
	for(int i=0; i<maxdinh; i++){
		for(int j=0; j<maxdinh; j++){
			b[i][j]=a[i][j];
		}
	}
}

int equal(int a[][maxdinh], int b[][maxdinh]){
	for(int i=0; i<maxdinh; i++){
		for(int j=0; j<maxdinh; j++){
			if(a[i][j] != b[i][j]){
				return 0;
			}
		}
	}
	return 1;
}

void puzzle(int S[][maxdinh], int E[][maxdinh], int g){
	if(equal(S,E)==1){
		printf("\nbai toan da duoc giai");
		return;
	}

	int row = (find(S)/3);
	int col = (find(S)%3);
	printf("\nVi tri so 0 trong S: (row = %d, col = %d)",row,col);
	
	//cac truong hop chuyen doi ma tran tu ma tran ban dau
	//---------------------------- hang 0 cot 0 -------------------//
	if(col==0 && row ==0){//hang 0, cot 0
		int T1[maxdinh][maxdinh];//xuong duoi
		int T2[maxdinh][maxdinh];//sang phai
		
		//dich chuyen xuong duoi
		duplicate(S,T1);
		swap(T1[row][col],T1[row+1][col]);
		//printf("\nPuzzle H1: \n");
		//inmang(T1);
		int h1 = g+h(T1,E);//tinh khoang cach T1 - End
		//printf("h1 = %d",h1);
		
		//dich chuyen sang phai
		duplicate(S,T2);
		swap(T2[row][col],T2[row][col+1]);
		//printf("\nPuzzle H2: \n");
		//inmang(T2);
		int h2 = g+h(T2,E);//tinh khoang cach T2 - End
		//printf("h2 = %d",h2);
		
		//tim hmin
		if(h1 < h2){
			duplicate(T1,S);//S=T1	
		}
		else{
			duplicate(T2,S);//S=T2
		}
		printf("\nPuzzle new: \n");
		inmang(S);
		
		//return;
	}
	//---------------------------- hang 0 cot 1 -------------------//
	if(col==1 && row ==0){//hang 0, cot 1
		int T1[maxdinh][maxdinh];//duoi
		int T2[maxdinh][maxdinh];//trai
		int T3[maxdinh][maxdinh];//phai
		//dich chuyen xuong duoi
			
		duplicate(S,T1);
		swap(T1[row][col],T1[row+1][col]);
		//printf("\nPuzzle H1: \n");
		//inmang(T1);
		int h1 = g+h(T1,E);//tinh khoang cach T1 - End
		//printf("h1 = %d",h1);
		
		//dich chuyen sang phai
		duplicate(S,T2);
		swap(T2[row][col],T2[row][col+1]);
		//printf("\nPuzzle H2: \n");
		//inmang(T2);
		int h2 = g+h(T2,E);//tinh khoang cach T2 - End
		//printf("h2 = %d",h2);
		
		//dich chuyen sang trai
		duplicate(S,T3);
		swap(T3[row][col],T3[row][col-1]);
		//printf("\nPuzzle H3: \n");
		//inmang(T3);
		int h3 = g+h(T3,E);//tinh khoang cach T3 - End
		//printf("h3 = %d",h3);
		
		//tim min
		int min=h1;
		if(min > h2){
			min = h2;
		}
		if(min > h3){
			min = h3;
		}
		
		if(min == h1) duplicate(T1,S);//S=T1
		if(min == h2) duplicate(T2,S);//S=T2
		if(min == h3) duplicate(T3,S);//S=T3

		printf("\nPuzzle new: \n");
		inmang(S);
		
		//return;
	}
	
	//---------------------------- hang 0 cot 2 -------------------//
	if(col==2 && row ==0){//hang 0, cot 2
		int T1[maxdinh][maxdinh];//duoi
		int T2[maxdinh][maxdinh];//trai		
		//dich chuyen xuong duoi
		duplicate(S,T1);
		swap(T1[row][col],T1[row+1][col]);
		//printf("\nPuzzle H1: \n");
		//inmang(T1);
		int h1 = g+h(T1,E);//tinh khoang cach T1 - End
		//printf("h1 = %d",h1);
		
		//dich chuyen sang trai
		duplicate(S,T2);
		swap(T2[row][col],T2[row][col-1]);
		//printf("\nPuzzle H2: \n");
		//inmang(T2);
		int h2 = g+h(T2,E);//tinh khoang cach T2 - End
		//printf("h2 = %d",h2);
		
		//tim hmin
		if(h1 < h2){
			duplicate(T1,S);//S=T1	
		}
		else{
			duplicate(T2,S);//S=T2
		}
		printf("\nPuzzle new: \n");
		inmang(S);
		
		//return;
	}
	//---------------------------- hang 1 cot 0 -------------------//
	if(col==0 && row ==1){//hang 1, cot 0
		int T1[maxdinh][maxdinh];//duoi
		int T2[maxdinh][maxdinh];//phai
		int T3[maxdinh][maxdinh];//tren
		//dich chuyen xuong duoi
		duplicate(S,T1);
		swap(T1[row][col],T1[row+1][col]);
		//printf("\nPuzzle H1: \n");
		//inmang(T1);
		int h1 = g+h(T1,E);//tinh khoang cach T1 - End
		//printf("h1 = %d",h1);
		
		//dich chuyen sang phai
		duplicate(S,T2);
		swap(T2[row][col],T2[row][col+1]);
		//printf("\nPuzzle H2: \n");
		//inmang(T2);
		int h2 = g+h(T2,E);//tinh khoang cach T2 - End
		//printf("h2 = %d",h2);
		
		//dich chuyen len tren
		duplicate(S,T3);
		swap(T3[row][col],T3[row-1][col]);
		//printf("\nPuzzle H3: \n");
		//inmang(T3);
		int h3 = g+h(T3,E);//tinh khoang cach T3 - End
		//printf("h3 = %d",h3);
		
		//tim min
		int min=h1;
		if(min > h2){
			min = h2;
		}
		if(min > h3){
			min = h3;
		}
		
		if(min == h1) duplicate(T1,S);//S=T1
		if(min == h2) duplicate(T2,S);//S=T2
		if(min == h3) duplicate(T3,S);//S=T3

		printf("\nPuzzle new: \n");
		inmang(S);
		
		//return;
	}
	//---------------------------- hang 1 cot 1 -------------------//
	if(col==1 && row ==1){//hang 1, cot 1
		int T1[maxdinh][maxdinh];//duoi
		int T2[maxdinh][maxdinh];//phai
		int T3[maxdinh][maxdinh];//tren
		int T4[maxdinh][maxdinh];//trai
		//dich chuyen xuong duoi
		duplicate(S,T1);
		swap(T1[row][col],T1[row+1][col]);
		//printf("\nPuzzle H1: \n");
		//inmang(T1);
		int h1 = g+h(T1,E);//tinh khoang cach T1 - End
		//printf("h1 = %d",h1);
		
		//dich chuyen sang phai
		duplicate(S,T2);
		swap(T2[row][col],T2[row][col+1]);
		//printf("\nPuzzle H2: \n");
		//inmang(T2);
		int h2 = g+h(T2,E);//tinh khoang cach T2 - End
		//printf("h2 = %d",h2);
		
		//dich chuyen len tren
		duplicate(S,T3);
		swap(T3[row][col],T3[row-1][col]);
		//printf("\nPuzzle H3: \n");
		//inmang(T3);
		int h3 = g+h(T3,E);//tinh khoang cach T3 - End
		//printf("h3 = %d",h3);
		
		//dich chuyen sang trai
		duplicate(S,T4);
		swap(T4[row][col],T4[row][col-1]);
		//printf("\nPuzzle H4: \n");
		//inmang(T4);
		int h4 = g+h(T4,E);//tinh khoang cach T2 - End
		//printf("h4 = %d",h4);
		//tim min
		int min=h1;
		if(min > h2){
			min = h2;
		}
		if(min > h3){
			min = h3;
		}
		if(min > h4){
			min = h4;
		}
		if(min == h1) duplicate(T1,S);//S=T1
		if(min == h2) duplicate(T2,S);//S=T2
		if(min == h3) duplicate(T3,S);//S=T3
		if(min == h4) duplicate(T4,S);//S=T3
		printf("\nPuzzle new: \n");
		inmang(S);
		
		//return;
	}
	//---------------------------- hang 1 cot 2 -------------------//
	if(col==2 && row ==1){//hang 1, cot 2
		int T1[maxdinh][maxdinh];//duoi
		int T2[maxdinh][maxdinh];//trai	
		int T3[maxdinh][maxdinh];//tren	
		//dich chuyen xuong duoi
		duplicate(S,T1);
		swap(T1[row][col],T1[row+1][col]);
		//printf("\nPuzzle H1: \n");
		//inmang(T1);
		int h1 = g+h(T1,E);//tinh khoang cach T1 - End
		//printf("h1 = %d",h1);
		
		//dich chuyen sang trai
		duplicate(S,T2);
		swap(T2[row][col],T2[row][col-1]);
		//printf("\nPuzzle H2: \n");
		//inmang(T2);
		int h2 = g+h(T2,E);//tinh khoang cach T2 - End
		//printf("h2 = %d",h2);
		
		//dich chuyen len tren
		duplicate(S,T3);
		swap(T3[row][col],T3[row-1][col]);
		//printf("\nPuzzle H3: \n");
		//inmang(T3);
		int h3 = g+h(T3,E);//tinh khoang cach T3 - End
		//printf("h3 = %d",h3);
		
		//tim min
		int min=h1;
		if(min > h2){
			min = h2;
		}
		if(min > h3){
			min = h3;
		}
		
		if(min == h1) duplicate(T1,S);//S=T1
		if(min == h2) duplicate(T2,S);//S=T2
		if(min == h3) duplicate(T3,S);//S=T3

		printf("\nPuzzle new: \n");
		inmang(S);
		
		//return;
	}
	//---------------------------- hang 2 cot 0 -------------------//
	if(col==0 && row ==2){//hang 2, cot 0
		int T1[maxdinh][maxdinh];//len tren
		int T2[maxdinh][maxdinh];//sang phai
		
		//dich chuyen len tren
		duplicate(S,T1);
		swap(T1[row][col],T1[row-1][col]);
		//printf("\nPuzzle H1: \n");
		//inmang(T1);
		int h1 = g+h(T1,E);//tinh khoang cach T1 - End
		//printf("h1 = %d",h1);
		
		//dich chuyen sang phai
		duplicate(S,T2);
		swap(T2[row][col],T2[row][col+1]);
		//printf("\nPuzzle H2: \n");
		//inmang(T2);
		int h2 = g+h(T2,E);//tinh khoang cach T2 - End
		//printf("h2 = %d",h2);
		
		//tim hmin
		if(h1 < h2){
			duplicate(T1,S);//S=T1	
		}
		else{
			duplicate(T2,S);//S=T2
		}
		printf("\nPuzzle new: \n");
		inmang(S);
		
		//return;
	}
	//---------------------------- hang 2 cot 1 -------------------//
	if(col==1 && row ==2){//hang 1, cot 2
		int T1[maxdinh][maxdinh];//phai
		int T2[maxdinh][maxdinh];//trai	
		int T3[maxdinh][maxdinh];//tren	
		//dich chuyen sang phai
		duplicate(S,T1);
		swap(T1[row][col],T1[row][col+1]);
		//printf("\nPuzzle H1: \n");
		//inmang(T1);
		int h1 = g+h(T1,E);//tinh khoang cach T1 - End
		//printf("h1 = %d",h1);
		
		//dich chuyen sang trai
		duplicate(S,T2);
		swap(T2[row][col],T2[row][col-1]);
		//printf("\nPuzzle H2: \n");
		//inmang(T2);
		int h2 = g+h(T2,E);//tinh khoang cach T2 - End
		//printf("h2 = %d",h2);
		
		//dich chuyen len tren
		duplicate(S,T3);
		swap(T3[row][col],T3[row-1][col]);
		//printf("\nPuzzle H3: \n");
		//inmang(T3);
		int h3 = g+h(T3,E);//tinh khoang cach T3 - End
		//printf("h3 = %d",h3);
		
		//tim min
		int min=h1;
		if(min > h2){
			min = h2;
		}
		if(min > h3){
			min = h3;
		}
		
		if(min == h1) duplicate(T1,S);//S=T1
		if(min == h2) duplicate(T2,S);//S=T2
		if(min == h3) duplicate(T3,S);//S=T3

		printf("\nPuzzle new: \n");
		inmang(S);
		
		//return;
	}
	//---------------------------- hang 2 cot 2 -------------------//
	if(col==0 && row ==2){//hang 2, cot 0
		int T1[maxdinh][maxdinh];//len tren
		int T2[maxdinh][maxdinh];//sang trai
		
		//dich chuyen len tren
		duplicate(S,T1);
		swap(T1[row][col],T1[row-1][col]);
		//printf("\nPuzzle H1: \n");
		//inmang(T1);
		int h1 = g+h(T1,E);//tinh khoang cach T1 - End
		//printf("h1 = %d",h1);
		
		//dich chuyen sang trai
		duplicate(S,T2);
		swap(T2[row][col],T2[row][col-1]);
		//printf("\nPuzzle H2: \n");
		//inmang(T2);
		int h2 = g+h(T2,E);//tinh khoang cach T2 - End
		//printf("h2 = %d",h2);
		
		//tim hmin
		if(h1 < h2){
			duplicate(T1,S);//S=T1	
		}
		else{
			duplicate(T2,S);//S=T2
		}
		printf("\nPuzzle new: \n");
		inmang(S);
		
		//return;
	}
	puzzle(S,E,g++);
}

int main(){
	printf("Puzzle khoi tao: \n");
	readfile();
	inmang(S);
	//printf("\nPuzzle ket qua: \n");
	//inmang(E);
	//tim vi tri cua so 0
	puzzle(S,E,g);
	
	return 0;
}
