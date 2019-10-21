#define _CRT_SECURE_NO_WARNINGS
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

// This function assume n does exist
void del_node(my_node ** n)
{
	my_node *buffer = NULL;
	buffer = (*n)->next;
	free(*n);
	*n = buffer;
}

int main()
{
	// Creates head node
	my_node *head = NULL;
	head = malloc(sizeof(my_node));
	if (head == NULL)
		return 1;
	head->value = 1;
	head->next = NULL;

	int i;
	for (i = 2; i<6; i++)
	{
		add_node_last(head, i);
	}
	print_list(head);
	printf("Test: %d\n", &(head->next->next->next));
	del_node(&(head->next->next->next));
	print_list(head);

	return 0;
}

