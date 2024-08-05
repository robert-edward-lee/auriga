#ifndef H_STACK
#define H_STACK

#ifndef STACK_INIT_CAP
#define STACK_INIT_CAP 8
#endif /* STACK_INIT_CAP */

typedef struct  {
    char *data;
    int size;
    int cap;
} Stack;

Stack Stack_new(void);
void Stack_del(Stack *stack);
bool Stack_push(Stack *stack, char parens);
char Stack_pop(Stack *stack);
char Stack_peek(const Stack *stack);
void Stack_print(const Stack *stack);

#endif /* H_STACK */
