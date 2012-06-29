/* Project Euler Problem 11 */
#include "ProjectEuler.h"

/* Remember 2d arrays are declared array[rows][columns] */

/* I'm recycling code for looping through 2d arrays. The tests for
   breaking out of the loop when there aren't four in a row or diagonal
   left are in if statements. The other way would have been simply artificially
   shorten the for loops. Six of one... */

#define NROW 20 /* Number of rows */
#define NCOL 20 /* Number of columns */

int PE11Array[NROW][NCOL] = {
  {8, 2, 22, 97, 38, 15, 0, 40, 0, 75, 4, 5, 7, 78, 52, 12, 50, 77, 91, 8},
  {49, 49, 99, 40, 17, 81, 18, 57, 60, 87, 17, 40, 98, 43, 69, 48, 04, 56, 62, 00},
  {81, 49, 31, 73, 55, 79, 14, 29, 93, 71, 40, 67, 53, 88, 30, 03, 49, 13, 36, 65},
  {52, 70, 95, 23, 4, 60, 11, 42, 69, 24, 68, 56, 01, 32, 56, 71, 37, 02, 36, 91},
  {22, 31, 16, 71, 51, 67, 63, 89, 41, 92, 36, 54, 22, 40, 40, 28, 66, 33, 13, 80},
  {24, 47, 32, 60, 99, 3, 45, 02, 44, 75, 33, 53, 78, 36, 84, 20, 35, 17, 12, 50},
  {32, 98, 81, 28, 64, 23, 67, 10, 26, 38, 40, 67, 59, 54, 70, 66, 18, 38, 64, 70},
  {67, 26, 20, 68, 02, 62, 12, 20, 95, 63, 94, 39, 63, 8, 40, 91, 66, 49, 94, 21},
  {24, 55, 58, 5, 66, 73, 99, 26, 97, 17, 78, 78, 96, 83, 14, 88, 34, 89, 63, 72},
  {21, 36, 23, 9, 75, 0, 76, 44, 20, 45, 35, 14, 0, 61, 33, 97, 34, 31, 33, 95},
  {78, 17, 53, 28, 22, 75, 31, 67, 15, 94, 3, 80, 4, 62, 16, 14, 9, 53, 56, 92},
  {16, 39, 5, 42, 96, 35, 31, 47, 55, 58, 88, 24, 0, 17, 54, 24, 36, 29, 85, 57},
  {86, 56, 0, 48, 35, 71, 89, 7, 5, 44, 44, 37, 44, 60, 21, 58, 51, 54, 17, 58},
  {19, 80, 81, 68, 5, 94, 47, 69, 28, 73, 92, 13, 86, 52, 17, 77, 4, 89, 55, 40},
  {4, 52, 8, 83, 97, 35, 99, 16, 7, 97, 57, 32, 16, 26, 26, 79, 33, 27, 98, 66},
  {88, 36, 68, 87, 57, 62, 20, 72, 3, 46, 33, 67, 46, 55, 12, 32, 63, 93, 53, 69},
  {4, 42, 16, 73, 38, 25, 39, 11, 24, 94, 72, 18, 8, 46, 29, 32, 40, 62, 76, 36},
  {20, 69, 36, 41, 72, 30, 23, 88, 34, 62, 99, 69, 82, 67, 59, 85, 74, 4, 36, 16},
  {20, 73, 35, 29, 78, 31, 90, 1, 74, 31, 49, 71, 48, 86, 81, 16, 23, 57, 5, 54},
  {1, 70, 54, 71, 83, 51, 54, 69, 16, 92, 33, 48, 61, 43, 52, 1, 89, 19, 67, 48}
};

