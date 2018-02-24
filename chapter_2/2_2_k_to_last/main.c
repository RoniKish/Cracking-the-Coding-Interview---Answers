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


// Start of solution
my_node *k_to_last(my_node * head, int k, int *pos)
{
	if (head == NULL)
		return NULL;
	my_node *current = k_to_last(head->next, k, pos);
	(*pos)++;
	if (k == *pos)
		return head;
	return current;
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
    // Creates linked list 1-5
	int i;
	for (i = 2; i<6; i++)
	{
		add_node_last(head, i);
	}
	print_list(head);

	int k;
	int pos = 0;
	printf("\nEnter the K node: ");
	scanf("%d", &k);
	printf("\nthe %d node value from last is: %d\n", k, k_to_last(head, k, &pos)->value);

	return 0;
}
