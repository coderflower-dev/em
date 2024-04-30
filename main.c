#include <stdio.h>
#include <stdlib.h>

#include "em/em.h"

int main(int argc, char* argv) { // Program


    prog[0] = GST; // Enable set
    prog[1] = 0; // Location in ram

    prog[2] = SET; // Enable set
    prog[3] = 1; // Location in ram
    prog[4] = 5; // Value

    prog[5] = SUB;
    prog[6] = 2; // Result location
    prog[7] = 0; // Mem loc 1
    prog[8] = 1; // Mem loc 2
    
    prog[9] = CEO;
    prog[10] = 2; // First check
    prog[11] = 1; // Second check

    prog[12] = JEO;
    prog[13] = 15;

    prog[14] = HLT;

    prog[15] = PRT;
    prog[16] = 0;

    exec(prog);
}
