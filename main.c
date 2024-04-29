#include <stdio.h>
#include <stdlib.h>

//#include "lang/lang.h" Coming soon

#define MAX_SYS 1028

char mem[MAX_SYS]; // Do not set automaticly
int prog[MAX_SYS]; // Program

int comparison = 0;

// Op codes
#define SET 0 // Set location in ram a value
#define ADD 1 // Add 2 values in ram
#define SUB 2 // Subtract 2 values in ram
#define DIV 3 // Divide 2 values in ram
#define MUL 4 // Multiply 2 values in ram
#define PRT 5 // Prints out a value
#define CEO 6 // Compares two values, then puts the result in comparison
#define JEO 7 // Jumps to line if CE is true
#define GST 8 // Gets terminal input from user and SETS it
#define HLT -1 // Stops the program (even em)

void exec(int prog[MAX_SYS]);

int main(int argc, char* argv) { // Program

    //char* source = readFile(argv[1]); // Read source file from second console parameter (Coming soon)


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

void clear_input_buffer() {
    while (getchar() != '\n');
}

// Executes the program in "prog"
void exec(int prog[MAX_SYS]) {
    for(int i = 0; i < MAX_SYS; i++)
    {
        switch (prog[i]) {
            case SET:
                mem[prog[i+1]] = prog[i+2];
                i += 2;
            break;
            
            case ADD:
                mem[prog[i + 1]] = mem[prog[i + 2]] + mem[prog[i + 3]];
                i += 3;
            break;

            case SUB:
                mem[prog[i + 1]] = mem[prog[i + 2]] - mem[prog[i + 3]];
                i += 3;
            break;

            case DIV:
                mem[prog[i + 1]] = mem[prog[i + 2]] / mem[prog[i + 3]];
                i += 3;
            break;

            case MUL:
                mem[prog[i + 1]] = mem[prog[i + 2]] * mem[prog[i + 3]];
                i += 3;
            break;

            case CEO:
                comparison = (mem[prog[i + 1]] == mem[prog[i + 2]]);
                i += 2;
            break;

            case JEO:
                // Jump to index if last comparison was true
                if (comparison) {
                    i = prog[i + 1] - 1; // -1 because the loop will increment i
                } else {
                    i += 1; // Skip the jump address
                }
            break;

            case PRT:
                printf("%i\n",mem[prog[i+1]]);
                i += 1;
            break;

            case GST:
            {
                int input;
                scanf("%d", &input);
                clear_input_buffer();
                mem[prog[i+1]] = input;
                i += 1;
                break;
            }

            case HLT:
                printf("Program and EM stopped.\n");
                exit(0); 
            break;
            default:
                printf("Whoops! That command does not exist at location %i\n", i);
            break;
        }
    }
}