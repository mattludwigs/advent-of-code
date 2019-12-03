#include <math.h>
#include <stdio.h>
#include "aoc.h"

int calc_fuel_needed(int fuel) {
    double r = floor((double)fuel / 3.0) - 2;

    if (r <= 0) {
        return 0;
    } else {
        return (int) r;
    }
}


int calc_total_fuel(int start_fuel) {
    int remaining_fuel = start_fuel;
    int total_fuel = 0;

    while (remaining_fuel) {
        remaining_fuel = calc_fuel_needed(remaining_fuel);
        total_fuel += remaining_fuel;
    }

    return total_fuel; 
}

int main(int argc, char **argv)
{
    int inputs[MAX_INPUTS];
    int total_fuel = 0;

    read_inputs_from_file("../inputs/day1.txt", inputs, MAX_INPUTS);

    for (int ix = 0; ix < MAX_INPUTS; ix++) {
        int needed_fuel = calc_total_fuel(inputs[ix]);

        total_fuel += needed_fuel;
    }

    printf("%d\n", total_fuel);
    return 0;
}