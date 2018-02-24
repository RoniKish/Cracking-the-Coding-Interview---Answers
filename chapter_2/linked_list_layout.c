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

void add_node_first(my_node **head, int value)
{
	my_node *new_node;
	new_node = malloc(sizeof(my_node));
	new_node->value = value;
	new_node->next = *head;
	*head = new_node;
}
// Use pop_first(&head) when popping first -- "&"!!!!
int pop_first(my_node ** head)
{
    int pop_value = 0;
	my_node *new_head = NULL;
	// No more nods
	if (*head == NULL)
		return pop_value;
	new_head = (*head)->next;
	pop_value = (*head)->value;
	free(*head);
	*head = new_head;
	return pop_value;
}

int pop_last(my_node * head)
{
    int pop_value = 0;
    // Deletes the linked list if only 1 item left
    if(head->next == NULL)
    {
        pop_value = head->value;
        free(head);
        return pop_value;
    }

    my_node *current = head;
    // Runs to last node in list
    while (current->next->next != NULL)
    {
        current = current->next;
    }
    pop_value = current->next->value;
    free(current->next);
    current->next = NULL;
    return pop_value;
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

	return 0;
}

