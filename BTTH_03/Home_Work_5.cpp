#include <stdio.h>
#include <math.h>

void isPrime(int number, int *check) {
    *check = 1;
    for (int i = 2; i <= sqrt(number); i++) {
        if (number % i == 0) {
            *check = 0;
        }
    }
}

int main() {
    int number, check = 0;
    do{
        printf("Nhap so nguyen duong > 2: ");
        scanf("%d", &number);
    }while(number<2);
    isPrime(number, &check);

    if (check == 0) printf("Day khong phai la so nguyen to.\n");
    else printf("Day la so nguyen to.\n");
    return 0;
}
