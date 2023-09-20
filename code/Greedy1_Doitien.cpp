#include<stdio.h>
#define INPUT "doitien_1.input"
//khai bao bien
FILE *fp;

void readfile(int a[], int &m, int &n){
	fp=fopen(INPUT,"r");
	if(fp==NULL){
		printf("File not found");
	}
	//else
	fscanf(fp,"%d",&m);
	printf("%d  ",m);
	fscanf(fp,"%d",&n);
	printf("%d\n",n);
	for(int i=0;i<n;i++){
		fscanf(fp,"%d",&a[i]);
	}
	//in noi dung file
	for(int i=0;i<n;i++){
		printf("%d  ",a[i]);
	}
	fclose(fp);
}

//doi tien voi Greedy1
void Greedy1(int a[], int m, int n){
	printf("\nm = %d, n = %d\n",m,n);
	int flash[n];
	flash[n]={0};//khoi tao mang so 0 (chua dung menh gia cua to nay de doi)
	int soto=0;
	for(int i=0;i<n;i++){
		if(m>=a[i]){
			m=m-a[i];//doi to dau tien - het so to menh gia co trong day
			soto++;//tang so to len 1 de in ra so to tien can doi la bao nhieu to
			flash[i]=1;//luu lai to nao da duoc doi thi gan 1 (chua doi duoc thi van la 0)
		}
	}
	if(m>0){//chua doi het so tien
		printf("\nKhong doi duoc so tien mong muon");
	}
	else{//in ra so to, to menh gia nao
		printf("\nSo to doi duoc la: %d\n",soto);
		for(int i=0;i<n;i++){
			if(flash[i]==1){
				printf("%d ",a[i]);
			}
		}
	}
}
//chuong trinh chinh
int main(){
	int a[100];
	int m;//so tien
	int n;//so to
	readfile(a,m,n);
	Greedy1(a,m,n);
	return 0;
}

