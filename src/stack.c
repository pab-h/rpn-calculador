#include <stdlib.h>
#include "../headers/stack.h"

int is_empty(stack* stack) {
    return (*stack).head == NULL;
}

node* create_node(float value) {
    node* new_node = (node*) malloc(sizeof(node));

    (*new_node).value = value;
    (*new_node).next = NULL;

    return new_node;
}

stack* create_stack() {
    return (stack*) malloc(sizeof(stack));
}

void delete_stack(stack* stack) {
    if (is_empty(stack)) {
        free(stack);
        return;
    }

    node* current = (*stack).head;

    while(current) {
        node* tmp_node = current;
        current = (*current).next;
        free(tmp_node);
    }

    free(stack);

}

void push(stack* stack, float value) {
    node* new_node = create_node(value);

    if (is_empty(stack)) {
        (*stack).head = new_node;
        
        return;
    }

    (*new_node).next = (*stack).head;
    (*stack).head = new_node; 

}

float peek(stack* stack) {
    if (is_empty(stack)) {
        return 0;
    }

    return (*(*stack).head).value;
}

float pop(stack *stack) {
    if (is_empty(stack)) {
        return 0;
    }

    node* poped_node = (*stack).head;
    (*stack).head = (*poped_node).next;

    float poped_node_value = (*poped_node).value;

    free(poped_node);

    return poped_node_value;
}