/* Project Euler problem 1 */
#include "ProjectEuler.h"

int PE1main(pe_data_t* pedata)
{
    /* Sum all multiples of 3 or 5 below 1000 */
    /* And, make sure not to count multiples of BOTH 3 and 5 twice! */
    unsigned int limit = 1000;
    unsigned int L     = (limit-1)/3;
    unsigned int M     = (limit-1)/5;
    unsigned int N     = (limit-1)/15;
    unsigned int total = ( 3*(L*(L+1)) + 
                           5*(M*(M+1)) - 
                          15*(N*(N+1))   )/2;

    // Report results
    if (pedata->verbosity > 0) printf ("L: %u M: %u N: %u Total: %i\n", L,M,N,total);
    sprintf(pedata->result,"%u",total);
    return 0;
}
