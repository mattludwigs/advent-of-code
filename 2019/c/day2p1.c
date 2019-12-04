#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add(const int ip, int *program)
{
    int v1i = program[ip + 1];
    int v2i = program[ip + 2];
    int ri = program[ip + 3];

    program[ri] = program[v1i] + program[v2i];
}

void mult(const int ip, int *program)
{
    int v1i = program[ip + 1];
    int v2i = program[ip + 2];
    int ri = program[ip + 3];

    program[ri] = program[v1i] * program[v2i];
}

int read_program(int *program)
{
    char pstring[] = "1,12,2,3,1,1,2,3,1,3,4,3,1,5,0,3,2,1,13,19,1,9,19,23,2,13,23,27,2,27,13,31,2,31,10,35,1,6,35,39,1,5,39,43,1,10,43,47,1,5,47,51,1,13,51,55,2,55,9,59,1,6,59,63,1,13,63,67,1,6,67,71,1,71,10,75,2,13,75,79,1,5,79,83,2,83,6,87,1,6,87,91,1,91,13,95,1,95,13,99,2,99,13,103,1,103,5,107,2,107,10,111,1,5,111,115,1,2,115,119,1,119,6,0,99,2,0,14,0";
    // char pstring[] = "1,0,0,3,1,1,2,3,1,3,4,3,1,5,0,3,2,1,13,19,1,9,19,23,2,13,23,27,2,27,13,31,2,31,10,35,1,6,35,39,1,5,39,43,1,10,43,47,1,5,47,51,1,13,51,55,2,55,9,59,1,6,59,63,1,13,63,67,1,6,67,71,1,71,10,75,2,13,75,79,1,5,79,83,2,83,6,87,1,6,87,91,1,91,13,95,1,95,13,99,2,99,13,103,1,103,5,107,2,107,10,111,1,5,111,115,1,2,115,119,1,119,6,0,99,2,0,14,0";
    char *token = strtok(pstring, ",");
    int program_index = 0;

    while (token != NULL)
    {
        program[program_index] = atoi(token);
        token = strtok(NULL, ",");
        program_index += 1;
    }

    return program_index;
}

int main(int argc, char **argv)
{
    int program[500];
    memset(program, 0, 500);

    int sizeof_program = read_program(program);

    int ip = 0;
    int running = 1;

    while (running) {
        switch (program[ip]) {
            case 1:
                add(ip, program);
                ip += 4;
                break;
            case 2:
                mult(ip, program);
                ip += 4;
                break;
            case 99:
                running = 0;
                break;
        }
    }

    printf("%d\n", program[0]);

    return 0;
}
