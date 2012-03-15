#include <stdint.h>
#include <math.h>
#include "ProjectEuler.h"

#define DEBUG  0
#define NUMBER 600851475143ULL
#define PLIMIT (1<<20)

// Regular implementation
int largestprimefactorof(uint64_t, uint64_t);

// Caching implementation
int isitprime_cache(uint64_t);
uint64_t largestprimefactorof_cache(uint64_t num);

// Caching implementation Globals
uint64_t primes[PLIMIT];
unsigned int N = 0;

/*----------------------------------------*/
/* Find the largest prime factor of 'num' */
/* starting at integer 'start'            */
/*----------------------------------------*/
int largestprimefactorof(uint64_t num, uint64_t start) {
  uint64_t j, root = (uint64_t)sqrt((double)num);

  if(DEBUG) printf("largestprimefactorof(%12lld,%6lld), ", num, start); 
  if(DEBUG) printf("sqrt(%lld)=%lld\n",num,root);

  /* Start loop at last factor (since all smaller factors */
  /* have already been found). Find the next smallest factor, */
  /* divide it out, and recurse. */
  for(j=start;j<=root;j++) {
    if( num % j == 0 )
      return largestprimefactorof(num/j,j);
  }
  /* No factors smaller than the square root? */
  /* This bitch be prime! */
  return num;
}

/*-------------------------------------------------------*/
/* Project Euler Problem #3 main (normal implementation) */
/*-------------------------------------------------------*/
int PE3main(pe_data_t *pedata)
{
    uint64_t y;
    uint64_t num = NUMBER;
 
    /* Find the largest prime factor, starting with 2 */
    y = largestprimefactorof(num,2);
    
    if (pedata->verbosity > 0) printf("--\nLargest Prime Factor of '%lld' is '%lld'\n",num,y);
    sprintf(pedata->result,"%lld",y);
    return 0;
}

/*-----------------------------------*/
/* Find out if a number 'p' is prime */
/*-----------------------------------*/
int isitprime_cache(uint64_t p) {
  static unsigned int lp=2;
  unsigned int j;

  // Step 1) Pre-compute all primes less than input 'p'
  while(lp<p && N<PLIMIT) {
    // While largest computed prime is less than input
    // prime candidate
    char isprime = 1;
    for(j=0;j<N;j++){
      if( lp % primes[j] == 0 ) {
        isprime = 0;
        break;
      }
    }
    if(isprime) {
      if(DEBUG) printf("\n- (%d)%d",N,lp);
      primes[N++] = lp;
    }
    lp++;
  }
  // At this point we should have all 'n' primes that exist
  // from 2 to 'p' precomputed in primes[]
  // Check to make sure we don't exceed PLIMIT before proceeding
  if( N>=PLIMIT ) return 1;

  // Step 2) Figure out if 'p' is prime
  for(j=0;j<N;j++){
    // Loop through the array of primes and test 'p' for factors...
    if( primes[j] == p ) // Exact match to existing prime
      return 1;
    if( p % primes[j] == 0 ) // Not prime!
      return 0; // Don't waste any more time once we find a factor
  }
  // This number is prime, and we don't have it in our list yet
  // Save it for later and return success
  if(DEBUG) printf("\n- (%d)%d *",N,lp);
  primes[N++] = p;

  return 1;
}

/*----------------------------------------*/
/* Find the largest prime factor of 'num' */
/*----------------------------------------*/
uint64_t largestprimefactorof_cache(uint64_t num) {
  uint64_t j;
  if(DEBUG) printf("call(%llu)... ",num);
  if ( isitprime_cache(num) ) // Check to see if the number itself is prime
    return num;
  for(j=0;j<N;j++) {
    // Find the lowest prime factor and recursively call 
    // until the last (largest) factor is found
    if( num % primes[j] == 0 )
      return largestprimefactorof_cache(num/primes[j]);
  }
  return 1;
}

/*--------------------------------------------------------*/
/* Project Euler Problem #3 main (caching implementation) */
/*--------------------------------------------------------*/
int PE3main_cache(pe_data_t *pedata)
{
    uint64_t y;
    uint64_t num = NUMBER;
 
    y = largestprimefactorof_cache(num);
   
    if (pedata->verbosity > 0) printf("\n\nLargest Prime Factor of '%llu' is '%llu' after computing '%d' primes.\n",num,y,N);
    sprintf(pedata->result,"%lld",y);
    return 0;
}