int PE11main(pe_data_t *pedata)
{

  int temp = 0;
  int largest = 0;
  int row,col;
  /* Step 1 is to find all the products of four numbers in a row horizontally*/
  if(pedata->verbosity > 0) printf("Starting Horizontal Row Test\n");
  for (row = 0; row <= (NROW - 1); row++)
    {
      for (col = 0; col <= NCOL - 1; col++)
	{
	  /* if there aren't four left in the row, break */
	  if ((col + 3) > (NCOL - 1))
	    {
	      if(pedata->verbosity > 0) printf("Next line\n");
	      break;
	    }
	  else
	    {
	      temp = ((PE11Array[row][col]) * (PE11Array[row][col+1]) * (PE11Array[row][col+2]) * (PE11Array[row][col+3]));
	      if (temp > largest)
		{
		  largest = temp;
		}
	      if(pedata->verbosity > 0) printf("%i * %i * %i * %i = %i\nLargest is %i\n", (PE11Array[row][col]), (PE11Array[row][col+1]), (PE11Array[row][col+2]), (PE11Array[row][col+3]), temp, largest);

	    }
	}
    }

  /* Step 2 is to find all the products of four numbers in a row vertically */
  if(pedata->verbosity > 0) printf("Starting Vertical Row Test\n");
  for (row = 0; row <= (NROW - 1); row++)
    {
      if ((row + 3) > (NROW - 1))
	{
	  if(pedata->verbosity > 0) printf("Next line\n");
	  break;
	}
      for (col = 0; col <= NCOL - 1; col++)
	{
	  /* if there aren't four left in the row, break */
	  temp = ((PE11Array[row][col]) * (PE11Array[row+1][col]) * (PE11Array[row+2][col]) * (PE11Array[row+3][col]));
	  if (temp > largest)
	    {
	      largest = temp;
	    }
	  if(pedata->verbosity > 0) printf("%i * %i * %i * %i = %i\nLargest is %i\n", (PE11Array[row][col]), (PE11Array[row+1][col]), (PE11Array[row+2][col]), (PE11Array[row+3][col]), temp, largest);
	
	}

    }

  if(pedata->verbosity > 0) printf("Starting Diagonal to the Lower Right Test\n");
  for (row = 0; row <= (NROW - 1); row++)
    {
      if ((row + 3) > (NROW - 1))
	{
	  if(pedata->verbosity > 0) printf("Next line\n");
	  break;
	}
      for (col = 0; col <= NCOL - 1; col++)
	{
	  /* if there aren't four left in the row, break */
	  if ((col + 3) > (NCOL - 1))
	    {
	      if(pedata->verbosity > 0) printf("Next line\n");
	      break;
	    }
	  else
	    {
	      temp = ((PE11Array[row][col]) * (PE11Array[row+1][col+1]) * (PE11Array[row+2][col+2]) * (PE11Array[row+3][col+3]));
	      if (temp > largest)
		{
		  largest = temp;
		}
	      if(pedata->verbosity > 0) printf("%i * %i * %i * %i = %i\nLargest is %i\n", (PE11Array[row][col]), (PE11Array[row+1][col+1]), (PE11Array[row+2][col+2]), (PE11Array[row+3][col+3]), temp, largest);

	    }
	}
    }

  if(pedata->verbosity > 0) printf("Starting Diagonal to the Lower Left Test\n");
  for (row = 0; row <= (NROW - 1); row++)
    {
      if ((row + 3) > (NROW - 1))
	{
	  if(pedata->verbosity > 0) printf("Next line\n");
	  break;
	}
      for (col = 0; col <= NCOL - 1; col++)
	{
	  /* if there aren't four left in the row, break */
	  if ((col - 3) < 0)
	    {
	      if(pedata->verbosity > 0) printf("Next line\n");
	      //break;
	    }
	  else
	    {
	      temp = ((PE11Array[row][col]) * (PE11Array[row+1][col-1]) * (PE11Array[row+2][col-2]) * (PE11Array[row+3][col-3]));
	      if (temp > largest)
		{
		  largest = temp;
		}
	      if(pedata->verbosity > 0) printf("%i * %i * %i * %i = %i\nLargest is %i\n", (PE11Array[row][col]), (PE11Array[row+1][col-1]), (PE11Array[row+2][col-2]), (PE11Array[row+3][col-3]), temp, largest);
	  
	    }
	}
    }






  if (pedata->verbosity > 0) printf ("Largest: %i\n", largest);
  sprintf(pedata->result,"%i",largest);

  return 0;
}
