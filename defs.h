/*------------------
Joanna Ni CPSC 1011 01
3/26/2024 Lab#9

defs.h - contains header guard and prototypes
------------------*/

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
