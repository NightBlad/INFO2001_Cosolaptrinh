#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "Binaryfile.txt"

struct Data {
    int number;
    char text[50];
};

void writeToFile() {
    FILE *file = fopen(FILE_NAME, "wb");
    if (file == NULL) {
        perror("Cannot open file for writing");
        return;
    }

    struct Data data;

    printf("Nhap so nguyen: ");
    scanf("%d", &data.number);

    printf("Nhap chuoi van ban (toi da 49 ky tu): ");
    scanf(" %[^\n]", data.text);

    fwrite(&data, sizeof(struct Data), 1, file);

    fclose(file);

    printf("Du lieu da duoc ghi vao tep tin.\n");
}

void readFromFile() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        perror("Cannot open file for reading");
        return;
    }

    struct Data readData;
    fread(&readData, sizeof(struct Data), 1, file);

    printf("\nDu lieu doc tu tep tin:\n");
    printf("Number: %d\n", readData.number);
    printf("Text: %s\n", readData.text);

    fclose(file);
}

int main() {
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Ghi du lieu vao tep tin\n");
        printf("2. Doc du lieu tu tep tin\n");
        printf("3. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                writeToFile();
                break;
            case 2:
                readFromFile();
                break;
            case 3:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}

