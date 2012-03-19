#include <stdio.h>

int Natural = 100;
int count;

long long SumOfSquares = 0;
long long SquareOfSums = 0;

int main (int argc, const char * argv[]) {
    
    printf("Finding sum of first %i squared natural numbers\n", Natural);
	
	for (count = 0; count <= Natural; count++)
	{
		SumOfSquares += (count * count);
	}
	
	printf("Finding sum of first %i natural numbers and squaring that sum\n", Natural);
	
	for (count = 0; count <= Natural; count++)
	{
		SquareOfSums += count;
	}
	SquareOfSums = (SquareOfSums * SquareOfSums);
	
	printf("Sum of squares: %lld\n", SumOfSquares);
	printf("Square of sums: %lld\n", SquareOfSums);
	printf("Difference: %lld\n", (SquareOfSums - SumOfSquares));
	
    return 0;
}
