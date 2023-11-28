#include <stdio.h>
#include <string.h>
struct Employee {
    char id[10];
	char name[50];
    char position[50];
    float salary;
};
int setQuantity() {
    int maxEmployee;
    printf("Hay nhap so luong nhan vien: ");
    scanf("%d", &maxEmployee);
    return maxEmployee;
}
void initEmployees(struct Employee employees[], int size) {
    for (int i = 0; i < size; i++) {
    	printf("Nhap thong tin nhan vien thu %d\n",i+1);
        printf("Nhap ma nhan vien: ");
        getchar();
        fgets(employees[i].id,10,stdin);
        printf("Nhap ten nhan vien: ");
        fgets(employees[i].name,50,stdin);
        printf("Nhap chuc vu nhan vien: ");
        fgets(employees[i].position,50,stdin);
        printf("Nhap luong nhan vien: ");
        scanf("%f",&employees[i].salary);
    }
}
void printEmployees(struct Employee employees[], int size) {
    for (int i = 0; i < size; i++) {
        printf("\nThong tin nhan vien thu %d\n", i + 1);
        printf("\nMa so nhan vien la: %s", employees[i].id);
        printf("Ten nhan vien la: %s", employees[i].name);
        printf("Chuc vu nhan vien la: %s", employees[i].position);
        printf("Luong nhan vien la: %.2f dong\n", employees[i].salary);
    }
}
void updateEmployeeInfo(struct Employee employees[], int size, char searchId[]) {
    for (int i = 0; i < size; i++) {
        if (strcmp(employees[i].id, searchId) == 0) {
            printf("Nhap thong tin moi cho nhan vien co ma so %s\n", searchId);
            getchar();
        	printf("Nhap id nhan vien: ");
        	fgets(employees[i].id,10,stdin);
        	printf("Nhap ten nhan vien: ");
        	fgets(employees[i].name,50,stdin);
            printf("Nhap chuc vu nhan vien: ");
            fgets(employees[i].position,50,stdin);
        	printf("Nhap luong nhan vien: ");
        	scanf("%f",&employees[i].salary);
            return;
        }
    }
    printf("Khong tim thay nhan vien co ma so %s.\n", searchId);
}
void sortEmployees(struct Employee employees[], int size, char sortBy[]) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if ((strcmp(sortBy, "name") == 0 && strcmp(employees[j].name, employees[j + 1].name) > 0) ||
                (strcmp(sortBy, "luong") == 0 && employees[j].salary < employees[j + 1].salary)) {
                struct Employee temp = employees[j];
                employees[j] = employees[j + 1];
                employees[j + 1] = temp;
            }
        }
    }
    printf("Danh sach sinh vien da duoc sap xep theo %s.\n", sortBy);
}
void searchEmployee(struct Employee employees[], int size, char search[]) {
    printf("Ket qua tim kiem:\n");
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (strstr(employees[i].name, search) != NULL || strstr(employees[i].id, search) != NULL) {
            found = 1;
            printf("\nThong tin nhan vien thu %d", i + 1);
            printf("\nMa so nhan vien la: %s", employees[i].id);
            printf("Ten nhan vien la: %s", employees[i].name);
            printf("Chuc vu nhan vien la: %s", employees[i].position);
            printf("Luong nhan vien la: %.2f dong\n", employees[i].salary);
        }
    }
    if (found==0) {
        printf("Khong tim thay nhan vien co ten hoac ma so tren %s.\n", search);
    }
}
void addEmployee(struct Employee employees[], int *size) {
    *size += 1;
    printf("Nhap thong tin nhan vien moi\n");
    printf("Nhap ma nhan vien: ");
    getchar();
    fgets(employees[*size].id, 10, stdin);
    printf("Nhap ten nhan vien: ");
    fgets(employees[*size].name, 50, stdin);
    printf("Nhap chuc vu nhan vien: ");
    fgets(employees[*size].position, 50, stdin);
    printf("Nhap luong nhan vien: ");
    scanf("%f", &employees[*size].salary);
    printf("Nhan vien da duoc them vao danh sach.\n");
}

void deleteEmployee(struct Employee employees[], int *size, char searchId[]) {
    int indexToDelete = -1;
    for (int i = 0; i < *size; i++) {
        if (strcmp(employees[i].id, searchId) == 0) {
            indexToDelete = i;
            break;
        }
    }

    if (indexToDelete != -1) {
        for (int i = indexToDelete; i < *size - 1; i++) {
            employees[i] = employees[i + 1];
        }
        *size -= 1;
        printf("Nhan vien co ma so %s da duoc xoa.\n", searchId);
    } else {
        printf("Khong tim thay nhan vien co ma so %s.\n", searchId);
    }
}
int main() {
    printf("CHUONG TRINH QUAN LY NHAN SU\n");
    int size = setQuantity();
    struct Employee employees[size];
    initEmployees(employees, size);
    // Menu
    int choice;
    do {
        printf("\n|||Ban muon lam gi tiep theo|||\n");
        printf("1. In danh sach nhan vien\n");
        printf("2. Cap nhat thong tin nhan vien\n");
        printf("3. Sap xep danh sach nhan vien\n");
        printf("4. Tim kiem nhan vien\n");
        printf("5.Them nhan vien");
        printf("6.Xoa nhan vien");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printEmployees(employees, size);
                break;
            case 2:
            {
                char searchId[10];
                printf("Nhap ma so nhan vien can cap nhat: ");
                getchar();
                fgets(searchId,10,stdin);
                updateEmployeeInfo(employees, size, searchId);
                break;
            }
            case 3:
            {
                char sortBy[10];
                printf("Nhap tieu chi sap xep (name hoac gpa): ");
                scanf("%s",&sortBy);
                sortEmployees(employees, size, sortBy);
                break;
            }
            case 4:
            {
                char search[50];
                printf("Nhap ten hoac id can tim kiem: ");
                // getchar();
                // fgets(search,50,stdin);
                scanf("%s",&search);
                searchEmployee(employees, size, search);
                break;
            }
            case 5:
                addEmployee(employees, &size);
                break;
            case 6:
            {
                char searchId[10];
                printf("Nhap ma so nhan vien can xoa: ");
                getchar();
                fgets(searchId, 10, stdin);
                deleteEmployee(employees, &size, searchId);
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
