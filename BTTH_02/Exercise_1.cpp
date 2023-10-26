#include <stdio.h>

int main(){
	int a , b; // khai báo biến 
	scanf("%d %d",&a ,&b); // input biến 
	int Nature = a/b; // chia lấy nguyên 
	int residual = a%b; // chia lấy dư 
	printf("%d %d",Nature,residual); // output giá trị 
	return 0;
}
