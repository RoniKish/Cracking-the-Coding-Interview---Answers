#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int top;
    int capacity;
    int *array;
} my_stack;

my_stack *createStack(int capacity)
{
    my_stack *stack = (my_stack *) malloc(sizeof(my_stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
    return stack;
}

int isEmpty(my_stack *stack)
{
    return stack->top == -1;
}

void push(my_stack *stack, int item)
{
// In case the stack is full
    if (stack->top == stack->capacity - 1)
    {
        printf("The stack is full, %d was not pushed\n", item);
        return;
    }
    else
        stack->array[++stack->top] = item;
        printf("%d pushed to stack\n", item);
}

int pull(my_stack *stack)
{
    if (isEmpty(stack))
    {
        printf("The stack is empty, nothing to pull\n");
        return 0;
    }
    printf("%d was pulled from stack\n", stack->array[stack->top]);
    return stack->array[stack->top--];
}

my_stack *sortStack(my_stack *stack_1, int capacity)
{
    my_stack *stack_2 = createStack(capacity);
    int bigest;
    while (!isEmpty(stack_1))
    {
        bigest = pull(stack_1);
        while (!isEmpty(stack_2) && stack_2->array[stack_2->top] > bigest)
            push(stack_1, pull(stack_2));
        push(stack_2, bigest);
    }

    return stack_2;
}

int main()
{
    int capacity;
    printf("Enter the stack capacity: ");
    scanf("%d", &capacity);
    my_stack *stack = createStack(capacity);

    push(stack, 4);
    push(stack, 7);
    push(stack, 3);
    push(stack, 12);
    push(stack, 6);
    stack = sortStack(stack, capacity);

    pull(stack);
    pull(stack);
    pull(stack);
    pull(stack);
    pull(stack);

    free(stack);
    return 0;
}
