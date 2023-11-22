#include<stdio.h>
int main(){
	float point;
	do{
		printf("Hay nhap so diem chinh xac: ");
		scanf("%f",&point);
	}while(point<0&&point>10);
	if(point>=9&&point<=10) printf("Xuat sac");
	else if(point>=8&&point<9) printf("Gioi");
	else if(point>=6.5&&point<8) printf("Kha");
	else if(point>=5&&point<6.5) printf("Trung binh");
	else printf("Yeu");
	return 0;
}
