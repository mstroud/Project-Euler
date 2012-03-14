/* Project Euler Problem 2 */
#include "ProjectEuler.h"

int iseven (int number)
    {
        if ((number % 2) == 0)
            return 1;
        else
            return 0;
    }

int PE2main()
{
    unsigned int next = 0;
    unsigned int current = 1, last = 0, totaleven = 0;

    printf("Running Project Euler Problem 2\n");
    while (1)
    {

        next = current + last;
        last = current;
        current = next;

        if (next > 4000000)
            break;

        if(iseven(next))
            totaleven = totaleven + next;

        /*printf ("Currently at: %i\n", current);*/
    }

    printf("Total: %i\n", totaleven);
    return 0;
}
