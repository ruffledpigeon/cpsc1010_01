/*--------------------------------------------------------
Joanna Ni 3/26/2024
1011 01 Lab#9

lab9.c - contains main function that calls functions located in other files
--------------------------------------------------------*/

#include "defs.h"

int main() {
	int numPizza;
	scanf("%d\n", &numPizza); //offshift bc missing \n

	pizza_t menu[numPizza]; //array with 10 slots
	initPizzas(menu, numPizza);
	printPizzas(menu, numPizza);

	return 0;
}
