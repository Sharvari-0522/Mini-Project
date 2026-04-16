#include <stdio.h>

int main()
{
    printf("\n*********  MINI ATM SYSTEM  *********\n");

    float balance;
    int choice;

    printf("\nEnter Initial Balance: ");
    scanf("%f", &balance);

    /* ---- PIN System ---- */
    int pin = 1234, enteredPin, attempts = 0;

    while (attempts < 3)
    {
        printf("Enter 4-digit PIN: ");
        scanf("%d", &enteredPin);

        if (enteredPin == pin)
        {
            printf("Login Successful!\n");
            break;
        }
        else
        {
            printf("Wrong PIN!\n");
            attempts++;
        }
    }

    if (attempts == 3)
    {
        printf("Too many failed attempts. Account Locked!\n");
        return 0;
    }

    float totalDeposit = 0, totalWithdrawal = 0;
    float deposit, withdraw, transfer;
    int transactionCount = 0;
    float lastTransaction = 0;

    do
    {
        printf("\n----------------------------------\n");
        printf("1. Check Balance\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Transfer Money\n");
        printf("5. Total Deposited\n");
        printf("6. Total Withdrawn\n");
        printf("7. Add 5%% Interest\n");
        printf("8. Last Transaction\n");
        printf("9. Exit\n");
        printf("----------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Current Balance: %.2f\n", balance);
            break;

        case 2:
            printf("Enter amount to deposit: ");
            scanf("%f", &deposit);

            if (deposit > 0)
            {
                balance += deposit;
                totalDeposit += deposit;
                lastTransaction = deposit;
                transactionCount++;
                printf("Deposit Successful!\n");
            }
            else
                printf("Invalid amount!\n");
            break;

        case 3:
            printf("Enter amount to withdraw: ");
            scanf("%f", &withdraw);

            if (withdraw > 0 && withdraw <= balance)
            {
                balance -= withdraw;
                totalWithdrawal += withdraw;
                lastTransaction = -withdraw;
                transactionCount++;
                printf("Withdrawal Successful!\n");
            }
            else
                printf("Invalid or Insufficient Balance!\n");
            break;

        case 4:
            printf("Enter amount to transfer: ");
            scanf("%f", &transfer);

            if (transfer > 0 && transfer <= balance)
            {
                balance -= transfer;
                lastTransaction = -transfer;
                transactionCount++;
                printf("Transfer Successful!\n");
            }
            else
                printf("Invalid or Insufficient Balance!\n");
            break;

        case 5:
            printf("Total Deposited: %.2f\n", totalDeposit);
            break;

        case 6:
            printf("Total Withdrawn: %.2f\n", totalWithdrawal);
            break;

        case 7:
            balance += balance * 0.05;
            printf("5%% Interest Added!\n");
            printf("Updated Balance: %.2f\n", balance);
            break;

        case 8:
            if (transactionCount == 0)
                printf("No transactions yet.\n");
            else{
                printf("Last Transaction Amount: %.2f\n", lastTransaction);
            break;
            }

        case 9:
            printf("\nThank You for Banking With Us!\n");
            break;

        default:
            printf("Invalid Choice! Select 1-9.\n");
        }

    } while (choice != 9);

    printf("\nTotal Transactions Done: %d\n", transactionCount);
    printf("Final Balance: %.2f\n", balance);

    return 0;
}

