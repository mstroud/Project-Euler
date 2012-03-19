#include "ProjectEuler.h"
#define UPPER_TEST 1000000000

int largest = 0;


int DivisorTest (int dividend) {

	for (int divisor = 11; divisor <=20; divisor++) {

		if ((dividend % divisor) > 0) {


			return 0;
		}

	}

    //printf("%i\n", dividend);
    if (dividend > largest) {largest = dividend;}
	return 1;
}

int PE5main (pe_data_t *pedata) {

	int check = 0;
	for (int test = 2; test <= UPPER_TEST; test+=2) {
		check = DivisorTest(test);
		if (check == 1) {break;}
	}
    if (pedata->verbosity > 0) printf("%i\n", largest);
    sprintf(pedata->result, "%i", largest);
    return 0;
}
