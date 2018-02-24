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

int main()
{
    int capacity;
    printf("Enter the stack capacity: ");
    scanf("%d", &capacity);
    my_stack *stack = createStack(capacity);

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    pull(stack);

    return 0;
}
