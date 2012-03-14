#include "ProjectEuler.h"
#include <stdint.h>
#include <math.h>
#include "ProjectEuler.h"

#define DEBUG  1
#define NUMBER 600851475143ULL

int largestprimefactorof(uint64_t, uint64_t);

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

int PE3main()
{
    uint64_t y;
    uint64_t num = NUMBER;
 
    /* Find the largest prime factor, starting with 2 */
    y = largestprimefactorof(num,2);
    printf("--\nLargest Prime Factor of '%lld' is '%lld'\n",num,y);

    return 0;
}
