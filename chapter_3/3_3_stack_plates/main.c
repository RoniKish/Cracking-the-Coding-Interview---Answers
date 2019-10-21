#include <stdio.h>
#include <stdlib.h>


typedef struct stack
{
    int top;
    int *array;
} my_stack;

typedef struct SetOfStacks
{
    my_stack *stacks_array;
    int current_stack;
    int threshold;
    int capacity;
} my_SetOfStacks;

my_SetOfStacks *createSetOfStacks(int capacity, int threshold)
{
    my_SetOfStacks *StackSet = (my_SetOfStacks *) malloc(sizeof(my_SetOfStacks));
    StackSet->current_stack = 0;
    StackSet->threshold = threshold;
    // Stack creation
    StackSet->stacks_array = (my_stack *) malloc(sizeof(my_stack));
    StackSet->capacity = capacity;
    StackSet->stacks_array->top = -1;
    StackSet->stacks_array->array = (int*) malloc(capacity * sizeof(int));
    return StackSet;
}

int isEmpty(my_SetOfStacks *StackSet)
{
    return StackSet->stacks_array[StackSet->current_stack].top == -1;
}

void push(my_SetOfStacks *StackSet, int item)
{
// In case the stack is full
    if (StackSet->stacks_array->top == StackSet->capacity - 1)
    {
        printf("The stack has reached the threshold, a new stack was created\n");
        StackSet->stacks_array = (my_stack *) realloc(StackSet->stacks_array, (++StackSet->current_stack + 1) * sizeof(my_stack));
        StackSet->stacks_array[StackSet->current_stack].top = -1;
        StackSet->stacks_array[StackSet->current_stack].array[++StackSet->stacks_array[StackSet->current_stack].top] = item;
    }
    else
        StackSet->stacks_array[StackSet->current_stack].array[++StackSet->stacks_array[StackSet->current_stack].top] = item;
    printf("%d was pushed to stack\n", item);
}

int pull(my_SetOfStacks *StackSet)
{
    if (isEmpty(StackSet))
    {
        if (StackSet->current_stack == 0)
        {
        printf("The set of stacks is empty, nothing to pull\n");
        return 0;
        }
        else
        {
            StackSet->current_stack--;
            printf("%d was pulled from stack\n", StackSet->stacks_array[StackSet->current_stack].array[StackSet->stacks_array[StackSet->current_stack].top]);
            return StackSet->stacks_array[StackSet->current_stack].array[StackSet->stacks_array[StackSet->current_stack].top--];
        }
    }
    printf("%d was pulled from stack\n", StackSet->stacks_array[StackSet->current_stack].array[StackSet->stacks_array[StackSet->current_stack].top]);
    return StackSet->stacks_array[StackSet->current_stack].array[StackSet->stacks_array[StackSet->current_stack].top--];
}

int main()
{
    int capacity, threshold;
    printf("Enter the stack capacity: ");
    scanf("%d", &capacity);
    printf("Enter the set of stacks threshold: ");
    scanf("%d", &threshold);
    my_SetOfStacks *my_set = createSetOfStacks(capacity, threshold);

    push(my_set, 10);
    push(my_set, 20);
    push(my_set, 30);
    pull(my_set);

    free(my_set);
    return 0;
}
