// car loan code - code for students in:
// ~/101/classExamples/Chp4
//
// calculate total amount paid by the end of a loan 
// 	based on montly payment
// total amount paid = monthly payment * term of loan (# months)
// 
// will add a loop later

/*-----------------------------------------
Calculates loan and repeats based on user input.
-----------------------------------------*/


#include <stdio.h>

int main() {
	double monthlyPmt, loanAmt;
	int term;
	int repeat = 0, repeatValue = 0;


	do {
		printf("\n\nTotal amount paid back at end of a car loan");
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
		repeat = 0;
		printf("\n\nWould you like to try again? 0 for no, 1 for yes: ");
		scanf("%d", &repeatValue);

		
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

	} while (repeat != 0);

/*
	if ((1 == repeatValue) || (0 == repeatValue)) {
		if (1 == repeatValue) {
			repeat = 1;
		}
		else {
			repeat = 0;
			printf("\n\nWould you like to try again? 0 for no, 1 for yes: ");
		}
	}
	else {
		repeat = 0;
		printf("\n\nWould you like to try again? 0 for no, 1 for yes: ");
	}

*/
	return 0;
}
