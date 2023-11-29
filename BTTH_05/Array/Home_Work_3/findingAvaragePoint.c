#include <stdio.h>
void calculateAvarage(float grade[],int quantity){
    float sum = 0;
    int i = 0;
    for(i=0;i<quantity;i++){
        sum += grade[i];
    }
    float avarage = sum/quantity;
    printf("Diem trung binh cua lop la: %.3f",avarage);
}
int main() {
    printf("CHUONG TRINH TINH DIEM TRUNG BINH\n");
    int i,quantity;
    printf("Lop ban co bao nhieu sinh vien: ");
    scanf("%d",&quantity);
    float grade[quantity];
    for(i=0;i<quantity;i++){
        printf("Nhap diem sinh vien thu %d: ",i+1);
        scanf("%f",&grade[i]);
    }
    calculateAvarage(grade,quantity);
    return 0;
}
