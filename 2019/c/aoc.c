#include <stdio.h>
#include <stdlib.h>
#include "aoc.h"

void read_inputs_from_file(const char *path, int *input_buff, size_t input_size) {
    char inputs[input_size][20];

    FILE *fp = fopen(path, "r");

    if (fp == NULL) {
        printf("Fail!");
        exit(-1);
    }

    for (int i = 0; i < 100; i++) {
        fgets(inputs[i], 20, fp);
        input_buff[i] = atoi(inputs[i]);
    }

    fclose(fp);
}
