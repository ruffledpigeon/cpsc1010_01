#include <stdio.h>
#include <math.h>

int main () {
        //user inputs
        int loanAmt, term;
        double monthPay, intRate;

        //formula vars
        int repeat, repeatVal;
        double tenPerc, fifPerc;
        double  monthPmt;


        printf("\n\nCAR LOAN CALCULATOR");
        printf("\n\nWhat is your monthly take-home pay?  ");
        scanf("%lf", &monthPay);

        repeat = 1;
        //loop starts here --

        do {
                //asking le questions
                printf("\nEnter the loan amount:  ");
                scanf("%d", &loanAmt);

                printf("Interest rate:  ");
                scanf("%lf", &intRate);

                printf("Term on loan (number of months):  ");
                scanf("%d", &term);

                //breaking down equation
                upper = intRate / 12;
                lowerPow = 1 - pow((1 + (intRate / 12),(-1 * term));
                monthPmt = loanAmt * (upper / lowerPow);

                //printing output
                printf("\n\nYour monthly payment will be:  %.2lf", monthPmt);

                printf("\nAt the end of the loan, you will have paid $%.2lf", (monthPmt * term) - loanAmt);
                printf(" in interest for a total of $%.2lf", monthPmt * term);

                //Calculate 10% and 15% of user's pay
                tenPerc = monthPay * 0.10;
                fifPerc = monthPay * 0.15;

                //Conditions if car is affordable


                if (monthPmt > fifPerc) {
                        printf("\n\nThe monthly payment is more than 15%% of your monthly income \nand is probably not affordable.");
                }
                else if (monthPmt >= tenPerc && monthPmt <= fifPerc) {
                        printf("\n\nThe monthly payment is between 10-15%% of your monthly income. \nIt might be affordable.");
                }
                else (monthPmt <= tenPerc) {
                        printf("\n\nThe monthly payment is less than 10%% of your monthly income. \nThis is an affordable car.");
                }



                printf("Would you like to try again? 0 for no, 1 for yes:  ");
                scanf("%d", &repeatVal);

                if (1 == repeatVal || 0 == repeatVal) {
                        if (1 == repeatVal) {
                                repeat = 1;
                        }
                        else {
                                repeat = 0;
                        }
                }
                else {
                        do {
                                printf("Would you like to try again? 0 for no, 1 for yes: ");
                                scanf("%d", &repeatVal);
                                if (1 == repeatVal) {
                                        repeat = 1;
                                }
                        } while (!(1 == repeatVal || 0 == repeatVal));
                }
        } while (1 == repeat);
        return 0;
}

