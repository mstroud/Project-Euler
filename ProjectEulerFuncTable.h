#include "ProjectEuler.h"

#ifndef __ProjectEulerFuncTableH
#define __ProjectEulerFuncTableH

// PE function pointer "jump table"
int (* const PE_func_table[NUM_PROBLEMS+1])(pe_data_t*) = {
    NULL,
    PE1main,
    PE2main,
    PE3main,
    NULL,
    PE5main
};

#endif
