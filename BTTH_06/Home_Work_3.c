#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    char title[100];
    char author[50];
    float price;
};

void inputBook(struct Book *book) {
    getchar();
    printf("Nhap ten sach: ");
    fgets(book->title, 100, stdin);
    strtok(book->title, "\n");
    printf("Nhap ten tac gia: ");
    fgets(book->author, 50, stdin);
    strtok(book->author, "\n");
    printf("Nhap gia sach: ");
    scanf("%f", &book->price);
}
void printBook(const struct Book *book) {
    printf("Ten sach: %s\n", book->title);
    printf("Tac gia: %s\n", book->author);
    printf("Gia sach: %.2f vnd\n", book->price);
}

void addBook(struct Book **bookList, int *numBooks) {
    *bookList = (struct Book *)realloc(*bookList, (*numBooks + 1) * sizeof(struct Book));
    if (*bookList == NULL) {
        printf("Loi cap phat bo nho!\n");
        exit(1);
    }
    inputBook(&(*bookList)[*numBooks]);
    (*numBooks)++;
}
void deleteBook(struct Book **bookList, int *numBooks) {
    if (*numBooks == 0) {
        printf("Danh sach sach dang trong.\n");
        return;
    }
    printf("Nhap vi tri sach muon xoa (tu 1 den %d): ", *numBooks);
    int position;
    scanf("%d", &position);
    if (position < 1 || position > *numBooks) {
        printf("Vi tri khong hop le.\n");
        return;
    }
    (*bookList)[position - 1] = (*bookList)[*numBooks - 1];
    *bookList = (struct Book *)realloc(*bookList, (*numBooks - 1) * sizeof(struct Book));
    if (*bookList == NULL && *numBooks > 1) {
        printf("Loi cap phat bo nho!\n");
        exit(1);
    }
    (*numBooks)--;
}

int main() {
    printf("CHUONG TRINH QUAN LY THU VIEN\n");
    int i,numBooks = 0;
    printf("Nhap so luong sach: ");
    scanf("%d", &numBooks);
    struct Book *bookList = (struct Book *)malloc(numBooks * sizeof(struct Book));
    if (bookList == NULL) {
        printf("Loi cap phat bo nho!\n");
        return 1;
    }
    
    int choice;
    do {
        printf("\n|||Ban muon lam gi tiep theo|||\n");
        printf("1. Nhap thong tin sach\n");
        printf("2. In danh sach sach\n");
        printf("3. Them sach moi\n");
        printf("4. Xoa sach\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Nhap thong tin sach\n");
                for (i = 0; i < numBooks; i++) {
                    printf("\nThong tin sach thu %d:\n",i+1);
                    inputBook(&bookList[i]);
                    printf("\n");
                }
                break;
            case 2:
                printf("In danh sach sach\n");
                for (i = 0; i < numBooks; i++) {
                    printf("\nThong tin sach thu %d:\n",i+1);
                    printBook(&bookList[i]);
                }
                break;
            case 3:
                printf("Them sach moi\n");
                addBook(&bookList, &numBooks);
                break;
            case 4:
                printf("Xoa sach\n");
                deleteBook(&bookList, &numBooks);
                break;
            case 0:
                printf("Thoat\n");
                printf("Tam biet!\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 0);

    free(bookList);
    return 0;
}

