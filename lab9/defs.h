
#ifndef DEFS_H
#define DEFS_H

#include <stdio.h>

#define nameLength 20
#define ingredientsLength 70

typedef struct {
	char pizzaName[nameLength];
	char ingredients[ingredientsLength];
} pizza_t;

//prototypes
void initPizzas(pizza_t menu[], int numPizza);
void printPizzas(pizza_t menu[], int numPizza);

#endif
