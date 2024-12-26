#include <stdio.h>
#include <string.h>

struct SinhVien {
    char id[50];
    char name[50];
    int age;
};
struct SinhVien sv[100];
int numberSinhvien = 0;

void loadFileSinhvien();
void printfSinhvien();
void addSinhvien();
void saveFileSinhvien();
void fixSinhvien();
void deleteSinhvien();
void searchSinhvien();
void sortSinhvien();

int main() {
    loadFileSinhvien();
    int choose;
    do {
        printf("1. In danh sach sinh vien:\n");
        printf("2. Them sinh vien:\n");
        printf("3. Sua sinh vien:\n");
        printf("4. Xoa sinh vien:\n");
        printf("5. Tim kiem sinh vien:\n");
        printf("6. Sap xep sinh vien:\n");
        printf("7. Thoat\n");
        printf("Moi nhap lua chon: ");
        scanf("%d", &choose);
        getchar(); // Clear the newline character after scanf

        switch (choose) {
            case 1:
                printfSinhvien();
                break;
            case 2:
                addSinhvien();
                break;
            case 3:
                fixSinhvien();
                break;
            case 4:
                deleteSinhvien();
                break;
            case 5:
                searchSinhvien();
                break;
            case 6:
                sortSinhvien();
                printf("Sap xep thanh cong!\n");
                break;
            case 7:
                saveFileSinhvien();
                printf("Thoat!\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
                break;
        }
    } while (choose != 7);

    return 0;
}

void loadFileSinhvien() {
    FILE *file = fopen("sinhvien.txt", "rb");
    if (file == NULL) {
        printf("Khong the mo file.\n");
        return;
    }
    while (fread(&sv[numberSinhvien], sizeof(struct SinhVien), 1, file)) {
        numberSinhvien++;
    }
    fclose(file);
}

void printfSinhvien() {
    if (numberSinhvien == 0) {
        printf("Danh sach sinh vien rong.\n");
        return;
    }
    for (int i = 0; i < numberSinhvien; i++) {
        printf("Sinh vien thu %d:\n", i + 1);
        printf("Ma sinh vien: %s\n", sv[i].id);
        printf("Ten sinh vien: %s\n", sv[i].name);
        printf("Tuoi sinh vien: %d\n", sv[i].age);
    }
}

void addSinhvien() {
    if (numberSinhvien == 100) {
        printf("Danh sach sinh vien da day.\n");
        return;
    }
    struct SinhVien sv1;
    printf("Nhap ma sinh vien: ");
    fgets(sv1.id, sizeof(sv1.id), stdin);
    sv1.id[strcspn(sv1.id, "\n")] = '\0';
    printf("Nhap ten sinh vien: ");
    fgets(sv1.name, sizeof(sv1.name), stdin);
    sv1.name[strcspn(sv1.name, "\n")] = '\0';
    printf("Nhap tuoi sinh vien: ");
    scanf("%d", &sv1.age);
    getchar(); // Clear newline character

    sv[numberSinhvien] = sv1;
    numberSinhvien++;
    printf("Them sinh vien thanh cong.\n");
}

void saveFileSinhvien() {
    FILE *file = fopen("sinhvien.txt", "wb");
    if (file == NULL) {
        printf("Khong the mo file.\n");
        return;
    }
    fwrite(sv, sizeof(struct SinhVien), numberSinhvien, file);
    fclose(file);
}

void fixSinhvien() {
    char id[50];
    printf("Nhap ma sinh vien can sua: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';

    for (int i = 0; i < numberSinhvien; i++) {
        if (strcmp(sv[i].id, id) == 0) {
            printf("Nhap ten sinh vien moi: ");
            fgets(sv[i].name, sizeof(sv[i].name), stdin);
            sv[i].name[strcspn(sv[i].name, "\n")] = '\0';
            printf("Nhap tuoi sinh vien moi: ");
            scanf("%d", &sv[i].age);
            getchar(); // Clear newline character
            printf("Sua sinh vien thanh cong.\n");
            return;
        }
    }
    printf("Khong tim thay sinh vien voi ma: %s\n", id);
}

void deleteSinhvien() {
    char id[50];
    printf("Nhap ma sinh vien can xoa: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';

    for (int i = 0; i < numberSinhvien; i++) {
        if (strcmp(sv[i].id, id) == 0) {
            for (int j = i; j < numberSinhvien - 1; j++) {
                sv[j] = sv[j + 1];
            }
            numberSinhvien--;
            printf("Xoa sinh vien thanh cong.\n");
            return;
        }
    }
    printf("Khong tim thay sinh vien voi ma: %s\n", id);
}

void searchSinhvien() {
    char id[50];
    printf("Nhap ma sinh vien can tim: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';

    for (int i = 0; i < numberSinhvien; i++) {
        if (strcmp(sv[i].id, id) == 0) {
            printf("Sinh vien thu %d:\n", i + 1);
            printf("Ma sinh vien: %s\n", sv[i].id);
            printf("Ten sinh vien: %s\n", sv[i].name);
            printf("Tuoi sinh vien: %d\n", sv[i].age);
            return;
        }
    }
    printf("Khong tim thay sinh vien voi ma: %s\n", id);
}

void sortSinhvien() {
    for (int i = 0; i < numberSinhvien - 1; i++) {
        for (int j = i + 1; j < numberSinhvien; j++) {
            if (strcmp(sv[i].name, sv[j].name) > 0) {
                struct SinhVien temp = sv[i];
                sv[i] = sv[j];
                sv[j] = temp;
            }
        }
    }
}
