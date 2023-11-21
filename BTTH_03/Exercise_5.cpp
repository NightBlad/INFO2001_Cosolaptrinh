#include <stdio.h>
int main(){
	int n;
	int sumOdd=0;
	int sumEven=0;
	do{
	printf("Hay nhap so tu nhien n: ");
	scanf("%d",&n);
	}
	while(n<0);
	while (n > 0) {
        int digit = n % 10; 
        n /= 10; 
        if (digit % 2 == 0) {
            sumEven += digit;
        } else {
            sumOdd += digit;
        }
    }printf("%d %d\n", sumEven, sumOdd);
	return 0;
}
