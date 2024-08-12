#ifndef H_STACK
#define H_STACK

#ifndef STACK_INIT_CAP
#define STACK_INIT_CAP 8
#endif /* STACK_INIT_CAP */

#ifndef STACK_TYPE
#define STACK_TYPE char
#endif /* STACK_TYPE */

typedef STACK_TYPE stack_t;
typedef struct {
    char *data;
    int size;
    int cap;
} Stack;
typedef void (*print_f)(stack_t);

Stack Stack_new(void);
void Stack_del(Stack *stack);
bool Stack_push(Stack *stack, stack_t item);
stack_t Stack_pop(Stack *stack);
stack_t Stack_peek(const Stack *stack);
void Stack_print(const Stack *stack, print_f fn);

#endif /* H_STACK */
