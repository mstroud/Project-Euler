#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ProjectEulerFuncTable.h"
#include "ProjectEulerAnswerKey.h"

// main helper prototypes
int run_all(pe_data_t*);
int run_solution(pe_data_t*,int);

/* Usage will ProjectEuler N, where N is the problem number to run */
int main(int argc, char *argv[])
{
    pe_data_t pedata ;
    int ProblemNumber  = 0;

    if (argc != 2)
        {
            printf("Not enough arguments, or too many arguments.\n");
            printf("Proper usage is: ./ProjectEuler #, where # is the problem number to run\n");
        }

    else
        {
            // Configure parameters
            ProblemNumber    = atoi(argv[1]);
            pedata.verbosity = 0 ; // change to > 0 for verbose outputs

            // Check and run solution
            if ( ProblemNumber == 0)
                run_all(&pedata);
            else if (ProblemNumber <= NUM_PROBLEMS)
                run_solution(&pedata,ProblemNumber);
            else
                printf("Problem #%03d not found.\n", ProblemNumber);

        }

    return 0;
}

/* Run a single solution */
int run_solution(pe_data_t* pedata, int ProblemNumber)
{
    int SolutionStatus = 0;
    int SolutionError  = 0;

    // Check for NULL function pointer...
    if ( PE_func_table[ProblemNumber] != NULL )
        {
            // Look up requested solution in function pointer table and run it
            SolutionStatus = PE_func_table[ProblemNumber](pedata);

            // Compare solution output with answer key
            SolutionError  = strcmp(pedata->result,PE_answer_table[ProblemNumber]);

            if (SolutionStatus == 0)
                printf("Project Euler problem #%03d solution: %-32s (%s)\n",
                                                                  ProblemNumber,
                                                                  pedata->result,
                                                                  (SolutionError==0)?"PASSED!":"FAILED!");
            else
                printf("Project Euler problem #%03d solution failed with code '%03d'\n",ProblemNumber,SolutionStatus);
        }

     else
        {
            printf("Problem #%03d solution not implemented.\n", ProblemNumber);
        }

     return SolutionStatus ;
}

/* Run all solutions */
int run_all(pe_data_t* pedata)
{
    for(int i=1;i<=NUM_PROBLEMS;i++)
        run_solution(pedata,i);

    return 0;
}
