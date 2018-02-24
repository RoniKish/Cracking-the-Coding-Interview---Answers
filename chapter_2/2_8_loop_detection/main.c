#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
	int value;
	struct node *next;
} my_node;

void print_list(my_node *head)
{
    printf("\n");
	my_node *current = head;
	while (current != NULL)
	{
		printf("The value is: %d \n", current->value);
		current = current->next;
	}
}

void add_node_last(my_node *head, int value)
{
	my_node *current = head;
	while (current->next != NULL)
	{
		current = current->next;
	}

	current->next = malloc(sizeof(my_node));
	current->next->value = value;
	current->next->next = NULL;
}

my_node *loop_detect(my_node *head)
{
    int move_counter = 0;
    my_node *slow_runner = head;
    my_node *fast_runner = head;
// Runs the 2 runners till they meet at the same node
    while ( fast_runner != NULL && fast_runner->next != NULL)
    {
        move_counter++;
        slow_runner = slow_runner->next;
        fast_runner = fast_runner->next->next;
        printf("Values for %d move: slow - %d  fast - %d\n", move_counter, slow_runner->value, fast_runner->value);
        if ((int) fast_runner == (int) slow_runner)
            break;
    }
// In case the list is not a loop
    if (fast_runner == NULL || fast_runner->next == NULL)
        return NULL;

    printf("The runners met at node number: %d\n", fast_runner->value);
// The runners will meet at the loop starting node
    slow_runner = head;
    while ((int) slow_runner != (int) fast_runner)
    {
        slow_runner = slow_runner->next;
        fast_runner = fast_runner->next;
    }
    return slow_runner;
}

void make_loop_list(my_node *head)
{
    int i;
    for(i=2;i<8;i++)
        add_node_last(head,i);
    print_list(head);
	my_node *current = head;
	while (current->next != NULL)
		current = current->next;
	current->next = head->next->next;
	printf("the value is: %d\n\n", current->next->value);
}

int main()
{
// Creates head node
	my_node *head = NULL;
	head = malloc(sizeof(my_node));
	head->value = 1;
	head->next = NULL;

// Creating a list that loops
    make_loop_list(head);
// Finding the starting node of the loop
	my_node *loop_node = NULL;
	loop_node = loop_detect(head);
	if (loop_node == NULL)
    {
        printf("\nThe list is not a loop list\n");
        return 0;
    }
    else
        printf("\nThe loop starting node value is: %d\n", loop_node->value);
	return 0;
}
