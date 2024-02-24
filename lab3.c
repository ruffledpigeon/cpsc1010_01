/*---------------------------------------
Tues, Feb 6, 2024
1011 01  Lab#3

This program serves as a car loan calculator and uses a loop in its process
---------------------------------------*/

#include <stdio.h>
#include <math.h>

int main () {
	int loanAmt, term;  //user inputs
	double monthPay, intRate;
	
	int repeat, repeatVal;
	double tenPerc, fifPerc, rate; 
	double  monthPmt;

	printf("\n\nCAR LOAN CALCULATOR");
	printf("\n\nWhat is your monthly take-home pay?  ");
	scanf("%lf", &monthPay);

	repeat = 1;
	//loop starts here

	do {
		printf("\nEnter the loan amount:  ");  //questions
		scanf("%d", &loanAmt);
		printf("Interest rate:  ");
		scanf("%lf", &intRate);
		printf("Term on loan (number of months):  ");
		scanf("%d", &term);

		rate = intRate / 100;
		monthPmt = loanAmt * ((rate / 12) / (1 - pow((1 + (rate/12)), (-1 * term))));
		
		//printing output
		printf("\n\nYour monthly payment will be:  $%.2lf.", monthPmt);
		printf("\nAt the end of the loan, you will have paid $%.2lf", (monthPmt * term) - loanAmt);
		printf("\nin interest for a total of $%.2lf.", monthPmt * term);

		tenPerc = monthPay * 0.10;   //Calc % of user's pay
		fifPerc = monthPay * 0.15;

		//Conditions if car is affordable
		if (monthPmt > fifPerc) {
			printf("\n\nThe monthly payment is more than 15%% of your monthly income \nand is probably not affordable.");
		} 
		else if ((monthPmt > tenPerc) && (monthPmt < fifPerc)) {
			printf("\n\nThe monthly payment is between 10-15%% of your monthly income. \nIt might be affordable.");
		}
		else if (monthPmt <= tenPerc) {
			printf("\n\nThe monthly payment is less than 10%% of your monthly income. \nThis is an affordable loan.");
		}	

		printf("\nWould you like to try again? 0 for no, 1 for yes:  ");
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
