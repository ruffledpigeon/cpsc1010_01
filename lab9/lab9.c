#include "defs.h"

int main() {
	int numPizza;
	scanf("%d\n", &numPizza); //offshift bc missing \n

	pizza_t menu[numPizza]; //array with 10 slots
	initPizzas(menu, numPizza);
	printPizzas(menu, numPizza);

	return 0;
}
