#include <stdio.h>
int main(){
	int a,b;
	printf("Nhap hai so a va b:");
	scanf("%d %d",&a,&b);
	int sum = a + b;
	int difference = a - b;
	int product = a *b;
	float quotient = (float)a / b;
	printf("Ket qua la: Tong:%d Hieu:%d Tich:%d Thuong:%.2f",sum,difference,product,quotient); 
	
	return 0;
}
