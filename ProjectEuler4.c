#include "ProjectEuler.h"

int ispalindrome(int test)
{
    char willflip[15];
    char willkeep[15];

    int compare;
    //get the integer into a string
    //itoa is not standard, let's try something else.
    //itoa (test, willflip, 10);
    sprintf(willflip, "%i", test);
    //move the string to something we want untouched
    strcpy(willkeep, willflip);
    //strrev does what you'd think
    //strrev (willflip);
    //strcmp returns 0 if equal
    compare = strcmp (willkeep, willflip);

    if (compare == 0)
        return 1;
    else
        return 0;

}

int PE4main()
{
    int largest_palindrome = 0, temp = 0;
    int x, y, total;

    for (x = 100; x <=999; x++)
        {
            for (y = 100; y <= 999; y++)
                {
                    total = x * y;
                    if (ispalindrome(total))
                        {
                            temp = total;
                            if (temp > largest_palindrome)
                                largest_palindrome = total;
                        }

                }
        }

    printf("Largest palindrome is %i", largest_palindrome);

    return 0;
}
