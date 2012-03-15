/* Project Euler Problem 1 */
#include "ProjectEuler.h"

int multiple_of_three_or_five (int number)
{
    if (((number % 3) && (number % 5)) == 0)
        return 1;
    else
        return 0;
}


int PE1main(pe_data_t *pedata)
{
    int total = 0, index = 1, condition = 0;

    printf("Running Project Euler Problem 1\n");
    for (index = 1; index < 1000; index++)
        {
            condition = multiple_of_three_or_five (index);

            if (condition == 1)
                total = total + index;
        }

    if (pedata->verbosity > 0) printf ("Total: %i\n", total);
    sprintf(pedata->result,"%i",total);

    return 0;
}
