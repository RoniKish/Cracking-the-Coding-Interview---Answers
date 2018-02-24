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

void pertition(my_node *head, int x)
{
    my_node *current = head;
    // Creating two linked lists
    my_node *lower_list = NULL;
    lower_list = malloc(sizeof(my_node));
    lower_list->next = NULL;
    my_node *upper_list = NULL;
    upper_list = malloc(sizeof(my_node));
    upper_list->next = NULL;
    // Passing the values to the lists
    while(current != NULL)
    {
        if(current->value < x)
            add_node_last(lower_list, current->value);
        else
            add_node_last(upper_list, current->value);
        current = current->next;
    }
    // Removing the first values from the lists (NULL)
    pop_first(&lower_list);
    pop_first(&upper_list);
    // Merging the lists
    my_node *temp_node = lower_list;
    while (temp_node->next != NULL)
    {
        temp_node = temp_node->next;
    }
    temp_node->next=upper_list;

    print_list(lower_list);
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

	int i,x;
	for(i=-3;i<4;i++)
	{
	    add_node_last(head, (i*i));
	}
	print_list(head);
	printf("Enter the number u want to split the list from: ");
	scanf("%d", &x);
	pertition(head, x);

	return 0;
}

