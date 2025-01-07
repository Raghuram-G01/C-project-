#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char name[100];
int dip_amt, amt = 1000, acc_no, withdraw_amt, transfer_amt;

void menu();
void record_transaction(const char *operation, int amount);
void deposit_money(), withdraw_money(), transfer_money(), check_balance(), transaction_detail(), last_details();

int main() {
    int choice;
    printf("Enter your name: ");
    fgets(name, 100, stdin);
    name[strlen(name) - 1] = '\0';  // Remove trailing newline
    printf("Enter your account no.: ");
    scanf("%d", &acc_no);

    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                deposit_money();
                break;
            case 2:
                withdraw_money();
                break;
            case 3:
                transfer_money();
                break;
            case 4:
                check_balance();
                break;
            case 5:
                transaction_detail();
                break;
            case 6:
                last_details();
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }
        printf("--------------------------------------------------\n");
    }
    return 0;
}
void menu() {
    printf("\n+------------------- MAIN MENU -------------------+\n");
    printf("| 1. Deposit Money                                |\n");
    printf("| 2. Withdraw Money                               |\n");
    printf("| 3. Transfer Money                               |\n");
    printf("| 4. Check Balance                                |\n");
    printf("| 5. Account statement                            |\n");
    printf("| 6. Exit                                         |\n");
    printf("+-------------------------------------------------+\n");
}

void record_transaction(const char *operation, int amount) {
    FILE *fp = fopen("bank.txt", "a");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }
    time_t tm;
    time(&tm);
    fprintf(fp, "Name: %s | Account No.: %d | Operation: %s | Amount: %d | Balance: %d | Date: %s||6", 
            name, acc_no, operation, amount, amt, ctime(&tm));
    fclose(fp);
}
void deposit_money() {
    printf("\n+---------------- DEPOSIT MONEY ----------------+\n");
    printf("Enter the amount to deposit: ");
    scanf("%d", &dip_amt);
    if (dip_amt <= 0) {
        printf("Invalid amount. Try again.\n");
        return;
    }
    amt += dip_amt;
    printf("Deposited successfully. Current balance: %d\n", amt);
    record_transaction("Deposit", dip_amt);
}
void withdraw_money() {
    printf("\n+---------------- WITHDRAW MONEY ---------------+\n");
    printf("Enter the amount to withdraw: ");
    scanf("%d", &withdraw_amt);
    if (withdraw_amt <= 0 || withdraw_amt > amt) {
        printf("Invalid amount or insufficient balance. Try again.\n");
        return;
    }
    amt -= withdraw_amt;
    printf("Withdrawn successfully. Current balance: %d\n", amt);
    record_transaction("Withdrawal", withdraw_amt);
}
void transfer_money() {
    printf("\n+---------------- TRANSFER MONEY ---------------+\n");
    printf("Enter the amount to transfer: ");
    scanf("%d", &transfer_amt);
    if (transfer_amt <= 0 || transfer_amt > amt) {
        printf("Invalid amount or insufficient balance. Try again.\n");
        return;
    }
    amt -= transfer_amt;
    printf("Transferred successfully. Current balance: %d\n", amt);
    record_transaction("Transfer", transfer_amt);
}

void check_balance() {
    printf("\n+--------------- CHECK BALANCE -----------------+\n");
    printf("Current balance: %d\n", amt);
}

void transaction_detail() {
    printf("\n+------------ TRANSACTION DETAILS --------------+\n");
    FILE *fp = fopen("bank.txt", "r");
    if (fp == NULL) {
        printf("No transaction history found.\n");
        return;
    }
    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
    }
    fclose(fp);
}

void last_details() {
    printf("\n+---------------- THANK YOU --------------------+\n");
    printf("Final balance: %d\nGoodbye, %s!\n", amt, name);
    record_transaction("Exit", 0);
}