#include "em.h"


// Executes the program in "prog"
void exec(int prog[1028]) {
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

            case JMP:
                i = prog[i + 1] - 1;
                i +=1 ;
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


void clear_input_buffer() {
    while (getchar() != '\n');
}


