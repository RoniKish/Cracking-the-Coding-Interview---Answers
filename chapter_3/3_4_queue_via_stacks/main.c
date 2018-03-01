#include <stdio.h>
#include <stdlib.h>


typedef struct stack
{
    int top;
    int *array;
} my_stack;

typedef struct queue_via_stacks
{
    my_stack *stack_1;
    my_stack *stack_2;
    int capacity;
} my_queue;

my_queue *createQueue(int capacity)
{
    my_queue *queue_main = (my_queue *) malloc(sizeof(my_queue));
    queue_main->capacity = capacity;
    queue_main->stack_1 = (my_stack *) malloc(sizeof(my_stack));
    queue_main->stack_2 = (my_stack *) malloc(sizeof(my_stack));
    queue_main->stack_1->top = -1;
    queue_main->stack_2->top = -1;
    queue_main->stack_1->array = (int*) malloc(capacity * sizeof(int));
    queue_main->stack_2->array = (int*) malloc(capacity * sizeof(int));
    return queue_main;
}

void push(my_queue *queue, int item)
{
// In case the stack is full
    if (queue->stack_1->top == queue->capacity - 1)
    {
        printf("The queue is full, %d was not pushed\n", item);
        return;
    }
    else
    {
// transfer all to stack 2
      while (queue->stack_1->top != -1)
          queue->stack_2->array[++queue->stack_2->top] = queue->stack_1->array[queue->stack_1->top--];
// enter the new item to stack 1
      queue->stack_1->array[++queue->stack_1->top] = item;
// transfer all to stack 1
      while (queue->stack_2->top != -1)
          queue->stack_1->array[++queue->stack_1->top] = queue->stack_2->array[queue->stack_2->top--];
    }
        printf("%d was pushed to the queue\n", item);
}

int pull(my_queue *queue)
{
    if (queue->stack_1->top == -1)
    {
        printf("The stack is empty, nothing to pull\n");
        return 0;
    }
    printf("%d was pulled from stack\n", queue->stack_1->array[queue->stack_1->top]);
    return queue->stack_1->array[queue->stack_1->top--];
}

int main()
{
    int capacity;
    printf("Enter the stack capacity: ");
    scanf("%d", &capacity);
    my_queue *queue_main = createQueue(capacity);

    push(queue_main,5);
    push(queue_main,10);
    push(queue_main,15);
    pull(queue_main);

    free(queue_main);
    return 0;
}
