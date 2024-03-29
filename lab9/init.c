/*---------------------------------------------
Joanna Ni 3/26/2024 
1011 01 Lab#9

init.c - initializes array that stores pizza information
---------------------------------------------*/

#include "defs.h"
#include <string.h>

/*--------------------------initArray------------------------------
- initializes array using information from pizzas.txt
- parameters: nameLength, ingredientsLength
- returns: none
-----------------------------------------------------------------*/
void initPizzas(pizza_t menu[], int numPizza) {
	int length;
	for (int i = 0; i < numPizza; i++) {
		//think it is also reading the 10

		//name
		fgets(menu[i].pizzaName, nameLength, stdin);
		length = strlen(menu[i].pizzaName); 
		if (menu[i].pizzaName[length - 1]  == '\n') {
			menu[i].pizzaName[length - 1] = '\0';
		}

		//ingredients
		fgets(menu[i].ingredients, ingredientsLength, stdin);
		length = strlen(menu[i].ingredients); 
		if (menu[i].ingredients[length - 1]  == '\n') {
			menu[i].ingredients[length - 1] = '\0';
		}
	}	
/*
	for (int i = 0; i < numPizza; i++) {
		for (int j = 0; menu[i].pizzaName[j] != '\0'; j++) {
			printf("%d ", menu[i].pizzaName[j]);
		}
		printf("\n");
		for (int j = 0; menu[i].ingredients[j] != '\0'; j++) {
			printf("%d ", menu[i].ingredients[j]);
		}
	}
*/
}
	

