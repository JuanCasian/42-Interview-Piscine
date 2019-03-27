#ifndef HEADER_H
# define HEADER_H

#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

/*--------------------------------
  !! required structure
  --------------------------------*/
struct s_city {
	char *name;
	struct s_city *next;
};

/*--------------------------------
  :) function you must implement
  --------------------------------*/
char *NthLastCity(struct s_city *city, int n);

/*--------------------------------
  ?? test function used in main 
  --------------------------------*/
struct s_city *getCities(void);


/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif
