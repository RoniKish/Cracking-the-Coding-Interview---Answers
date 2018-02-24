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
void remove_dups(my_node ** head)
{
    int list_hush[20] = {0};
    my_node *current = *head;
    my_node *buffer = NULL;
    while(current->next != NULL)
    {
        if(list_hush[current->next->value] == 1)
        {
            buffer = current->next->next;
			free(current->next);
			current->next = buffer;
        }
        else
        {
            list_hush[current->value]++;
            current = current->next;
        }
    }
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
// Creates linked list with duplicates
    int i;
	for (i=2;i<6;i++)
    {
        add_node_last(head, i);
        add_node_last(head, 4);
    }

    print_list(head);
    remove_dups(&head);
    print_list(head);
	return 0;
}

