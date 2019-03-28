#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(void)
{

	/*-------------------
	launch your test here
	--------------------*/
	struct s_queue 	*q;
	int				i;

	if (!(q = queueInit()))
	{
		printf("Error creating the queue");
		return (-1);
	}
	printf("Adding elements to queue...\n\n");
	enqueue(q, "First in");
	enqueue(q, "Second in");
	printf("Printing peek: %s\n", peek(q));
	enqueue(q, "Third in");
	printf("Printing isEmpty result while queue is full: %i\n", isEmpty(q));
	i = 1;
	while(q->first)
	{
		printf("Printing queue items, deque #%i: %s\n", i, dequeue(q));
		i++;
	}
	printf("Printing isEmpty result when queue is empty: %i\n", isEmpty(q));
	free(q);
	return (0);
}



// Function used for the test
// Don't go further :)

