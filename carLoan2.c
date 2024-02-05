// car loan code - code for students in:
// ~/101/classExamples/Chp4
//
// calculate total amount paid by the end of a loan 
// 	based on montly payment
// total amount paid = monthly payment * term of loan (# months)
// 
// will add a loop later

/*-----------------------------------------
Calculates car loan affordability based on monthly income. Stops if affordable, else repeat.
-----------------------------------------*/


#include <stdio.h>

int main() {
	double monthlyPmt, loanAmt;
	int tenPercent, fifteenPercent, netMonth;
	int term;
	int repeat, repeatValue;
	do {
		printf("\n\nCan I afford this car?");
		printf("\n\nMonthly payment amount:  ");
		scanf("%lf", &monthlyPmt);
		
		printf("Term of loan (total number of months):  ");
		scanf("%d", &term);
		
		printf("Original loan amount:  ");
		scanf("%lf", &loanAmt);

		printf("\n\nTotal amount paid back:  $%.2lf", monthlyPmt * term);

		printf("\nTotal interest paid back:  $%.2lf", 
		(monthlyPmt * term) - loanAmt);

		printf("\n\n");

		printf("Enter your monthly take-home pay  ");
		scanf("%d", &netMonth);


//Calculate 10% of 15% of netMonth
		tenPercent = netMonth * 0.10;
		fifteenPercent = netMonth * 0.15;

//Conditions if car is affordable
		if ((int)monthlyPmt > fifteenPercent) {
			
			printf("\n\nThis car payment is more than 15%% of your monthly income \nand is probably not affordable.");
		printf("\n\nWould you like to try again? 0 for no, 1 for yes: ");
		scanf("%d", &repeatValue);
		//the repea`t conditions
		if ((1 == repeatValue) || (0 == repeatValue)) {
			if (1 == repeatValue) {	
				repeat = 1;
			}
			else {
				repeat = 0;
			}
		}
		else {
			do {
				printf("Would you like to try again? 0 for no, 1 for yes: ");
				scanf("%d", &repeatValue);
				if (1 == repeatValue) {
					repeat = 1;
				}
			} while (!((1 == repeatValue) || (0 == repeatValue)));
		}
		//repeat conditions end here
		
		} else if (((int)monthlyPmt >= tenPercent) && ((int)monthlyPmt <= fifteenPercent)) {
			
			printf("\n\nThis car payment is between 10-15%% of your monthly income. \nIt might be affordable.");
			repeat = 0;
			//printf("\n%.2lf is between %d and %d", monthlyPmt, tenPercent, fifteenPercent);
			}	
		else {
			printf("\n\nThis car payment is less than 10%% of your monthly income. \nThis is an affordable car.");
			repeat = 0;
			//printf("\n%.2lf is less than %d", monthlyPmt, fifteenPercent);
		}
	} while (1 == repeat);
	return 0;
}
