#include <stdlib.h>
#include <stdio.h>
#include <time.h>

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

my_node *sum_lists(my_node *head1, my_node *head2)
{
    if(head1 == NULL)
        return head2;
    if(head2 == NULL)
        return head1;

    my_node *sum_head, *new_head, *prev_node;
    int carry = 0;
    int index = 0;
    int sum;
// both heads are not in the end
    while(head1 && head2)
    {
        sum = head1->value + head2->value + carry;
        carry = sum / 10;
        sum = sum % 10;
        if(index == 0)
        {
            sum_head = (my_node *)malloc(sizeof(my_node));
			sum_head->value = sum;
			sum_head->next = NULL;
			prev_node = sum_head;
			index++;
        }
        else
        {
            new_head = (my_node *)malloc(sizeof(my_node));
			new_head->value = sum;
			new_head->next = NULL;
			prev_node->next = new_head;
			prev_node = new_head;
        }
        head1 = head1->next;
		head2 = head2->next;
    }
// end of head 2 list
    	while (head1)
    	{
            sum = head1->value + carry;
            carry = sum / 10;
            sum %= 10;
            new_head = (my_node *)malloc(sizeof(my_node));
            new_head->value = sum;
            new_head->next = NULL;
            prev_node->next = new_head;
            prev_node = new_head;
            head1 = head1->next;
        }
// end of head 1 list
	while (head2)
    {
        sum = head2->value + carry;
        carry = sum / 10;
        sum %= 10;
        new_head = (my_node *)malloc(sizeof(my_node));
        new_head->value = sum;
        new_head->next = NULL;
        prev_node->next = new_head;
        prev_node = new_head;
        head2 = head2->next;
	}
// in case sum > 10 (carry = 1)
	if (carry)
	{
		new_head = (my_node *)malloc(sizeof(my_node));
		new_head->value = carry;
		new_head->next = NULL;
		prev_node->next = new_head;
	}
	return sum_head;
}

int main()
{
// Creates 2 heads nodes
	my_node *head1 = NULL;
    my_node *head2 = NULL;
	head1 = malloc(sizeof(my_node));
	head1->value = rand()%10;
	head1->next = NULL;
    head2 = malloc(sizeof(my_node));
    head2->value = rand()%10;
	head2->next = NULL;
// insert more nodes to the lists to represent a number
	int i;
	srand((unsigned) time(NULL));
	for(i=0;i<3;i++)
	{
	    add_node_last(head1, rand()%10);
        add_node_last(head2, rand()%10);
	}
	print_list(head1);
	print_list(head2);
	print_list(sum_lists(head1, head2));

	return 0;
}

