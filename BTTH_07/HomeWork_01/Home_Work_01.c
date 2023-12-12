#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "studentInfo.txt"

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

void writeToFile(struct Student *students, int size) {
    FILE *file = fopen(FILENAME, "wb");
    if (file == NULL) {
        printf("Loi mo file.\n");
        return;
    }

    fwrite(students, sizeof(struct Student), size, file);

    fclose(file);
}

void readFromFile(struct Student **students, int *size) {
    FILE *file = fopen(FILENAME, "rb");
    if (file == NULL) {
        printf("Khong tim thay file. Tep tin se duoc tao moi khi luu.\n");
        *size = 0;
        *students = NULL;
        return;
    }

    fseek(file, 0, SEEK_END);
    *size = ftell(file) / sizeof(struct Student);
    rewind(file);

    *students = (struct Student *)malloc(*size * sizeof(struct Student));
    if (*students == NULL) {
        printf("Loi cap phat bo nho.\n");
        fclose(file);
        return;
    }

    fread(*students, sizeof(struct Student), *size, file);

    fclose(file);

    if (*size > 0) {
        printf("\nDanh sach sinh vien trong tep tin:\n");
        int i;
        for (i = 0; i < *size; i++) {
            printf("\nThong tin sinh vien thu %d:\n", i + 1);
            printStudent(&(*students)[i]);
        }
    } else {
        printf("\nTep tin khong co du lieu.\n");
    }
}

void appendToFile(struct Student *student) {
    FILE *file = fopen(FILENAME, "ab");
    if (file == NULL) {
        printf("Loi mo file.\n");
        return;
    }

    fwrite(student, sizeof(struct Student), 1, file);

    fclose(file);
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

void updateStudent(struct Student *students, int size, const char *searchId) {
    int foundIndex = findStudent(students, size, searchId);

    if (foundIndex != -1) {
        printf("\nNhap thong tin moi cho sinh vien co ma so %s:\n", searchId);
        inputStudent(&students[foundIndex]);
        printf("Cap nhat thong tin thanh cong.\n");
    } else {
        printf("\nKhong tim thay sinh vien co ma so %s.\n", searchId);
    }
}

void initializeStudentListFromfile(struct Student **students, int *size) {
    readFromFile(students, size);
}

void printStudentList(const struct Student *students, int size) {
    if (size > 0) {
        printf("\nDanh sach sinh vien trong tep tin:\n");
        int i;
        for (i = 0; i < size; i++) {
            printf("\nThong tin sinh vien thu %d:\n", i + 1);
            printStudent(&students[i]);
        }
    } else {
        printf("\nTep tin khong co du lieu.\n");
    }
}

int main() {
    printf("CHUONG TRINH QUAN LY SINH VIEN\n");

    int n;
    struct Student *students = NULL;
    int size = 0;

    int choice;

    do {
        printf("\n||Menu chuc nang:||\n");
        printf("***LUU Y***\n");
        printf("Hay luu khi hoan thanh thong tin khi thuc hien xong\n");
        printf("1. Mo tep thong tin sinh vien(neu co) va in ra danh sach\n");
        printf("2. Nhap thong tin sinh vien\n");
        printf("3. In danh sach sinh vien\n");
        printf("4. Tim kiem sinh vien\n");
        printf("5. Luu thong tin sinh vien vao tep tin\n");
        printf("6. Them sinh vien vao tep tin\n");
        printf("7. Cap nhat thong tin sinh vien\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                initializeStudentListFromfile(&students, &size);
                break;
            case 2:
                printf("Nhap so luong sinh vien: ");
                scanf("%d", &n);
                students = (struct Student *)realloc(students, (size + n) * sizeof(struct Student));
                if (students == NULL) {
                    printf("Loi cap phat bo nho.\n");
                    return 1;
                }int i;
                for (i = size; i < size + n; i++) {
                    printf("\nNhap thong tin cho sinh vien thu %d:\n", i + 1);
                    inputStudent(&students[i]);
                }
                size += n;
                break;
            case 3:
                printStudentList(students, size);
                break;
            case 4: {
                char searchId[10];
                printf("\nNhap ma so sinh vien can tim kiem: ");
                scanf("%s", searchId);
                int foundIndex = findStudent(students, size, searchId);

                if (foundIndex != -1) {
                    printf("\nTim thay sinh vien co ma so %s:\n", searchId);
                    printStudent(&students[foundIndex]);
                } else {
                    printf("\nKhong tim thay sinh vien co ma so %s.\n", searchId);
                }
                break;
            }
            case 5:
                writeToFile(students, size);
                printf("Luu thong tin sinh vien vao tep tin thanh cong.\n");
                break;
            case 6: {
                struct Student newStudent;
                printf("\nNhap thong tin cho sinh vien moi:\n");
                inputStudent(&newStudent);
                appendToFile(&newStudent);
                printf("Them sinh vien vao tep tin thanh cong.\n");
                break;
            }
            case 7: {
                char searchId[10];
                printf("\nNhap ma so sinh vien can cap nhat: ");
                scanf("%s", searchId);
                updateStudent(students, size, searchId);
                break;
            }
            case 0:
                printf("Ban co muon luu truoc khi thoat ko?\n");
                printf("YES/NO\n");
                char chon[3];
                scanf("%s", chon);
                if (strcmp(chon, "YES") == 0||strcmp(chon, "yes") == 0) {
                    writeToFile(students, size);
                    printf("Luu thong tin sinh vien vao tep tin thanh cong.\n");
                }
                printf("Tam biet!\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 0);

    free(students);
    return 0;
}

