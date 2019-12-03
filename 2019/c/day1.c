#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "aoc.h"

int main() {
    int inputs[MAX_INPUTS];
    int total_fuel = 0;

    read_inputs_from_file("../inputs/day1.txt", inputs, MAX_INPUTS);

    for (int i = 0; i < MAX_INPUTS; i++) {
        double fuel_amount = floor((double)inputs[i] / 3.0) - 2;
        total_fuel += (int) fuel_amount;
    }

    printf("%d\n", total_fuel);

    return 0;
}