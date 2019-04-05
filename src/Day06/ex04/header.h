#ifndef HEADER_H
# define HEADER_H
#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...
/*--------------------------------
  !! required structure
  --------------------------------*/
#define WIDTH 8

/*--------------------------------
  :) function you must implement
  --------------------------------*/
int getInitialPos(uint64_t board);
double knightOut(uint64_t board, int n);

/*--------------------------------
  ?? test function used in main 
  --------------------------------*/
void printBoard(uint64_t board);

/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif
