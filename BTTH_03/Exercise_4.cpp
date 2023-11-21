#include<stdio.h>

int main(){
	long int n,sum;
	do{
	printf("Hay nhap so tu nhien n: ");
	scanf("%ld",&n);
	}
	while(n<=0);
	sum = n*(n+1)*(2*n+1)/6;
	printf("Tong cua day 1^2+2^2+...+%ld^2 la: %ld",n,sum);
	return 0;
}
