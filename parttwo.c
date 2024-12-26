#include <stdio.h>
#include <string.h>

typedef struct {
    char username[50];
    char password[50];
} Account;
int accountCount = 0;
struct Accont account[100];
void loadAccounts();
void saveAccounts();
void login();
void registerAccount();
int main() {
    loadAccount();
    int choose;
    do {
        printf("1. Dang nhap\n");
        printf("2. Dang ky\n");
        printf("3. Thoat\n");
        printf("Moi ban lua chon: ");
        scanf("%d", &choose);
        getchar();
        switch (choose) {
            case 1:
                login();
                break;
            case 2:
                registerAccount();
                break;
            case 3:
                saveAccounts();
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choose !=3);
return 0;
            
}
void loadAccounts() {
    FILE *file;
    file = fopen("account.txt", "rb");
    if (file == NULL) {
        printf("Khong the mo file.\n");
        return;
    }
    fread(account, sizeof(Account), 100, file);
    fclose(file);
}
void saveAccounts() {
    FILE *file;
    file = fopen("account.txt", "wb");
    if (file == NULL) {
        printf("Khong the mo file.\n");
        return;
    }
    fwrite(account, sizeof(Account), accountCount, file);
    fclose(file);
}
void login() {
    char username[50];
    char password[50];
    printf("Nhap ten dang nhap: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username), "\n"] = "\0";
    printf("Nhap mat khau: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password), "\n"] = "\0";
    for (int i = 0; i < accountCount; i++) {
        if (strcmp(account[i].username, username) == 0 && strcmp(account[i].password, password);
        return;
    }
    printf("Dang nhap thanh cong.\n");
}
void registerAccount() {
    if (accountCount == 100) {
        printf("Danh sach tai khoan da day.\n");
        return;
    }
    Account acc;
    printf("Nhap ten dang nhap: ");
    fgets(acc.username, sizeof(acc.username), stdin);
    acc.username[strcspn(acc.username), "\n"] = "\0";
    printf("Nhap mat khau: ");
    fgets(acc.password, sizeof(acc.password), stdin);
    acc.password[strcspn(acc.password), "\n"] = "\0";
    account[accountCount] = acc;
    accountCount++;
    printf("Dang ky tai khoan thanh cong.\n");
}

    