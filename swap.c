#include "push_swap.h"


/*swap 

head

*/

//sa

//sb

//ss

typedef struct s_node
{
	int					value;
	struct s_node	*next;
	struct s_node	*previous;
}				t_node;	



static void swap(t_node *head)
{
    head = head->next;
    head->previous->previous = head;
    head->previous->next = head->next;
    head->next->previous = head->previous;
    head->next = head->previous;
    head->previous = NULL;

}

int main (void)
{
    t_node *head = NULL;

    t_node a;
    t_node b;
    t_node c;

    head = &a;

    a.value = 1;
    b.value = 2;
    c.value = 3;

    a.next = &b;
    a.previous = NULL;
    b.next = &c;
    b.previous = &a;
    c.next = NULL;
    c.previous = &b;
    swap(head);
}