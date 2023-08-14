#include <stdio.h>

#include "headers/rpn.h"

int main(int argc, char* args[]) {

    if (argc != 2) {
        printf("You only need parser the expression in Reverse Polish Notation!\n");
        printf("About Reverse Polish Notation: https://en.wikipedia.org/wiki/Reverse_Polish_notation\n");

        return 1;
    }

    char* expression = args[1];
    float result = solve_expression(expression);

    printf("Your expression: %s\n", expression);
    printf("Result: %f\n", result);

    return 0; 
}