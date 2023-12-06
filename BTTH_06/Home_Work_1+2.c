#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Student {
    char id[10];
    char name[50];
    float gpa;
};
void inputStudent(struct Student *students) {
    getchar();
    printf("Nhap ma sinh vien: ");
    fgets(students->id, 10, stdin);
    strtok(students->id, "\n");
    printf("Nhap ten sinh vien: ");
    fgets(students->name, 50, stdin);
    strtok(students->name, "\n");
    printf("Nhap diem trung binh: ");
    scanf("%f", &(students->gpa));
}
void printStudent(const struct Student *student) {
    printf("Ma sinh vien: %s\n", student->id);
    printf("Ten sinh vien: %s\n", student->name);
    printf("Diem trung binh: %.2f\n", student->gpa);
}


int findStudent(const struct Student *students, int size, const char *searchId) {
	int i;
    for (i = 0; i < size; i++) {
        if (strcmp(students[i].id, searchId) == 0) {
            return i;
        }
    }
    return -1; 
}
int main() {
    printf("CHUONG TRINH QUAN LY SINH VIEN\n");
    int n,i;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    struct Student *students = (struct Student *)malloc(n * sizeof(struct Student));
    if (students == NULL) {
        printf("Loi cap phat bo nho.\n");
        return 1;
    }
    int choice;
    do {
        printf("\nMenu chuc nang:\n");
        printf("1. Nhap thong tin sinh vien\n");
        printf("2. In danh sach sinh vien\n");
        printf("3. Tim kiem sinh vien\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                for (i = 0; i < n; i++) {
                    printf("\nNhap thong tin cho sinh vien thu %d:\n", i + 1);
                    inputStudent(&students[i]);
                }
                break;
            case 2:
                printf("\nDanh sach sinh vien:\n");
                for (i = 0; i < n; i++) {
                    printf("\nThong tin sinh vien thu %d:\n", i + 1);
                    printStudent(&students[i]);
                }
                break;
            case 3:
                char searchId[10];
                printf("\nNhap ma so sinh vien can tim kiem: ");
                scanf("%s", searchId);
                int foundIndex = findStudent(students, n, searchId);

                if (foundIndex != -1) {
                    printf("\nTim thay sinh vien co ma so %s:\n", searchId);
                    printStudent(&students[foundIndex]);
                } else {
                    printf("\nKhong tim thay sinh vien co ma so %s.\n", searchId);
                }
                break;
            case 0:
                printf("Tam biet!\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 0);
    free(students);
    return 0;
}

