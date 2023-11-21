#include <stdio.h>

int main(){
	int month,year;
	printf("Hay nhap thang va nam: ");
	scanf("%d %d",&month,&year);
	if(month>=1 && month<=12 && year>0){
		if(year%400==0||(year%4==0 && year%100!=0)){
			if(month == 2) printf("29");
			else if(month ==4||month ==6||month==9||month==11) printf("30");
			else printf("31");
		}else{
			if(month == 2) printf("28");
			else if(month ==4||month ==6||month==9||month==11) printf("30");
			else printf("31");	
		}
	}else printf("INVALID");
	return 0;
}
