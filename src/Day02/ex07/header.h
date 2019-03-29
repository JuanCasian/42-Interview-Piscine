#ifndef HEADER_H
# define HEADER_H
#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...
#include <time.h>

/*--------------------------------
  !! required structure
  --------------------------------*/


/*--------------------------------
  :) function you must implement
  --------------------------------*/
void printYoungest(int *ages, int length);

/*--------------------------------
  ?? test function used in main 
  --------------------------------*/
int *createRandomArray(int n);
void printArray(int *arr, int n);

/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif
