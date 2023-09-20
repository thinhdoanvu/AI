//ver_2. h duoc tinh dua vao tong so o khac dich
//ver_1. Tong gia tri sai khac cua cac o
#include<stdio.h>
#include<math.h>
#define maxdinh 3

#define INPUT "puzzle.inp"
//khai bao bien
FILE *fp;
int S[maxdinh][maxdinh];
int E[3][3]={{1,2,3},{8,0,4},{7,6,5}};
int n;//so hang/cot
int g=0;
int rowvet = maxdinh;
int colvet = maxdinh;
int vet[maxdinh][maxdinh];

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

void inmang(int a[][maxdinh], int row, int col){
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			printf("%3d",a[i][j]);	
		}
		printf("\n");
	}
}

int h(int src[][maxdinh], int des[][maxdinh]){
	int distance=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(src[i][j]!=des[i][j]){
				distance++;
			}
		}
	}	
	return distance;
}

int find(int a[][maxdinh]){//find zero
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

void duplicate(int src[][maxdinh], int des[][maxdinh]){
	for(int i=0; i<maxdinh; i++){
		for(int j=0; j<maxdinh; j++){
			des[i][j]=src[i][j];
		}
	}
}

int equal(int src[][maxdinh], int des[][maxdinh]){
	for(int i=0; i<maxdinh; i++){
		for(int j=0; j<maxdinh; j++){
			if(src[i][j] != des[i][j]){
				return 0;
			}
		}
	}
	return 1;
}

void insert(int src[][maxdinh]) {
     // Noi ma tran src vao tiep theo ma tran vet
   for (int i = 0; i < maxdinh; i++) {
        for (int j = 0; j < maxdinh; j++) {
            vet[rowvet + i][j] = src[i][j];
        }
    }
    rowvet = rowvet+maxdinh;
    colvet = maxdinh;
}


int search(int des[][maxdinh]){
    for (int i = 0; i <= rowvet - maxdinh; i++) {
        int found = 1;
        for (int j = 0; j < maxdinh; j++) {
            for (int k = 0; k < maxdinh; k++) {
                if (vet[i+j][k] != des[j][k]) {
                    found = 0;
                    break;
                }
            }
            if (!found) {
                break;
            }
        }
        if (found) {
            return found;
        }
    }
    return 0;
}

void puzzle(int S[][maxdinh], int E[][maxdinh]){
	if(equal(S,E)==1){
		printf("\nbai toan da duoc giai");
		return;
	}

	int row = (find(S)/3);
	int col = (find(S)%3);
	//printf("\nVi tri so 0 trong S: (row = %d, col = %d)",row,col);
	
	//cac truong hop chuyen doi ma tran tu ma tran ban dau
	//---------------------------- hang 0 cot 0 -------------------//
	if(col==0 && row ==0){//hang 0, cot 0
		int T1[maxdinh][maxdinh];//xuong duoi
		int T2[maxdinh][maxdinh];//sang phai
		
		//dich chuyen xuong duoi
		duplicate(S,T1);
		swap(T1[row][col],T1[row+1][col]);
		//printf("\nPuzzle H1: \n");
		//inmang(T1,n,n);
		int h1 = g+h(T1,E);//tinh khoang cach T1 - End
		//kiem tra T1 co trong ma tran vet khong, neu co thi gan h1 = gia tri vo cung lon
		if(search(T1)==1){
			h1=9999;
		}
		printf("h1 = %d",h1);
		
		//dich chuyen sang phai
		duplicate(S,T2);
		swap(T2[row][col],T2[row][col+1]);
		//printf("\nPuzzle H2: \n");
		//inmang(T2,n,n);
		int h2 = h(T2,E);//tinh khoang cach T2 - End
		//kiem tra T2 co trong ma tran vet khong, neu co thi gan h2 = gia tri vo cung lon
		if(search(T2)==1){
			h2=9999;
		}
		printf(", h2 = %d",h2);
		
		//tim hmin
		if(h1 < h2){
			duplicate(T1,S);//S=T1
			//noi ma tran S vao vet
			insert(S); 
		}
		else{
			duplicate(T2,S);//S=T2
			//noi ma tran S vao vet
			insert(S);
		}
		printf("\nS new: \n");
		inmang(S,n,n);
		//printf("\nvet new: \n");
		//inmang(vet,rowvet,colvet);
		
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
		//inmang(T1,n,n);
		int h1 = h(T1,E);//tinh khoang cach T1 - End
		//kiem tra T1 co trong ma tran vet khong, neu co thi gan h2 = gia tri vo cung lon
		if(search(T1)==1){
			h1=9999;
		}
		printf("h1 = %d",h1);
		
		//dich chuyen sang phai
		duplicate(S,T2);
		swap(T2[row][col],T2[row][col+1]);
		//printf("\nPuzzle H2: \n");
		//inmang(T2,n,n);
		int h2 = h(T2,E);//tinh khoang cach T2 - End
		//kiem tra T2 co trong ma tran vet khong, neu co thi gan h2 = gia tri vo cung lon
		if(search(T2)==1){
			h2=9999;
		}
		printf(", h2 = %d",h2);
		
		//dich chuyen sang trai
		duplicate(S,T3);
		swap(T3[row][col],T3[row][col-1]);
		//printf("\nPuzzle H3: \n");
		//inmang(T3,n,n);
		int h3 = h(T3,E);//tinh khoang cach T3 - End
		//kiem tra T3co trong ma tran vet khong, neu co thi gan h2 = gia tri vo cung lon
		if(search(T3)==1){
			h3=9999;
		}
		printf("h3 = %d",h3);
		
		//tim min
		int min=h1;
		if(min > h2){
			min = h2;
		}
		if(min > h3){
			min = h3;
		}
		
		if(min == h1){
			duplicate(T1,S);//S=T1
			//noi ma tran S vao vet
			insert(S);
		} 
		else{
			if(min == h2){
				duplicate(T2,S);//S=T2
				//noi ma tran S vao vet
				insert(S);
			} 
			else{
				if(min == h3){
					duplicate(T3,S);//S=T3
					//noi ma tran S vao vet
					insert(S);
				} 
			}
		}
				
		printf("\nS new: \n");
		inmang(S,n,n);
		//printf("\nvet new: \n");
		//inmang(vet,rowvet,colvet);
		
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
		//inmang(T1,n,n);
		int h1 = h(T1,E);//tinh khoang cach T1 - End
		//kiem tra T1 co trong ma tran vet khong, neu co thi gan h2 = gia tri vo cung lon
		if(search(T1)==1){
			h1=9999;
		}
		printf("h1 = %d",h1);
		
		//dich chuyen sang trai
		duplicate(S,T2);
		swap(T2[row][col],T2[row][col-1]);
		//printf("\nPuzzle H2: \n");
		///inmang(T2,n,n);
		int h2 = h(T2,E);//tinh khoang cach T2 - End
		//kiem tra T2 co trong ma tran vet khong, neu co thi gan h2 = gia tri vo cung lon
		if(search(T2)==1){
			h2=9999;
		}
		printf("h2 = %d",h2);
		
		//tim hmin
		if(h1 < h2){
			duplicate(T1,S);//S=T1
			//noi ma tran S vao vet
			insert(S);
		}
		else{
			duplicate(T2,S);//S=T2
			//noi ma tran S vao vet
			insert(S);
		}
		printf("\nS new: \n");
		inmang(S,n,n);
		//printf("\nvet new: \n");
		//inmang(vet,rowvet,colvet);
		
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
		//inmang(T1,n,n);
		int h1 = h(T1,E);//tinh khoang cach T1 - End
		//kiem tra T1 co trong ma tran vet khong, neu co thi gan h2 = gia tri vo cung lon
		if(search(T1)==1){
			h1=9999;
		}
		printf("h1 = %d",h1);
		
		//dich chuyen sang phai
		duplicate(S,T2);
		swap(T2[row][col],T2[row][col+1]);
		//printf("\nPuzzle H2: \n");
		//inmang(T2,n,n);
		int h2 = h(T2,E);//tinh khoang cach T2 - End
		//kiem tra T2 co trong ma tran vet khong, neu co thi gan h2 = gia tri vo cung lon
		if(search(T2)==1){
			h2=9999;
		}
		printf("h2 = %d",h2);
		
		//dich chuyen len tren
		duplicate(S,T3);
		swap(T3[row][col],T3[row-1][col]);
		//printf("\nPuzzle H3: \n");
		///inmang(T3,n,n);
		int h3 = h(T3,E);//tinh khoang cach T3 - End
		//kiem tra T3 co trong ma tran vet khong, neu co thi gan h2 = gia tri vo cung lon
		if(search(T3)==1){
			h3=9999;
		}
		printf("h3 = %d",h3);
		
		//tim min
		int min=h1;
		if(min > h2){
			min = h2;
		}
		if(min > h3){
			min = h3;
		}
		
		if(min == h1){
			duplicate(T1,S);//S=T1
			//noi ma tran S vao vet
			insert(S);
		}
		else{
			if(min == h2){
				duplicate(T2,S);//S=T2
				//noi ma tran S vao vet
				insert(S);
			} 
			else{
				if(min == h3){
					duplicate(T3,S);//S=T3
					//noi ma tran S vao vet
					insert(S);
				} 
			}
		}
		printf("\nS new: \n");
		inmang(S,n,n);
		//printf("\nvet new: \n");
		//inmang(vet,rowvet,colvet);
		
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
		//inmang(T1,n,n);
		int h1 = h(T1,E);//tinh khoang cach T1 - End
		//kiem tra T1 co trong ma tran vet khong, neu co thi gan h2 = gia tri vo cung lon
		if(search(T1)==1){
			h1=9999;
		}
		printf("h1 = %d",h1);
		
		//dich chuyen sang phai
		duplicate(S,T2);
		swap(T2[row][col],T2[row][col+1]);
		//printf("\nPuzzle H2: \n");
		//inmang(T2,n,n);
		int h2 = h(T2,E);//tinh khoang cach T2 - End
		//kiem tra T2 co trong ma tran vet khong, neu co thi gan h2 = gia tri vo cung lon
		if(search(T2)==1){
			h2=9999;
		}
		printf("h2 = %d",h2);
		
		//dich chuyen len tren
		duplicate(S,T3);
		swap(T3[row][col],T3[row-1][col]);
		//printf("\nPuzzle H3: \n");
		//inmang(T3,n,n);
		int h3 = h(T3,E);//tinh khoang cach T3 - End
		//kiem tra T2 co trong ma tran vet khong, neu co thi gan h2 = gia tri vo cung lon
		if(search(T3)==1){
			h3=9999;
		}
		printf("h3 = %d",h3);
		
		//dich chuyen sang trai
		duplicate(S,T4);
		swap(T4[row][col],T4[row][col-1]);
		//printf("\nPuzzle H4: \n");
		//inmang(T4,n,n);
		int h4 = h(T4,E);//tinh khoang cach T2 - End
		//kiem tra T4 co trong ma tran vet khong, neu co thi gan h2 = gia tri vo cung lon
		if(search(T4)==1){
			h4=9999;
		}
		printf("h4 = %d",h4);
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
		if(min == h1){
			duplicate(T1,S);//S=T1
			//noi ma tran S vao vet
			insert(S);
		}
		else{
			if(min == h2){
				duplicate(T2,S);//S=T2
				//noi ma tran S vao vet
				insert(S);
			} 
			else{
				if(min == h3) {
					duplicate(T3,S);//S=T3
					//noi ma tran S vao vet
					insert(S);
				}
				else{
					if(min == h4){
						duplicate(T4,S);//S=T3
						//noi ma tran S vao vet
//						insert(S);
						//thay the ma tran S cho ma tran vet
						 
					} 
				}
			}
		}
		
		printf("\nS new: \n");
		inmang(S,n,n);
		//printf("\nvet new: \n");
		//inmang(vet,rowvet,colvet);
		
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
		//inmang(T1,n,n);
		int h1 = h(T1,E);//tinh khoang cach T1 - End
		//kiem tra T1 co trong ma tran vet khong, neu co thi gan h2 = gia tri vo cung lon
		if(search(T1)==1){
			h1=9999;
		}
		printf("h1 = %d",h1);
		
		//dich chuyen sang trai
		duplicate(S,T2);
		swap(T2[row][col],T2[row][col-1]);
		//printf("\nPuzzle H2: \n");
		//inmang(T2,n,n);
		int h2 = h(T2,E);//tinh khoang cach T2 - End
		//kiem tra T2 co trong ma tran vet khong, neu co thi gan h2 = gia tri vo cung lon
		if(search(T2)==1){
			h2=9999;
		}
		printf("h2 = %d",h2);
		
		//dich chuyen len tren
		duplicate(S,T3);
		swap(T3[row][col],T3[row-1][col]);
		//printf("\nPuzzle H3: \n");
		//inmang(T3,n,n);
		int h3 = h(T3,E);//tinh khoang cach T3 - End
		//kiem tra T3 co trong ma tran vet khong, neu co thi gan h2 = gia tri vo cung lon
		if(search(T3)==1){
			h3=9999;
		}
		printf("h3 = %d",h3);
		
		//tim min
		int min=h1;
		if(min > h2){
			min = h2;
		}
		if(min > h3){
			min = h3;
		}
		
		if(min == h1){
			duplicate(T1,S);//S=T1
			//noi ma tran S vao vet
			insert(S);
		}
		else{
			if(min == h2){
				duplicate(T2,S);//S=T2
				//noi ma tran S vao vet
				insert(S);
			} 
			else{
				if(min == h3){
					duplicate(T3,S);//S=T3
					//noi ma tran S vao vet
					insert(S);
				}
			}
		}	 

		printf("\nS new: \n");
		inmang(S,n,n);
		//printf("\nvet new: \n");
		//inmang(vet,rowvet,colvet);
		
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
		//inmang(T1,n,n);
		int h1 = h(T1,E);//tinh khoang cach T1 - End
		//kiem tra T1 co trong ma tran vet khong, neu co thi gan h2 = gia tri vo cung lon
		if(search(T1)==1){
			h1=9999;
		}
		printf("h1 = %d",h1);
		
		//dich chuyen sang phai
		duplicate(S,T2);
		swap(T2[row][col],T2[row][col+1]);
		//printf("\nPuzzle H2: \n");
		//inmang(T2,n,n);
		int h2 = h(T2,E);//tinh khoang cach T2 - End
		//kiem tra T2 co trong ma tran vet khong, neu co thi gan h2 = gia tri vo cung lon
		if(search(T2)==1){
			h2=9999;
		}
		printf("h2 = %d",h2);
		
		//tim hmin
		if(h1 < h2){
			duplicate(T1,S);//S=T1	
			//noi ma tran S vao vet
			insert(S);
		}
		else{
			duplicate(T2,S);//S=T2
			//noi ma tran S vao vet
			insert(S);
		}
		
		printf("\nS new: \n");
		inmang(S,n,n);
		//printf("\nvet new: \n");
		//inmang(vet,rowvet,colvet);
		
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
		//inmang(T1,n,n);
		int h1 = h(T1,E);//tinh khoang cach T1 - End
		//kiem tra T1 co trong ma tran vet khong, neu co thi gan h2 = gia tri vo cung lon
		if(search(T1)==1){
			h1=9999;
		}
		printf("h1 = %d",h1);
		
		//dich chuyen sang trai
		duplicate(S,T2);
		swap(T2[row][col],T2[row][col-1]);
		//printf("\nPuzzle H2: \n");
		//inmang(T2,n,n);
		int h2 = h(T2,E);//tinh khoang cach T2 - End
		//kiem tra T2 co trong ma tran vet khong, neu co thi gan h2 = gia tri vo cung lon
		if(search(T2)==1){
			h2=9999;
		}
		printf("h2 = %d",h2);
		
		//dich chuyen len tren
		duplicate(S,T3);
		swap(T3[row][col],T3[row-1][col]);
		//printf("\nPuzzle H3: \n");
		//inmang(T3,n,n);
		int h3 = h(T3,E);//tinh khoang cach T3 - End
		//kiem tra T3 co trong ma tran vet khong, neu co thi gan h2 = gia tri vo cung lon
		if(search(T3)==1){
			h3=9999;
		}
		printf("h3 = %d",h3);
		
		//tim min
		int min=h1;
		if(min > h2){
			min = h2;
		}
		if(min > h3){
			min = h3;
		}
		
		if(min == h1){
			duplicate(T1,S);//S=T1
			//noi ma tran S vao vet
			insert(S);
		} 
		else{
			if(min == h2){
				duplicate(T2,S);//S=T2
				//noi ma tran S vao vet
//				insert(S);
			} 
			else{
				if(min == h3){
					duplicate(T3,S);//S=T3
					//noi ma tran S vao vet
					insert(S);
				}
			}
		}
		
		printf("\nS new: \n");
		inmang(S,n,n);
		//printf("\nvet new: \n");
		//inmang(vet,rowvet,colvet);
		
		//return;
	}
	//---------------------------- hang 2 cot 2 -------------------//
	if(col==2 && row ==2){//hang 2, cot 2
		int T1[maxdinh][maxdinh];//len tren
		int T2[maxdinh][maxdinh];//sang trai
		
		//dich chuyen len tren
		duplicate(S,T1);
		swap(T1[row][col],T1[row-1][col]);
		//printf("\nPuzzle H1: \n");
		//inmang(T1,n,n);
		int h1 = h(T1,E);//tinh khoang cach T1 - End
		//kiem tra T1 co trong ma tran vet khong, neu co thi gan h2 = gia tri vo cung lon
		if(search(T1)==1){
			h1=9999;
		}
		printf("h1 = %d",h1);
		
		//dich chuyen sang trai
		duplicate(S,T2);
		swap(T2[row][col],T2[row][col-1]);
		//printf("\nPuzzle H2: \n");
		//inmang(T2,n,n);
		int h2 = h(T2,E);//tinh khoang cach T2 - End
		//kiem tra T2 co trong ma tran vet khong, neu co thi gan h2 = gia tri vo cung lon
		if(search(T2)==1){
			h2=9999;
		}
		printf("h2 = %d",h2);
		
		//tim hmin
		if(h1 < h2){
			duplicate(T1,S);//S=T1	
			//noi ma tran S vao vet
			insert(S);
		}
		else{
			duplicate(T2,S);//S=T2
			//noi ma tran S vao vet
			insert(S);
		}
		
		printf("\nS new: \n");
		inmang(S,n,n);
		//printf("\nvet new: \n");
		//inmang(vet,rowvet,colvet);
		
		//return;
	}
	puzzle(S,E);
}

int main(){
	
	printf("Puzzle khoi tao: \n");
	readfile();
	inmang(S,3,3);
	//printf("\nPuzzle ket qua: \n");
	//inmang(E);
	// cap phat dong vung nho cho mang vet
    int **arr = new int *[rowvet];
    for (int i = 0; i < rowvet; i++) {
        arr[i] = new int[colvet];
    }
	//dua ma tran S vao ma tran luu vet
	duplicate(S,vet);
	printf("vet khoi tao: \n");
	inmang(vet,rowvet,colvet);
	puzzle(S,E);
	
	return 0;
}
