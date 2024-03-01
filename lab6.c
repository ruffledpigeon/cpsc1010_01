/*---------------------------------------
Joanna Ni  Tues, Feb 27, 2024
1011 01  Lab#6

This program revisits the car loan calculator and adds arrays and strings to its process. 
---------------------------------------*/

#include <stdio.h>
#include <math.h>

#define NUM_LINES 3
#define MAX_LENGTH 95

int main () {
	int loanAmt, term;  //user inputs
	double monthPay, intRate;
	
	int repeat, repeatVal;
	double tenPerc, fifPerc, rate; 
	double  monthPmt;

	//int a[3][4]; <-- this format for 2D, 3 rows, 4 column

	char array[NUM_LINES][MAX_LENGTH];

	for (int i = 0; i < NUM_LINES; i++) {
		fgets(array[i], MAX_LENGTH, stdin); 
	}

/*
	//array checking starts here
	for (int i = 0; i < NUM_LINES; i++) {
		printf("%s", array[i]);
		}
		printf("/n");
*/

	//comment out before submission
	//freopen("/dev/tty", "rw", stdin);

	printf("\n\nCAR LOAN CALCULATOR\n");
	printf("\nWhat is your monthly take-home pay?  ");
	scanf("%lf", &monthPay);

	repeat = 1;

	//loop starts here
	do {
		printf("\nEnter the loan amount:  ");  //questions
		scanf("%d", &loanAmt);
		printf("Interest rate:  ");
		scanf("%lf", &intRate);
		printf("Term of loan (number of months):  ");
		scanf("%d", &term);

		rate = intRate / 100;
		monthPmt = loanAmt * ((rate / 12) / (1 - pow((1 + (rate/12)), (-1 * term))));
		
		//printing output
		printf("\n\nYour monthly payment will be:  $%.2lf.\n", monthPmt);
		printf("\nAt the end of the loan, you will have paid $%.2lf", (monthPmt * term) - loanAmt);
		printf("\nin interest for a total of $%.2lf.\n", monthPmt * term);

		tenPerc = monthPay * 0.10;   //Calc % of user's pay
		fifPerc = monthPay * 0.15;

		printf("\n\n");

		//Conditions if car is affordable
		if (monthPmt > fifPerc) {
			printf("%s\n\n", array[0]);
		} 
		else if ((monthPmt > tenPerc) && (monthPmt < fifPerc)) {
			printf("%s\n\n", array[1]);
		}
		else if (monthPmt <= tenPerc) {
			printf("%s\n\n", array[2]);
		}	
		//asking to repeat
		printf("Would you like to try again? 0 for no, 1 for yes:  ");
		scanf("%d", &repeatVal);
/*
		if (1 == repeatVal || 0 == repeatVal) {//if input is 1 or 0
			if (1 == repeatVal) { //if user inputs 1
				repeat = 1;
			}
			if (0 == repeatVal) { //if user inputs 0
				repeat = 0;
			}
		}
		else { //if repeat input invalid
			do {
				printf("Would you like to try again? 0 for no, 1 for yes:  ");
				scanf("%d", &repeatVal);
				if (1 == repeatVal) {
					repeat = 1;
				} //do-while input is neither 1 or 0
			} while (!(1 == repeatVal || 0 == repeatVal));
		}
		*/

		if (repeatVal == 1) {
			repeat = 1;
		}
		else if (repeatVal == 0) {
			repeat = 0;
		}
		else {
			while (!(repeatVal == 1 || repeatVal == 0)) {
				printf("Would you like to try again? 0 for no, 1 for yes:  ");
				scanf("%d", &repeatVal);
				if (repeatVal == 1) {
					repeat = 1;
				}
				if (repeatVal == 0) {
					repeat = 0;
				}
			}
		}		

	} while (1 == repeat); //runs while repeat is true 

	return 0;
}
