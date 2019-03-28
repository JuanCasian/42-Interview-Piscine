#ifndef HEADER_H
# define HEADER_H

#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...
#include <time.h>
#include <ctype.h>

/*--------------------------------
  !! required structure
  --------------------------------*/
struct s_node {
	int value;
	int isFinal;
	struct s_node *random;
	struct s_node *next;
};

struct s_queue {
  struct s_item *first;
	struct s_item *last;
};

struct s_item {
	struct s_node *parent;
	struct s_node *node;
	struct s_item *next;
};

struct s_queue *queueInit(void);

struct s_node *dequeue(struct s_queue *queue);

void enqueue(struct s_queue *queue, struct s_node *node);

struct s_node *peek(struct s_queue *queue);

int isEmpty(struct s_queue *queue);

/*--------------------------------
  :) function you must implement
  --------------------------------*/
int	minimumMoves(struct s_node *begin); //you must return the minimum number of strokes to access to the final

/*--------------------------------
  ?? test function used in main
  --------------------------------*/
struct s_node *getBoardFromFile(char *file);

/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif
