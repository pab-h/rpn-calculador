#include "../headers/stack.h"

float convert_symbol_to_float(char symbol) {
    return (float)(symbol - '0');
}

int is_operation(char symbol) {
    return 
        symbol == '+' || 
        symbol == '-' || 
        symbol == '*' || 
        symbol == '/';
}

void handle_operation(stack* stack, char operation) {
    float result = 0.0;

    float first_poped_value = pop(stack);
    float second_poped_value = pop(stack);

    if (operation == '+') {
        result = second_poped_value + first_poped_value;
    }

    if (operation == '-') {
        result = second_poped_value - first_poped_value; 
    }

    if (operation == '*') {
        result = second_poped_value * first_poped_value;
    }

    if (operation == '/') {
        result = second_poped_value / first_poped_value;
    }

    push(stack, result);
}

int is_digit(char symbol) {
    return symbol >= '0' && symbol <= '9';
}

void handle_digit(stack* stack, char symbol) {
    float digit = convert_symbol_to_float(symbol);

    push(stack, digit);
}

void handle_symbol(stack* stack, char symbol) {
    if (symbol == ' ') {
        return;
    }

    if (is_digit(symbol)) {
        handle_digit(stack, symbol);

        return;
    }

    if (is_operation(symbol)) {
        handle_operation(stack, symbol);

        return;
    }

}

float solve_expression(char *expression) {
    stack* stack = create_stack();

    while (*expression != '\0') {

        handle_symbol(stack, *expression);

        expression = expression + 1;
    }

    float result = pop(stack);

    delete_stack(stack);

    return result;

}