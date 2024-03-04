/*
Car Loan program revised to store and output an amortization table in an array.
spent three days on it crying and solved it when i put interest formula first 
*/
#include <stdio.h>
#include <math.h>

int main () {
	int loanAmt, term; //3 user inputs
	double intRate;

	double rate, monthPmt; //outputs 
	double principal, monthlyInt;
	double principalBalance;

	printf("\n\nMonthly payment for a car loan.\n");
	printf("\nEnter the loan amount:  "); //questions
	scanf("%d", &loanAmt);
	printf("Interest rate:  ");
	scanf("%lf", &intRate);
	printf("Term on loan (number of  months):  "); //space
	scanf("%d", &term);

	principalBalance = loanAmt;   //formulas
	rate = intRate / 100.00;
	monthPmt = loanAmt * ((rate/12) / (1 - pow((1 + (rate/12)), -term)));

	printf("\n\nYour monthly payment will be:  $%.2lf.\n", monthPmt);
	printf("At the end of the loan, you will have paid a total:  $%.2lf.\n", monthPmt * term);
	
	printf("\n\n");

	//array starts here
	double array[term][3]; //array[row][columns]

	//     [principal][monthlyInt][principalBalance]
	printf("Principal\t\tInterest\t\tLoan Balance\n");
	printf("---------\t\t--------\t\t------------\n");

	for (int i = 0; i < term; i++) { // Rows
        monthlyInt = principalBalance * rate / 12;
        principal = monthPmt - monthlyInt;
        principalBalance -= principal; // remaining balance

        if (principalBalance < 0) {
			  principalBalance = principalBalance * -1;
		  }

		  array[i][0] = principal;
        array[i][1] = monthlyInt;
        array[i][2] = principalBalance;

        printf("$%.2lf\t\t$%.2lf\t\t$%.2lf\n", array[i][0], array[i][1], array[i][2]);
    }

    return 0;
}
