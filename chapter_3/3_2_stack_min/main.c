#include <stdio.h>
#include <stdlib.h>


typedef struct stack
{
    int top;
    int capacity;
    int *array;
    int min_value;
} my_stack;

my_stack *create_stack(int capacity)
{
    my_stack *stack = (my_stack *) malloc(sizeof(my_stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *) malloc(capacity * sizeof(int));
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
// In case the stack is empty
    if (isEmpty(stack))
    {
        stack->array[++stack->top] = item;
        stack->min_value = item;
    }
// In case the stack is NOT empty
    else
    {
        if (stack->min_value > item)
        {
            stack->array[++stack->top] = 2 * item - stack->min_value;
            stack->min_value = item;
        }
        else
            stack->array[++stack->top] = item;
    }
    printf("%d pushed to stack\n", item);
}

int pull(my_stack *stack)
{
// In case the stack is empty
    if (isEmpty(stack))
    {
        printf("The stack is empty, nothing to pull\n");
        return 0;
    }
// In case the top element is less then min_value
    if (stack->array[stack->top] < stack->min_value)
    {
        printf("%d was pulled from stack\n", (stack->min_value + stack->array[stack->top--])/2);
        stack->min_value = 2 * stack->min_value - stack->array[stack->top];
        return (stack->min_value + stack->array[stack->top--])/2;
    }
// In case the top element is bigger or equal to min_value
    else
    {
        printf("%d was pulled from stack\n", stack->array[stack->top--]);
        return stack->array[stack->top--];
    }
}

int getMin(my_stack *stack)
{
    if (isEmpty(stack))
    {
        printf("The stack is empty no min value to return");
        return 0;
    }
    printf("The min value is: %d", stack->min_value);
    return stack->min_value;
}

int main()
{
    int capacity;
    printf("Enter the stack capacity: ");
    scanf("%d", &capacity);
    my_stack *stack = create_stack(capacity);

    push(stack, 5);
    push(stack, 8);
    push(stack, 3);
    push(stack, 11);
    pull(stack);
    getMin(stack);

    free(stack);
    return 0;
}
