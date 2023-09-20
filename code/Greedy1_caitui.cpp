#include<stdio.h>
#define INPUT "caitui1.input"
//khai bao bien
FILE *fp;
int W[100];
int V[100];
float CS[100];//Value/Weight
int n;
int Pmax;
//giai thuat uu tien vat co gia tri nhat va kich thuoc nho vao truoc
void readfile(){
	fp=fopen(INPUT,"r");
	if(fp==NULL) printf("File not found");
	//doc gia tri n = so do vat
	fscanf(fp,"%d",&n);
	fscanf(fp,"%d",&Pmax);
	int tam[n];
	for(int i=0; i<2*n; i++){
		fscanf(fp,"%d",&tam[i]);
	}
	int dem=0;
	for(int i=0; i<2*n; i=i+2){
		W[dem]=tam[i];
		V[dem]=tam[i+1];
		dem++;
	}
	//in ra gia tri cac mang
	printf("\nKhoi luong cac do vat: ");
	for(int i=0; i<n; i++){
		printf("%d ",W[i]);
	}
	printf("\nGia tri cac do vat: ");
	for(int i=0; i<n; i++){
		printf("%d ",V[i]);
	}
	//mang CS
	for(int i=0; i<n; i++){
		CS[i]=(float)V[i]/W[i];
	}
	printf("\nDanh sach cac V/W: ");
	for(int i=0; i<n; i++){
		printf("%.1f ",CS[i]);
	}
	fclose(fp);
}

void sort(){
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(CS[i]<CS[j]){
				float tam=CS[i];
				CS[i]=CS[j];
				CS[j]=tam;
				
				int t = W[i];
				W[i]=W[j];
				W[j]=t;
				
				t = V[i];
				V[i]=V[j];
				V[j]=t;
			}
		}
	}
}

void Greedy2(){
	sort();
	printf("\nCS[]: ");
	for(int i=0; i<n; i++){
		printf("%.1f ",CS[i]);
	}
	printf("\nW[]: ");
	for(int i=0; i<n; i++){
		printf("%d  ",W[i]);
	}
	printf("\nV[]: ");
	for(int i=0; i<n; i++){
		printf("%d  ",V[i]);
	}
	//thuc hien thao tac con lai giong bai toan doi tien
	//tinh trong luong con lai = Pmax - W[i]
	int flash[n];
	flash[n]={0};
	int Maxvalue=0;
	for(int i=0; i<n; i++){
		if(Pmax>=W[i]){
			Pmax=Pmax-W[i];
			//luu lai vet da duyet qua
			flash[i]=1;
			Maxvalue+=V[i];
		}
	}
	//in ra danh sach cac W[i], V[i]
	printf("\nMax value: %d\n",Maxvalue);
	for(int i=0; i<n; i++){
		if(flash[i]==1){
			printf("%d\t|",W[i]);
		}
	}
	printf("\n");
	for(int i=0; i<n; i++){
		if(flash[i]==1){
			printf("%d\t|",V[i]);
		}
	}
}

//chuong trinh chinh
int main(){
	readfile();
	Greedy2();
	
	return 0;
}

