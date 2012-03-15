#include "ProjectEuler.h"

#define PE7_LIMIT 10001

int PE7main(pe_data_t *pedata)
{
  unsigned long primes[PE7_LIMIT],i;
  int n=0,j;
  char isprime;

  // Start with 2, the first prime  
  for(i=2;n<PE7_LIMIT;i++){
    isprime=1;
    for(j=0;j<n;j++){
      if( i % primes[j] == 0 ){
        isprime=0;
        break; // Don't waste any more time once we find a factor
      }
    }
    if(isprime){ // Got one!
      primes[n++] = i;
      if (pedata->verbosity>0) printf("%ld,",i);
    }
  }
  if (pedata->verbosity>0) printf("\n");
 
  sprintf(pedata->result,"%lu",primes[PE7_LIMIT-1]);
  return 0;
}

