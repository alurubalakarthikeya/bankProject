#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
struct Customers {
    char cName[20];
    int cAge;
    int cAccountNumber;
    int cBalance;
};
int createNewAccount(struct Customers *c1) {
    FILE *fp;
    long long max = 999999999999;
    long long min = 100000000000;
    
    srand(time(0)); 
    c1->cAccountNumber = (rand() % (max - min + 1)) + min;
    c1->cBalance = 0;
    
    fp = fopen("bank.txt", "ab+");
    if(fp == NULL){
        printf("Error opening file!");
        exit(1);
    }
    
    fwrite(c1, sizeof(struct Customers), 1, fp);
    fclose(fp);
    
    return c1->cAccountNumber;
}
int retrieveCustomer(int accountNumber, struct Customers *c1) {
    FILE *fp;
    fp = fopen("bank.txt", "rb");
    if(fp == NULL) {
        printf("Error opening file!");
        return 0;
    }

    while(fread(c1, sizeof(struct Customers), 1, fp)) {
        if(c1->cAccountNumber == accountNumber) {
            fclose(fp);
            return 1;
        }
    }
    
    fclose(fp);
    return 0; 
}
void updateCustomer(struct Customers *c1) {
    FILE *fp;
    struct Customers temp;
    fp = fopen("bank.txt", "rb+");
    if(fp == NULL) {
        printf("Error opening file!");
        exit(1);
    }

    while(fread(&temp, sizeof(struct Customers), 1, fp)) {
        if(temp.cAccountNumber == c1->cAccountNumber) {
            fseek(fp, -sizeof(struct Customers), SEEK_CUR);
            fwrite(c1, sizeof(struct Customers), 1, fp);
            break;
        }
    }
    
    fclose(fp);
}
int Balance(int accountNumber) {
    struct Customers c1;
    if(retrieveCustomer(accountNumber, &c1)) {
        printf("\nAccount Number: %d\nCurrent balance: %d", c1.cAccountNumber, c1.cBalance);
    } else {
        printf("\nAccount not found!");
    }
    return 0;
}
int Withdraw(int accountNumber) {
    struct Customers c1;
    int amount;
    if(retrieveCustomer(accountNumber, &c1)) {
        printf("\nEnter the amount to withdraw: ");
        scanf("%d", &amount);
        if(c1.cBalance >= amount) {
            c1.cBalance -= amount;
            updateCustomer(&c1);
            printf("\nWithdrawal successful! New balance: %d", c1.cBalance);
        } else {
            printf("\nInsufficient balance!");
        }
    } else {
        printf("\nAccount not found!");
    }
    return 0;
}
int Deposit(int accountNumber) {
    struct Customers c1;
    int amount;
    if(retrieveCustomer(accountNumber, &c1)) {
        printf("\nEnter the amount to deposit: ");
        scanf("%d", &amount);
        c1.cBalance += amount;
        updateCustomer(&c1);
        printf("\nDeposit successful! New balance: %d", c1.cBalance);
    } else {
        printf("\nAccount not found!");
    }
    return 0;
}

int main() {
    int choice, accountNumber;
    struct Customers c1;

    printf("\n********************************");
    printf("\n   WELCOME TO BANK OF BANANA    ");
    printf("\n********************************\n");
    printf("1. Create a new bank account\n");
    printf("2. Deposit money to account\n");
    printf("3. Withdraw money from account\n");
    printf("4. Check account balance\n");
    printf("5. Exit\n");
    printf("********************************\n");
    printf("Enter a number of your choice to continue: ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            printf("Enter your name: ");
            scanf("%s", c1.cName);
            printf("Enter your age: ");
            scanf("%d", &c1.cAge);
            c1.cAccountNumber = createNewAccount(&c1);
            printf("\nAccount created successfully!\n");
            printf("Account Number: %d\nName: %s\n", c1.cAccountNumber, c1.cName);
            break;

        case 2:
            printf("Enter your account number: ");
            scanf("%d", &accountNumber);
            Deposit(accountNumber);
            break;

        case 3:
            printf("Enter your account number: ");
            scanf("%d", &accountNumber);
            Withdraw(accountNumber);
            break;

        case 4:
            printf("Enter your account number: ");
            scanf("%d", &accountNumber);
            Balance(accountNumber);
            break;

        case 5:
            printf("Thank you for banking with us!");
            break;

        default:
            printf("Invalid choice!");
    }

    return 0;
}
