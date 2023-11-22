#include<stdio.h>
int main(){
	int n,sum=0,i=1;
	do{
	printf("Hay nhap N so le can tinh tong: ");
	scanf("%d",&n);
	}
	while(n<0);
	do{
		sum +=i;
		i+=2;
		n-=1;
	}while(n>0);
	printf("Tong N cac so le dau tien: %d",sum);
	return 0;
}
