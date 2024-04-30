#pragma once

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
#define JMP 9 // Jumps to program index
#define HLT -1 // Stops the program (even em)

void exec(int prog[MAX_SYS]);

void clear_input_buffer();
