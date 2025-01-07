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