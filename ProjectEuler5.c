#include "ProjectEuler.h"
#include <stdint.h>
#include <math.h>

#define NUM    20

/*-----------------------------------------*/
/* Find the least common multiple of the   */
/* integers between 1 and 'NUM'            */
/*-----------------------------------------*/
int PE5main(pe_data_t* pedata)
{
    int64_t factors[NUM]; 
    int64_t num_factors=0;
    int64_t num=0;
    int64_t i=0,j=0;
    int64_t result=1;
 
    for(i=2;i<=NUM;i++) {
      num = i ;
      for(j=0;j<num_factors;j++) {
        if ( num % factors[j] == 0 ) { 
          num = num / factors[j] ;
        }
      }
      if( num != 1 ) {
        factors[num_factors++] = num;
        result = result*num;
      }        
      if(pedata->verbosity>0) printf("Least common multiple of '1..%5lld' is '%lld'\n",i,result);
    }
    sprintf(pedata->result,"%llu",result);
    return 0;
}
