#include <stdio.h>
void createaccount(double *y, char st[], int *x);
void displayaccountdetails(double x, char st[], int z);
double depositmoney(double x);
double withdrawmoney(double x);
void checkbalance(double x);
void updateaccountdetails(char st[]);
void transactionhistory(void);
double transactions[100];
int transactionType[100];
int transactionCount = 0;
int accountCreated = 0;

int main()
{
    double balance = 0.0;
    double *a = &balance;
    char st[20];
    char *p = st;
    int z = 0;
    int *pt = &z;

    while (1)
    {
        int x;
        printf("1. Create account\n");
        printf("2. Display Account Details\n");
        printf("3. Deposit Money\n");
        printf("4. Withdraw Money\n");
        printf("5. Check balance\n");
        printf("6. Update Account Details\n");
        printf("7. Transaction History\n");
        printf("8. Exit\n");
        printf("Enter Your Choice\n");
        if (scanf("%d", &x) != 1)
        {
            printf("Invalid input. Enter a number.\n");

            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF)
            {
                // Clear invalid input
            }

            continue;
        }
        switch (x)
        {
        case 1:
            if (accountCreated == 1)
            {
                printf("An account has already been created.\n");
            }
            else
            {
                createaccount(a, st, pt);
            }
            break;

            break;
        case 2:
            displayaccountdetails(*a, st, *pt);
            break;
        case 3:
            *a = depositmoney(*a);
            printf("New Balance : %lf\n", *a);
            break;
        case 4:
            *a = withdrawmoney(*a);
            printf("Remaining Balance :%lf\n", *a);
            break;
        case 5:
            checkbalance(*a);
            break;
        case 6:
            updateaccountdetails(st);
            break;
        case 7:
            transactionhistory();
            break;
        case 8:
            printf("Thank you for using our banking system!\n");
            return 0;
        default:
            printf("Invalid input! Please enter a number between 1 and 8.\n");
        }
    }
}
void createaccount(double *y, char st[], int *x)
{
    if (accountCreated == 0)
    {
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF)
        {
            // Consume remaining characters
        }
        printf("PLEASE ENETR THE NAME OF THE ACCOUNT HOLDER");
        fgets(st, 20, stdin);
        printf("PLEASE ENTER YOUR ACCOUNT NUMBER ");
        scanf("%d", x);
        printf("Account created successfully!\n");
        printf("Account Holder name = %s\n", st);
        printf("Account Number = %d\n", *x);
        printf("Account Balance = %lf\n", *y);
        accountCreated = 1;
    }
    else

    {

        printf("An account has already been created.\n");
    }
}

void displayaccountdetails(double x, char st[], int z)
{
    if (accountCreated == 0)
    {
        printf("Please create an account first.\n");
    }
    printf("account holder name %s\n", st);
    printf("account number %d\n", z);
    printf("current balance :%2f\n", x);
}
double depositmoney(double x)
{
    if (accountCreated == 0)
    {
        printf("Please create an account first.\n");
        return x;
    }
    double y;
    printf("Current Balance = %lf\n", x);
    printf("Enter The Amount You Want To Deposit");
    scanf("%lf", &y);
    if (y <= 0)
    {
        printf("deposited amount is invalid\n");
        return x;
    }
    x = x + y;
    printf("Deposited : %lf\n", y);
    printf("Deposit Successful!\n");
    if (transactionCount >= 100)
    {
        printf("Transaction history is full.\n");
    }
    else
    {
        transactions[transactionCount] = y;
        transactionType[transactionCount] = 1;
        transactionCount++;
    }
    return x;
}
double withdrawmoney(double x)
{
    if (accountCreated == 0)
    {
        printf("Please create an account first.\n");
        return x;
    }
    double y;

    printf("Enter the withdrawal amount: ");
    if (scanf("%lf", &y) != 1)
    {
        printf("\nInvalid input. Please enter a number.\n");
        return x;
    }

    if (y <= 0)
    {
        printf("Invalid amount.\n");
        return x;
    }

    if (y > x)
    {
        printf("Insufficient balance.\n");
        return x;
    }

    x = x - y;
    printf("Withdrawal successful!\n");

    return x;
    if (transactionCount >= 100)
    {
        printf("Transaction history is full.\n");
    }
    else
    {
        transactions[transactionCount] = y;
        transactionType[transactionCount] = 2;
        transactionCount++;
    }
    return x;
}
void checkbalance(double x)
{
    if (accountCreated == 0)
    {
        printf("Please create an account first.\n");
    }
    printf("Current Balance :%lf\n", x);
}
void updateaccountdetails(char st[])
{
    if (accountCreated == 0)
    {
        printf("Please create an account first.\n");
    }
    printf("enter the new name\n ");
    scanf("%19[^\n]", st);
    printf("Name changed Successfully!\n");
}
void transactionhistory(void)
{
    if (accountCreated == 0)
    {
        printf("Please create an account first.\n");
    }
    int i;
    if (transactionCount == 0)

    {

        printf("No transactions yet.\n");

        return;
    }
    printf("Transaction History");
    for (i = 0; i < transactionCount; i++)
    {
        if (transactionType[i] == 1)
        {
            printf("deposited :%lf\n", transactions[i]);
        }
        else if (transactionType[i] == 2)
        {
            printf("withdrawn :%lf\n", transactions[i]);
        }
    }
}