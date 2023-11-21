#include <stdio.h>
int main(){
	int n;
	int countOdd=0;
	int countEven=0;
	do{
	printf("Hay nhap so tu nhien n: ");
	scanf("%d",&n);
	}
	while(n<0);
	while (n > 0) {
        int digit = n % 10; 
        n /= 10; 
        if (digit % 2 == 0) {
            countEven += 1;
        } else {
            countOdd += 1;
        }
    }if(countOdd==countEven) printf("YES");
    else printf("NO");
	return 0;
}
