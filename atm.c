#include <stdio.h>

int main()
{
    int userInput, pass = 0000, passIN, newpass;
    FILE *pas;
    float bal = 50000;
    printf("\nWelcome to the ATM\n\n");
    printf("Enter your password: ");
    scanf("%d", &passIN);
    pas = fopen("pass.txt", "r");
    fscanf(pas, "%d", &pass);
    if (pass == passIN)
    {
        fclose(pas);
        do
        {
            printf("\nSelect an option from the given menu:\n");
            printf("1: For Withdrawal\n");
            printf("2: For Balance check\n");
            printf("3: Change Password\n");
            printf("0: Exit\n\n");
            scanf("%d", &userInput);

            if (userInput <= 3)
            {
                switch (userInput)

                {
                case 1:
                {
                    float wd, charges, finalAmt;
                    printf("\nEnter the amount you wish to withdraw\n");
                    scanf("%f", &wd);
                    charges = wd * 0.001;
                    finalAmt = wd + charges;

                    if (bal >= finalAmt && bal != 0)
                    {
                        bal -= finalAmt;
                        printf("\n%.2f whithrawn successfully! \n", wd);
                        printf("Charges (0.1 percent): $%.2f\n\n", charges);
                        printf("Balance $%.2f\n\n", bal);
                    }
                    else
                    {
                        printf("\nNot enough Balance. \n");
                        printf("You can withdraw %.2f \n\n", wd - charges);
                    }
                    break;
                }

                case 2:
                {
                    printf("Balance $%.5f\n\n", bal);
                    break;
                }

                case 3:
                {
                    pas = fopen("pass.txt", "w");
                    printf("\nEnter new password: ");
                    scanf("%d", &newpass);
                    fprintf(pas, "%d", newpass);
                    fclose(pas);
                    printf("Password Changed Sussecfully\n");
                    break;
                }

                case 0:
                {
                    printf("\nThankyou for Banking with us\n");
                    break;
                }
                }
            }
            else
            {
                printf("<--Invalid Input-->\n");
                printf("<--Thankyou for banking with us!-->");
            }
        } while (userInput <= 3 && userInput != 0);
    }
    else
    {
        printf("\n<---Invalid Password--->\n<--Transaction Failed-->\nThankyou for Banking with us");
    }

    return 0;
}