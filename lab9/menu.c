#include "defs.h"

/*------------------------printPizzas--------------------------------
- prints the array of pizza names and their ingredients
- parameters: 
- returns: none
-------------------------------------------------------------------*/
void printPizzas(pizza_t menu[], int numPizza){

	printf("\n\n%25s", "PIZZA MENU");
	printf("\n\n%-20sIngredients\n", "Pizza");
	printf("----------------------------------------------------\n\n");
	
	for (int i = 0; i < numPizza; i++) {
		printf("%-20s%-70s\n", menu[i].pizzaName, menu[i].ingredients);
	}
}
