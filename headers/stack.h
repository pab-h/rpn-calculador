#ifndef STACK_HEADER

#define STACK_HEADER

typedef struct node {
    float value;
    struct node *next;
} node;

typedef struct stack {
    struct node *head;
} stack;

int is_empty(stack* stack);

node* create_node(float value);

stack* create_stack();

void delete_stack(stack* stack);

void push(stack* stack, float value);

float peek(stack* stack);

float pop(stack *stack);

#endif