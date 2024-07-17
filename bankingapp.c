#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// defining the maximum number of users using a compile-time constant
#define userlimit 72

int accnumber[userlimit] = {0}; // array to store account numbers
char names[userlimit][14];      // array to store account holders' name
float balance[userlimit];       // array to store account balances

void addacc();     // Function to add a new account
void displayacc(); // Function to display a account
void deposite();   // Function to deposite money to an account
void withdraw();   // Function to withdraw money from an account

int main(void)

{

    int option;
    do
    {

        // displaying all the options menu
        printf("\n    Banking System Menu    \n");
        printf("\n1. Add Account\n");
        printf("2. Display Account\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("5. Exit\n");
        printf("\nChoose option(1-5): ");
        scanf("%i", &option);

        if (option <= 0 || option > 5)
        {
            printf("\n    Invalid input.\n    Try again!\n");
        }

        else
        {
            switch (option)
            {
            case 1:
                addacc();
                break;

            case 2:
                displayacc();
                break;
            case 3:
                deposite();
                break;
            case 4:
                withdraw();
                break;
            case 5:
                printf("\nExiting...\nThank you!!\n");
                exit(0);

            default:
                break;
            }
        }

    } while (1);

    getch();
}

void addacc()
{
    for (int i = 0; i < userlimit; i++)
    {
        if (accnumber[i] == 0) // checking for an empty position in the accounts array
        {
            printf("\nEnter your account number: ");
            scanf("%i", &accnumber[i]);

            printf("Your name: ");
            scanf("%s", names[i]);

            printf("Initial Balance: ");
            scanf("%f", &balance[i]);

            printf("\nAccount '%i' added successfully!!\n", accnumber[i]);
            break;
        }
    }
}

void displayacc()
{
    int accposition;
    printf("Your account number: ");
    scanf("%i", &accposition);
    for (int i = 0; i < userlimit; i++)
    {
        if (accposition == accnumber[i]) // search for the account by account number
        {
            printf("\n    Account Info    \n");
            printf("Account holder's name: %s\n", names[i]);
            printf("Account number: %i\n", accnumber[i]);
            printf("Total balance: %g\n", balance[i]);
            break;
        }
    }
}

void deposite()
{
    int accposition;
    int depoamt;

    printf("Enter your account number: ");
    scanf("%i", &accposition);

    for (int i = 0; i < userlimit; i++)
    {
        if (accposition == accnumber[i]) // search for the account by account number
        {
            printf("Enter the amount you want to deposite: ");
            scanf("%i", &depoamt);
            balance[i] += depoamt; // adding the deposite money to total balance

            printf("New balance is: %f", balance[i]);
            break;
        }
    }

    printf("\n    Please enter a valid account number!    \n");
}

void withdraw()
{
    int accposition;
    printf("Enter your account number: ");
    scanf("%i", &accposition);
    int withdrawamt;
    printf("Enter the amount you want to withdraw: ");
    scanf("%i", &withdrawamt);
    for (int i = 0; i < userlimit; i++)
    {
        if (accposition == accnumber[i])
        {

            if (withdrawamt > balance[i])
            {
                printf("\n    Insufficient balance!\n    Please try again.    \n");
                break;
            }

            else
            {
                balance[i] -= withdrawamt; // subtracting the withdrawal money from total balance

                printf("New balance is: %f\n", balance[i]);
                break;
            }
        }
    }
}