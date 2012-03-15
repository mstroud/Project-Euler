#include <stdio.h>
#include <stdlib.h>

#ifndef __ProjectEulerH
#define __ProjectEulerH

// PE defines
#define NUM_PROBLEMS 3

// PE data structures
typedef struct {
  char verbosity;
  char result[64];
} pe_data_t ;

// PE function prototypes
int PE1main(pe_data_t*);
int PE2main(pe_data_t*);
int PE3main(pe_data_t*);

#endif
