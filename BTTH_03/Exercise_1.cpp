#include <stdio.h>

int main(){
	int x,remain_3,remain_5;
	do{
		printf("Hay nhap so nguyen theo yeu cau: ");
		scanf("%d",&x);
	}
	while(x>1018||x<-1018);
	remain_3 = x%3;
	remain_5 = x%5;
	if(remain_3 == 0 && remain_5 == 0)printf("1");
	else printf("0");
	return 0;
}
