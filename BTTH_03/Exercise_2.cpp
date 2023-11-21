#include <stdio.h>

int main(){
	int year;
	printf("Hay nhap nam ma ban muon kiem tra: ");
	scanf("%d",&year);
	if(year<=0) printf("INVALID\n");
	else{
		if(year%400==0||(year%4==0 && year%100!=0)) printf("YES");
		else printf("NO");
	}
	
	return 0;
}
