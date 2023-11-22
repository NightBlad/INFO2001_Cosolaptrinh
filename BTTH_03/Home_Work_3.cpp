#include<stdio.h>
int main(){
	printf("Bang cuu chuong tu 2 den 9\n");
	int j =2,k;
	do{
		int i;
		printf("Bang phep nhan cua %d\n",j);
		for(i=1;i<10;i++){
			k =j*i;
			printf("%d x %d= %d; ",j,i,k);	
		}j++;
		printf("\n");
	}while(j<10);
	return 0;
}
