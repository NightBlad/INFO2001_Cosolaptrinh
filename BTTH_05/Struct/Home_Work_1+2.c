#include <stdio.h>
#include <string.h>
struct Student {
    char id[10];
    char Class[50];
    char name[50];
    int age;
    float gpa;
};
int setQuantity() {
    int maxStudent;
    printf("Hay nhap so luong sinh vien: ");
    scanf("%d", &maxStudent);
    return maxStudent;
}
void initStudents(struct Student students[], int size) {
    for (int i = 0; i < size; i++) {
    	printf("Nhap thong tin sinh vien thu %d\n",i+1);
        printf("Nhap id sinh vien: ");
        getchar();
        fgets(students[i].id,10,stdin);
        printf("Nhap lop sinh vien: ");
        fgets(students[i].Class,50,stdin);
        printf("Nhap ten sinh vien: ");
        fgets(students[i].name,50,stdin);
        printf("Nhap tuoi sinh vien: ");
        scanf("%d",&students[i].age);
        printf("Nhap diem sinh vien: ");
        scanf("%f",&students[i].gpa);
    }
}
void printStudents(struct Student students[], int size) {
    for (int i = 0; i < size; i++) {
        printf("\nThong tin sinh vien thu %d\n", i + 1);
        printf("\nMa so sinh vien la: %s", students[i].id);
        printf("Lop sinh vien la: %s", students[i].Class);
        printf("Ten sinh vien la: %s", students[i].name);
        printf("Tuoi sinh vien la: %d\n", students[i].age);
        printf("Diem sinh vien la: %.2f\n", students[i].gpa);
    }
}
void updateStudentInfo(struct Student students[], int size, char searchId[]) {
    for (int i = 0; i < size; i++) {
        if (strcmp(students[i].id, searchId) == 0) {
            printf("Nhap thong tin moi cho sinh vien co ma so %s\n", searchId);
            getchar();
        	printf("Nhap id sinh vien: ");
        	fgets(students[i].id,10,stdin);
        	printf("Nhap lop sinh vien: ");
        	fgets(students[i].Class,50,stdin);
        	printf("Nhap ten sinh vien: ");
        	fgets(students[i].name,50,stdin);
        	printf("Nhap tuoi sinh vien: ");
        	scanf("%d",&students[i].age);
        	printf("Nhap diem sinh vien: ");
        	scanf("%f",&students[i].gpa);
            return;
        }
    }
    printf("Khong tim thay sinh vien co ma so %s.\n", searchId);
}
void sortStudents(struct Student students[], int size, char sortBy[]) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if ((strcmp(sortBy, "name") == 0 && strcmp(students[j].name, students[j + 1].name) > 0) ||
                (strcmp(sortBy, "gpa") == 0 && students[j].gpa < students[j + 1].gpa)) {
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    printf("Danh sach sinh vien da duoc sap xep theo %s.\n", sortBy);
}
void searchStudent(struct Student students[], int size, char search[]) {
    printf("Ket qua tim kiem:\n");
    int found = 0;  
    for (int i = 0; i < size; i++) {
        if (strstr(students[i].name, search) != NULL || strstr(students[i].id, search) != NULL) {
            found = 1;  
            printf("\nThong tin sinh vien thu %d", i + 1);
            printf("\nMa so sinh vien la: %s", students[i].id);
            printf("Lop sinh vien la: %s", students[i].Class);
            printf("Ten sinh vien la: %s", students[i].name);
            printf("Tuoi sinh vien la: %d\n", students[i].age);
            printf("Diem sinh vien la: %.2f\n", students[i].gpa);
        }
    }
    if (found==0) {
        printf("Khong tim thay sinh vien co ten hoac ma so tren %s.\n", search);
    }
}
int main() {
    printf("CHUONG TRINH QUAN LY SINH VIEN\n");
    int size = setQuantity();
    struct Student students[size];
    initStudents(students, size);
    // Menu chức năng
    int choice;
    do {
        printf("\n|||Ban muon lam gi tiep theo|||\n");
        printf("1. In danh sach sinh vien\n");
        printf("2. Cap nhat thong tin sinh vien\n");
        printf("3. Sap xep danh sach sinh vien\n");
        printf("4. Tim kiem sinh vien\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printStudents(students, size);
                break;
            case 2:
            {
                char searchId[10];
                printf("Nhap ma so sinh vien can cap nhat: ");
                getchar();
                fgets(searchId,10,stdin);
                updateStudentInfo(students, size, searchId);
                break;
            }
            case 3:
            {
                char sortBy[10];
                printf("Nhap tieu chi sap xep (name hoac gpa): ");
                scanf("%s",&sortBy);
                sortStudents(students, size, sortBy);
                break;
            }
            case 4:
            {
                char search[50];
                printf("Nhap ten hoac id can tim kiem: ");
                // getchar();
                // fgets(search,50,stdin);
                scanf("%s",&search);
                searchStudent(students, size, search);
                break;
            }
            case 0:
                printf("Tam biet!\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 0);
    return 0;
}
