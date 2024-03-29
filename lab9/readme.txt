makefile - removed defs.h

init.c - was using sizeof(menu[i].pizzaName) instead of nameLength which gave number of bytes, not length of array
fgets(menu[i].pizzaName, nameLength, stdin)
fgets(menu[i].ingredients, ingredientsLength, stdin)
- also named it initArray instead of initPizzas()

lab9.out - %d only won't read \n, changed to "%d\n"
