/* Project Euler Problem 9 */
#include "ProjectEuler.h"

int PE9main(pe_data_t *pedata)
{

  int m,n;
  int a,b,c;

  for (n=1; n<100; n++)
    {
      for(m = n+1; m<100; m++)
	{
	  a = (m*m) - (n*n);
	  b = 2 * m * n;
	  c = (m*m) + (n*n);
	  
	  if ((a + b + c) == 1000)
	    {
	      sprintf(pedata->result, "%i", a * b * c);
	      if (pedata->verbosity >0) printf ("Result: %i\n", a*b*c);
	    }
	}
    }


return 0;
}
