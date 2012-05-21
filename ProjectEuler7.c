#include "ProjectEuler.h"

#define MAXTEST 100000000

extern int IsPrime(unsigned long int);
int primecount = 0;

int PE7main(pe_data_t *pedata)
{
  int x;
  for (x = 2; x <= MAXTEST; x++)
    {
      if (IsPrime(x))
	{
	  primecount++;
	}
      
      if (primecount + 1 >= 10001)
	{
	  if (pedata->verbosity > 0) printf ("Result: %i\n", x);
	  sprintf(pedata->result, "%i", x);
	  break;
	}
    }
  return 0;
}
