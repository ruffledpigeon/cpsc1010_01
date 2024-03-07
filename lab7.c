/*---------------------------------------
Joanna Ni  Tues, Mar 5, 2024
1011 01  Lab#7

This program revisits the car loan calculator and adds separate functions to condense the main function. 
---------------------------------------*/

#include <stdio.h>
#include <math.h>

#define NUM_LINES 3
#define MAX_LENGTH 95

//prototypes
void initArray(char array[][MAX_LENGTH]);
double getMonthlyPmt();
void printAffordability(char array[][MAX_LENGTH], double monthPmt, double monthSalary);

int main () {
	char array[NUM_LINES][MAX_LENGTH]; //creating the array
	double monthSalary, monthPmt;
	int repeat = 1, repeatVal; //for repeat process

	initArray(array);

	printf("\n\nCAR LOAN CALCULATOR\n");
	printf("\nWhat is your monthly take-home pay?  ");
	scanf("%lf", &monthSalary);

	do {
		monthPmt = getMonthlyPmt(); 
		printAffordability(array, monthPmt, monthSalary);

		//asking if want to repeat
		printf("Would you like to try again? 0 for no, 1 for yes:  ");
		scanf("%d", &repeatVal);

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
		}		//end repeat loop

	} while (1 == repeat); //runs while repeat is true 

	return 0;
}

/*------------------------getMonthlyPmt-----------------------------
- gets user input: loan amount, interest rate, term
- parameters: none
- return: the monthly payment
*/
double getMonthlyPmt() {
	int loanAmt, term;
	double monthPmt, rate, intRate;

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

	printf("\n\n");
	return monthPmt;
}

/*------------------------initArray---------------------------------
- initializes array, fill with affordability statements
- parameters: MAX_LENGTH
- return: none
*/
void initArray(char array[][MAX_LENGTH]) {
	//char array[NUM_LINES][MAX_LENGTH];
	for (int i = 0; i < NUM_LINES; i++) {
		fgets(array[i], MAX_LENGTH, stdin); 
	}

	//comment out before submission
	//freopen("/dev/tty", "rw", stdin);
}

/*-----------------------printAffordability--------------------------
- prints appropriate affordability statement based on monthly payment and monthly pay
- parameters: array[][MAX_LENGTH], monthPmt, monthPay
- return: none
*/
void printAffordability(char array[][MAX_LENGTH], double monthPmt, double monthSalary) {
	double tenPerc = monthSalary * 0.10;   //Calc % of user's pay
	double fifPerc = monthSalary * 0.15;
	
	if (monthPmt > fifPerc) {
		printf("%s\n\n", array[0]);
	} else if ((monthPmt > tenPerc) && (monthPmt < fifPerc)) {
		printf("%s\n\n", array[1]);
	} else if (monthPmt <= tenPerc) {
		printf("%s\n\n", array[2]);
	}	
}


