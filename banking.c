#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define SIZE 32

typedef enum { deposit, withdraw } balanceOption;
typedef enum { menuAccount = 1, menuWithdraw = 2, menuDeposit = 3, menuLogout = 4} menuOption;
/*
typedef struct {
    int whole, cent;
} currency;
*/
typedef struct {
    char username[SIZE], password[SIZE], pin[8];
    float balance;
    //currency balance = {.whole = 0, .cent = 0};
    } account;

account testAccount;

/*
void printCurrency(currency amount) {
    printf("€%d,%2d", amount.whole, amount.cent);
}

int checkCents(int cents) {
    if (cents < 100 && cents >= 0) { return 0; } else { return 1; }
}
*/

int login() {
    char buffer[SIZE];
    printf("Type in \"(cancel)\" to cancel the login process\n");
    printf("Username: ");
    scanf("%s", buffer);
    if (strcmp(buffer, "(cancel)") == 0) { return 3; }
    if (strcmp(buffer, testAccount.username) == 0) {
        printf("Password: ");
        scanf("%s", buffer);
        if (strcmp(buffer, testAccount.password) == 0) {
            return 0;
        } else {
            printf("Invalid password.\n");
            return 2;
            }
    } else {
        printf("Invalid username.\n");
        return 1;
    }
}

int askPin() {
    char buffer[8];
    printf("PIN: ");
    scanf("%s", buffer);
    if (strcmp(buffer, testAccount.pin) == 0) {
        return 0;
    } else {
        return 1;
    }
}

void setCredentials() {
    printf("\nPlease set the account username: ");
    scanf("%s", testAccount.username);
    printf("\nPlease set your password: ");
    scanf("%s", testAccount.password);
    printf("\nPlease set your PIN: ");
    scanf("%s", testAccount.pin);
    }

void signup() {

}

void setBalance(balanceOption option) {
    float amount;
    printf("amount: ");
    scanf("%f", &amount);
    if (option == deposit) { testAccount.balance += amount; }
    else if (option == withdraw) { testAccount.balance -= amount; }

    //currency amount;
    /*scanf("%d%d", &amount.whole, &amount.cent);
    if (checkCents(amount.cent) == 0) {
        if (option == 0) {
            testAccount.balance.whole += amount.whole;
            testAccount.balance.cent += amount.cent;
        } else if (option == 1) {
            testAccount.balance.whole -= amount.whole;
            testAccount.balance.whole -= amount.whole;
        }
    } else { printf("Invalid cent input.\n"); }*/
}

int selectPrompt() {
        int buffer;
        printf("\n> ");
        scanf("%d", &buffer);
        return buffer;
}

void mainMenu() {
    menuOption menu;
    while (menu != menuLogout) {
        printf("\nWelcome back, %s. Your balance is %.2f EUR", testAccount.username, testAccount.balance);
        printf("\n1. Account Management\n2. Withdraw\n3. Deposit\n4. Logout\n");

        menu = selectPrompt();

        switch (menu) {
            case menuAccount: setCredentials(); break;
            
            case menuWithdraw:
            if (askPin() == 0) { setBalance(withdraw); }
            else { printf("Invalid PIN.\n"); } break;

            case menuDeposit: setBalance(deposit); break;

            case menuLogout: printf("Goodbye, %s.\n", testAccount.username); break;

            default: printf("Invalid option.\n"); break;
        }
    }
}

int frontMenu() {
    int mainState, loginState;
        while (mainState != 3) {
        printf("Welcome to the H+ME CLI banking app!\n(1)login [or (2)register an account], or else (3)exit.\n" );
        switch (selectPrompt()) {
            case 1:
            while ((loginState = login()) != 3) {
                if (loginState == 0) { mainMenu(); }
            }
            break;
            
            case 2: signup(); break;
            case 3: return 1;
        }
    }
}

int main() {
    strcpy(testAccount.username, "user");
    strcpy(testAccount.password, "pass");
    strcpy(testAccount.pin, "0000");
    testAccount.balance = 0;
    //testAccount.balance.whole, testAccount.balance.cent = 0;
    while (frontMenu() != 1) {}
}