#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int *array;
    int capacity_1;
    int capacity_2;
    int capacity_3;
    int top_1;
    int top_2;
    int top_3;
} my_stack;

my_stack *createStack_3in1(int capacity_1, int capacity_2, int capacity_3)
{
    int capacity_sum = capacity_1 + capacity_2 + capacity_3;
    my_stack *stack = (my_stack *) malloc(sizeof(my_stack));
    stack->capacity_1 = capacity_1;
    stack->capacity_2 = capacity_2;
    stack->capacity_3 = capacity_3;
    stack->top_1 = -1;
    stack->top_2 = -1;
    stack->top_3 = -1;
    stack->array = (int*) malloc(capacity_sum * sizeof(int));
    return stack;
}
// Checking if stack is empty depending on stack number
int isEmpty(my_stack *stack, int stack_num)
{
    if(stack_num == 1)
        return (stack->top_1 == -1);
    if(stack_num == 2)
        return (stack->top_2 == -1);
    if(stack_num == 3)
        return (stack->top_3 == -1);
    return 0;
}
// Checking if stack is full depending on stack number
int isFull(my_stack *stack, int stack_num)
{
    if(stack_num == 1)
        return (stack->top_1 == stack->capacity_1 - 1);
    if(stack_num == 2)
        return (stack->top_2 == stack->capacity_2 - 1);
    if(stack_num == 3)
        return (stack->top_3 == stack->capacity_3 - 1);
    return 0;
}
// Push item into stack depending on stack number
void push(my_stack *stack,int stack_num, int item)
{
// In case the stack is full
    if (isFull(stack, stack_num))
    {
        printf("The stack is full, %d was not pushed\n", item);
        return;
    }
    if (stack_num == 1)
    {
        stack->array[++stack->top_1] = item;
        printf("%d was pushed to stack %d\n", item, stack_num);
    }
    if (stack_num == 2)
    {
        stack->array[(++stack->top_2) + stack->capacity_1] = item;
        printf("%d was pushed to stack %d\n", item, stack_num);
    }
    if (stack_num == 3)
    {
        stack->array[(++stack->top_3) + stack->capacity_2] = item;
        printf("%d was pushed to stack %d\n", item, stack_num);
    }
}

int pull(my_stack *stack, int stack_num)
{
    if (isEmpty(stack, stack_num))
    {
        printf("The stack is empty, nothing to pull\n");
        return 0;
    }
    else
    {
        if (stack_num == 1)
        {
            printf("%d was pulled from stack %d\n", stack->array[stack->top_1], stack_num);
            return stack->array[stack->top_1--];
        }
        if (stack_num == 2)
        {
            printf("%d was pulled from stack %d\n", stack->array[stack->top_2], stack_num);
            return stack->array[(stack->top_2--) + stack->capacity_1];
        }
        if (stack_num == 3)
        {
            printf("%d was pulled from stack %d\n", stack->array[stack->top_3], stack_num);
            return stack->array[(stack->top_3--) + stack->capacity_2];
        }
    }
    return 0;
}

int main()
{
// Enters the 3 stacks capacity
    int capacity_1,capacity_2,capacity_3;
    printf("Enter stack 1 capacity: ");
    scanf("%d", &capacity_1);
    printf("Enter stack 2 capacity: ");
    scanf("%d", &capacity_2);
    printf("Enter stack 3 capacity: ");
    scanf("%d", &capacity_3);
// Creates the 3 stacks using 1 array;
    my_stack *stack = createStack_3in1(capacity_1,capacity_2,capacity_3);
// Testing the commands
    push(stack, 1, 10);
    push(stack, 2, 30);
    push(stack, 1, 40);
    pull(stack, 1);

    return 0;
}
