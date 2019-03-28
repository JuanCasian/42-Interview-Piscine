#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(void)
{
	struct s_tank *tank;
	int res;

	/*-------------------
	launch your test here
	--------------------*/
	if (!(tank = initTank()))
	{
		printf("Error initiating tank");
		return (-1);
	}
	tankPush(tank, 990);
	printf("Tank stacks = %i\n", tank->n);
	tankPush(tank, 20);
	printf("Tank stacks = %i\n", tank->n);
	tankPush(tank, 900);
	printf("Tank stacks = %i\n", tank->n);
	tankPush(tank, 500);
	printf("Tank stacks = %i\n", tank->n);
	while ((res = tankPop(tank)) != -1)
		printf("Tanks pop result: %i\n", res);
	return (0);
}



// Function used for the test
// Don't go further :)
