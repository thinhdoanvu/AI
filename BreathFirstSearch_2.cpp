#include<stdio.h>
#define INPUT "BFS3.txt"
#define MAX 20 //so dinh toi da cua do thi

//khai bao bien
int sodinh;
int mtk[MAX][MAX];
FILE *fp;

void inmatran(int mt[][MAX], int size){
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			printf("%d  ",mt[i][j]);
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
		//doc so dinh cua do thi
		fscanf(fp,"%d",&sodinh);
		printf("So dinh cua do thi: %d",sodinh);
		//doc mtk cua do thi
		for(int i=0; i<sodinh; i++){
			for(int j=0; j<sodinh; j++){
				fscanf(fp,"%d",&mtk[i][j]);
			}
		}
		//in ra mtk cua do thi
		printf("\nMTK:\n");
		inmatran(mtk,sodinh);
		fclose(fp);
	}
}

void init(int mang[], int size, int value){//khoi tao gia tri cho mang
	for(int i=0; i<size; i++){
		mang[i]=value;
	}
}

void inmang(int mang[], int size){
	for(int i=0; i<size; i++){
		printf("%d  ",mang[i]);
	}
}

void BreathFirstSearch(int start, int goal){
	int OPEN[MAX];//tap cac dinh can duyet
	int CLOSE[MAX];//tap cac dinh da xet
	int n;//dinh dang xet
	int dem=0;//so luong dinh con lai trong OPEN
	int Tn[MAX];//tap cac dinh tiem nang (ke voi dinh dang xet)
	int CHA[MAX];//cha cua cac dinh dang xet
	
	OPEN[dem]=start;
	init(CLOSE,sodinh,0);//CLOSE[0 0 0 0 0 0]
	init(Tn,sodinh,0);//Tn[0 0 0 0 0 0]
	init(CHA,sodinh,-1);//CHA[-1 -1 -1 -1 -1 -1]
	
	while(dem>=0){
		n=OPEN[0];//luon luon lay phan tu o dau danh sach OPEN
		CLOSE[n]=-1;//gan dinh da xet = -1
		
		printf("\nDinh dang xet: %d",n);
		//xoa phan tu ra khoi danh sach
		for(int i=0; i<dem; i++){//dem = so luong phan tu cua OPEN
			OPEN[i]=OPEN[i+1];
		}
		if(n==goal){
			printf("\nTim thay duong di tu %d den %d: ",start, goal);
			//in ra lo trinh duong di tu start den goal
			int duongdi[MAX];
			int len=0;//so phan tu cua duongdi[]
			//luu cha cua cac dinh vao duong di
			for(int i=goal; i!=-1; i=CHA[i]){
				duongdi[len++]=i;
			}
			printf("\nduongdi: ");
			inmang(duongdi,len);
			//in duong di
			printf("\nLo trinh tu start = %d den goal = %d: ", start,goal);
			for(int i=len-1; i>=0; i--){
				printf("%d ->  ",duongdi[i]);
			}
			return;
		}
		else{
			//dua cac dinh lan can cua n vao cuoi OPEN
			for(int j=0; j<sodinh;j++){
				if(mtk[n][j]==1 && CLOSE[j]!=-1 && Tn[j]!=-1){
					OPEN[dem++]=j;//j = dinh ke cua n
					Tn[j]=-1;//dinh da duoc dua vao OPEN
					CHA[j]=n;//cha cua dinh tiem nang = n
				}
			}
		}
		printf("\nOPEN: ");
		inmang(OPEN,dem);
		printf("\nCLOSE: ");
		inmang(CLOSE,sodinh);
		printf("\nTn: ");
		inmang(Tn,sodinh);
		printf("\nCHA: ");
		inmang(CHA,sodinh);
		dem--;
	}
}

//chuong trinh chinh
int main(){
	readfile();
	BreathFirstSearch(0,6);
	return 0;
}

