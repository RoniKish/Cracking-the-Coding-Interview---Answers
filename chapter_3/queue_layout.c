#include <stdio.h>
#include <stdlib.h>


typedef struct queue
{
	int size, front, rear;
	int capacity;
	int *array;
} my_queue;

my_queue *createQueue(int capacity)
{
	my_queue *queue = (my_queue *)malloc(sizeof(my_queue));
	queue->capacity = capacity;
	queue->front = queue->size = 0;
	queue->rear = capacity - 1;
	queue->array = (int *)malloc(capacity * sizeof(int));
	return queue;
}

int isEmpty(my_queue *queue)
{
	return (queue->size == 0);
}

void push(my_queue *queue, int item)
{
	if (queue->size == queue->capacity)
	{
		printf("The queue is full, did no insert %d\n", item);
		return;
	}
	queue->rear = (queue->rear + 1) % queue->capacity;
	queue->array[queue->rear] = item;
	queue->size = queue->size + 1;
	printf("%d entered the queue\n", item);
}

int pull(my_queue *queue)
{
	if (isEmpty(queue))
	{
		printf("The queue is empty, there is nothing to pull\n");
		return 0;
	}
	else
	{
		int item = queue->array[queue->front];
		queue->front = (queue->front + 1) % queue->capacity;
		queue->size = queue->size - 1;
		printf("%d came out of queue\n", item);
		return item;
	}

}

int front(my_queue *queue)
{
	if (isEmpty(queue))
	{
		printf("The queue is empty, there is no front item\n");
		return 0;
	}
	else
	{
		printf("Front item is %d\n", queue->front);
		return queue->array[queue->front];
	}
}

int rear(my_queue *queue)
{
	if (isEmpty(queue))
	{
		printf("The queue is empty, there is no rear item\n");
		return 0;
	}
	printf("Rear item is %d\n", queue->array[queue->rear]);
	return queue->array[queue->rear];
}

int main()
{
	int size;
	printf("Enter the size of the queue: ");
	scanf("%d", &size);
	my_queue *queue = createQueue(size);

	push(queue, 10);
	push(queue, 20);
	pull(queue);
	pull(queue);
	pull(queue);

	front(queue);
	rear(queue);

	return 0;
}
