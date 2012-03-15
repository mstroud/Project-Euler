#include <math.h>
#include "ProjectEuler.h"

#define NUMBER 600851475143

int IsPrime(unsigned long int);

int PE3main(pe_data_t *pedata)
{
    unsigned long int x = 1;
    unsigned int largestprime = 42;
    int y;

    for (x = 1; x <= sqrt(NUMBER); x++)
        {
            //printf("Testing %li \n", x);

            if ((NUMBER % x) == 0)
                if ((y = IsPrime(x)))
                    largestprime = x;
        }

    if (pedata->verbosity > 0) printf("Largest prime is: %i\n", largestprime);
    sprintf(pedata->result,"%u",largestprime);

    return 0;
}

int IsPrime(unsigned long int x)
{
    int index;

    if (x % 2 == 0) {return 0;}

    for (index = 3; index < x; index++)
        {
            if ((x % index) == 0)
            {
                return 0;
            }
        }
    return 1;
}
