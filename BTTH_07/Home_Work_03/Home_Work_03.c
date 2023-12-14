#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "contacts.txt"

struct Contact {
    char name[50];
    char phone[15];
    char email[50];
};

void inputContact(struct Contact *contact) {
    getchar();
    printf("Nhap ten: ");
    fgets(contact->name, 50, stdin);
    strtok(contact->name, "\n");
    printf("Nhap so dien thoai: ");
    fgets(contact->phone, 15, stdin);
    strtok(contact->phone, "\n");
    printf("Nhap email: ");
    fgets(contact->email, 50, stdin);
    strtok(contact->email, "\n");
}

void printContact(const struct Contact *contact) {
    printf("Ten: %s\n", contact->name);
    printf("So dien thoai: %s\n", contact->phone);
    printf("Email: %s\n", contact->email);
}

void writeToFile(struct Contact *contacts, int size) {
    FILE *file = fopen(FILENAME, "wb");
    if (file == NULL) {
        printf("Loi mo file.\n");
        return;
    }

    fwrite(contacts, sizeof(struct Contact), size, file);

    fclose(file);
}

void readFromFile(struct Contact **contacts, int *size) {
    FILE *file = fopen(FILENAME, "rb");
    if (file == NULL) {
        printf("Khong tim thay file. Tep tin se duoc tao moi khi luu.\n");
        *size = 0;
        *contacts = NULL;
        return;
    }

    fseek(file, 0, SEEK_END);
    *size = ftell(file) / sizeof(struct Contact);
    rewind(file);

    *contacts = (struct Contact *)malloc(*size * sizeof(struct Contact));
    if (*contacts == NULL) {
        printf("Loi cap phat bo nho.\n");
        fclose(file);
        return;
    }

    fread(*contacts, sizeof(struct Contact), *size, file);

    fclose(file);

    if (*size > 0) {
        printf("\nDanh sach lien lac trong tep tin:\n"); int i;
        for (i = 0; i < *size; i++) {
            printf("\nThong tin lien lac thu %d:\n", i + 1);
            printContact(&(*contacts)[i]);
        }
    } else {
        printf("\nTep tin khong co du lieu.\n");
    }
}

void addContact(struct Contact **contacts, int *size) {
    int n;
    printf("Nhap so luong lien lac can them: ");
    scanf("%d", &n);

    *contacts = (struct Contact *)realloc(*contacts, (*size + n) * sizeof(struct Contact));
    if (*contacts == NULL) {
        printf("Loi cap phat bo nho.\n");
        return;
    }
	int i;
    for (i = *size; i < *size + n; i++) {
        printf("\nNhap thong tin cho lien lac thu %d:\n", i + 1);
        inputContact(&(*contacts)[i]);
    }

    *size += n;
}

void addNewContact(struct Contact **contacts, int *size) {
    *contacts = (struct Contact *)realloc(*contacts, (*size + 1) * sizeof(struct Contact));
    if (*contacts == NULL) {
        printf("Loi cap phat bo nho.\n");
        return;
    }

    printf("\nNhap thong tin cho lien lac moi:\n");
    inputContact(&(*contacts)[*size]);

    (*size)++;
}

int findContact(const struct Contact *contacts, int size, const char *searchName) {int i;
    for (i = 0; i < size; i++) {
        if (strcmp(contacts[i].name, searchName) == 0) {
            return i;
        }
    }
    return -1;
}

void deleteContact(struct Contact **contacts, int *size, const char *searchName) {
    int foundIndex = findContact(*contacts, *size, searchName);

    if (foundIndex != -1) {int i;
        for (i = foundIndex; i < *size - 1; i++) {
            (*contacts)[i] = (*contacts)[i + 1];
        }

        *contacts = (struct Contact *)realloc(*contacts, (*size - 1) * sizeof(struct Contact));
        if (*contacts == NULL) {
            printf("Loi cap phat bo nho.\n");
            return;
        }

        (*size)--;
        printf("Xoa lien lac thanh cong.\n");
    } else {
        printf("Khong tim thay lien lac co ten %s.\n", searchName);
    }
}

void updateContact(struct Contact *contacts, int size, const char *searchName) {
    int foundIndex = findContact(contacts, size, searchName);

    if (foundIndex != -1) {
        printf("\nNhap thong tin moi cho lien lac co ten %s:\n", searchName);
        inputContact(&contacts[foundIndex]);
        printf("Cap nhat thong tin thanh cong.\n");
    } else {
        printf("\nKhong tim thay lien lac co ten %s.\n", searchName);
    }
}

int main() {
    printf("CHUONG TRINH QUAN LY DANH BA\n");

    struct Contact *contacts = NULL;
    int size = 0;

    int choice;

    do {
        printf("\n||Menu chuc nang:||\n");
        printf("***LUU Y***\n");
        printf("Hay luu khi hoan thanh thong tin khi thuc hien xong\n");
        printf("1. Mo danh sach lien lac tu tep tin (neu co) va in luon\n");
        printf("2. Nhap thong tin lien lac\n");
        printf("3. Them moi mot thong tin lien lac\n");
        printf("4. Xoa lien lac\n");
        printf("5. Tim kiem lien lac\n");
        printf("6. Cap nhat thong tin lien lac\n");
        printf("7. In danh sach lien lac\n");
        printf("8. Luu danh sach lien lac\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                readFromFile(&contacts, &size);
                break;
            case 2:
                addContact(&contacts, &size);
                break;
            case 3:
                addNewContact(&contacts, &size);
                break;
            case 4: {
                char searchName[50];
                printf("\nNhap ten lien lac can xoa: ");
                getchar();
                fgets(searchName, 50, stdin);
                strtok(searchName, "\n");
                deleteContact(&contacts, &size, searchName);
                break;
            }
            case 5: {
                char searchName[50];
                printf("\nNhap ten lien lac can tim kiem: ");
                getchar();
                fgets(searchName, 50, stdin);
                strtok(searchName, "\n");
                int foundIndex = findContact(contacts, size, searchName);

                if (foundIndex != -1) {
                    printf("\nTim thay lien lac co ten %s:\n", searchName);
                    printContact(&contacts[foundIndex]);
                } else {
                    printf("\nKhong tim thay lien lac co ten %s.\n", searchName);
                }
                break;
            }
            case 6: {
                char searchName[50];
                printf("\nNhap ten lien lac can cap nhat: ");
                getchar();
                fgets(searchName, 50, stdin);
                strtok(searchName, "\n");
                updateContact(contacts, size, searchName);
                break;
            }
            case 7:
                if (contacts != NULL) {
                    printf("\nDanh sach lien lac:\n");int i;
                    for (i = 0; i < size; i++) {
                        printf("\nThong tin lien lac thu %d:\n", i + 1);
                        printContact(&contacts[i]);
                    }
                } else {
                    printf("\nDanh sach lien lac trong.\n");
                }
                break;
            case 8:
            	writeToFile(contacts, size);
                printf("Luu thong tin lien lac vao tep tin thanh cong.\n");
            	break;
            case 0:
                printf("Ban co muon luu truoc khi thoat ko?\n");
                printf("YES/NO\n");
                char chon[3];
                scanf("%s", chon);
                if (strcmp(chon, "YES") == 0 || strcmp(chon, "yes") == 0) {
                    writeToFile(contacts, size);
                    printf("Luu thong tin lien lac vao tep tin thanh cong.\n");
                }
                printf("Tam biet!\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 0);

    free(contacts);
    return 0;
}

