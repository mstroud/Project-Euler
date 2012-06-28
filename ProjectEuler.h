#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef __ProjectEulerH
#define __ProjectEulerH

// PE defines
#define NUM_PROBLEMS 9

// PE data structures
typedef struct {
  char verbosity;
  char result[64];
} pe_data_t ;

// PE function prototypes
int PE1main(pe_data_t*);
int PE2main(pe_data_t*);
int PE3main(pe_data_t*);
int PE4main(pe_data_t*);
int PE5main(pe_data_t*);
int PE6main(pe_data_t*);
int PE7main(pe_data_t*);
int PE8main(pe_data_t*);
int PE9main(pe_data_t*);
#endif
