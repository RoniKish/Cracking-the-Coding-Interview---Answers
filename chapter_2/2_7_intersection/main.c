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

my_node *intersection_node(my_node *head1, my_node *head2)
{
// Getting head1, head2 size and last node
    int i;
    int list_size_1 = 1, list_size_2 = 1;
    my_node *current_1 = head1;
    my_node *current_2 = head2;
    while (current_1->next != NULL && current_2->next != NULL)
    {
        current_1 = current_1->next;
        current_2 = current_2->next;
        list_size_1++;
        list_size_2++;
    }
    while (current_1->next != NULL)
    {
        current_1 = current_1->next;
        list_size_1++;
    }
    while (current_2->next != NULL)
    {
        current_2 = current_2->next;
        list_size_2++;
    }
// Comparing the last nodes of both lists
    if ((int) current_1 != (int) current_2)
        return NULL;
// Finding the intersect node
    current_1 = head1;
    current_2 = head2;
    if (list_size_1 > list_size_2)
    {
        for(i=0;i<(list_size_1-list_size_2);i++)
            current_1 = current_1->next;
    }
    else
        for(i=0;i<(list_size_2-list_size_1);i++)
            current_2 = current_2->next;
    while ((int) current_1 != (int) current_2)
    {
        current_1 = current_1->next;
        current_2 = current_2->next;
    }

    return current_1;
}

void make_intersection(my_node *head1, my_node *head2)
{
    add_node_last(head1, 3);
    add_node_last(head1, 5);
    add_node_last(head1, 7);
    add_node_last(head1, 9);
    add_node_last(head2, 6);
    my_node *current = head1;
    current = current->next->next->next;
    head2->next->next = current;

    printf("the first list is:");
    print_list(head1);
    printf("\nthe the second list is:");
    print_list(head2);

}

int main()
{
// Creates head1 head2 nodes
	my_node *head1 = NULL;
	head1 = malloc(sizeof(my_node));
	head1->value = 1;
	head1->next = NULL;
    my_node *head2 = NULL;
	head2 = malloc(sizeof(my_node));
	head2->value = 4;
	head2->next = NULL;
// Creating 2 lists that intersect
    make_intersection(head1, head2);

	my_node *inter_node = NULL;
	inter_node = intersection_node(head1, head2);
// Prints the results
	if(intersection_node(head1, head2) == NULL)
        printf("\nThere is no intersection node\n");
    else
        printf("\nThe intersection node value is %d\n",inter_node->value);

	return 0;
}

