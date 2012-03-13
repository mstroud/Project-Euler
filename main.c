#include <stdio.h>
#include <stdlib.h>
#include "projects.h"

int main(int argc, char *argv[])
{
    //Usage will ProjectEuler N, where N is the problem number to run

    int ProjectNumber = 0;
    if (argc != 2)
        {
            printf("Not enough arguments, or too many arguments.\n");
            printf("Proper useage is: ./ProjectEuler #, where # is the project number to run\n");
        }

    else
        {
            ProjectNumber = atoi(argv[1]);
            switch (ProjectNumber)
                {
                    case 1:
                        PE1main();
                        break;
                    case 2:
                        PE2main();
                        break;
                    case 3:
                        PE3main();
                        break;
                    default:
                        printf("Project %i not found.\n", ProjectNumber);
                        break;
                }
        }

    return 0;
}
