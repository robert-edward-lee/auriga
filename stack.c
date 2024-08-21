#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

Stack Stack_new(void) {
    stack_t *data;

    data = malloc(STACK_INIT_CAP * sizeof(stack_t));
    if(!data) {
        return (Stack){NULL, -1, -1};
    }

    return (Stack){data, 0, STACK_INIT_CAP};
}
void Stack_del(Stack *stack) {
    if(stack) {
        free(stack->data);
    }
}
bool Stack_push(Stack *stack, stack_t item) {
    stack_t *tmp;

    if(!stack || !stack->data) {
        return false;
    }

    if(stack->cap == stack->size) {
        tmp = realloc(stack->data, stack->cap * 2);
        if(!tmp) {
            return false;
        }
        stack->cap *= 2;
        stack->data = tmp;
    }

    stack->data[stack->size++] = item;
    return true;
}
stack_t Stack_pop(Stack *stack) {
    if(!stack || !stack->data || !stack->size) {
        return (stack_t){0};
    }

    return stack->data[stack->size--];
}
stack_t Stack_peek(const Stack *stack) {
    if(!stack || !stack->data || !stack->size) {
        return '\0';
    }
    return stack->data[stack->size - 1];
}
void Stack_print(const Stack *stack, print_f fn) {
    int i;

    if(!stack || !stack->data || !stack->size) {
        return;
    }

    printf("|- ");
    for(i = 0; i < stack->size; ++i) {
        fn(stack->data[i]);
    }
    printf("\n");
}
