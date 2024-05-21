#include "push_swap.h"



static void swap(t_node **header)
{
    if (ft_lstsize(*header) < 2)
        return;
    header = (*header)->next;
    (*header)->previous->previous = header;
    (*header)->previous->next = (*header)->next;
    if ((*header)->next != NULL)
        (*header)->next->previous = (*header)->previous;
    (*header)->next = (*header)->previous;
    (*header)->previous = NULL;

}

static void stack_push(t_node **a_header, t_node **b_header) 
{
    t_node *temp;

    if (ft_lstsize(*a_header) == 0) 
        return;
   temp = *a_header;
    *a_header = (*a_header)->next; //parenthesis because first *a_header, then go to next
    if (*a_header != NULL) 
        (*a_header)->previous = NULL; // If there's a next node, set its previous to NULL
    if (ft_lstsize(*b_header) == 0) 
    {
        *b_header = temp;
        (*b_header)->next = NULL;
        (*b_header)->previous = NULL;
    } 
    else 
    {
        temp->next = *b_header;
        temp->previous = NULL;
        (*b_header)->previous = temp;
        *b_header = temp;
    }
}

static void rotate(t_node **header)
{
    t_node *last;

    if (*header == NULL || (*header)->next == NULL) 
        return; 
    last = ft_lstlast(*header);
    last->next = *header;
    (*header)->previous = last;
    (*header)->next = NULL;
    *header = last->previous;
    (*header)->previous = NULL;
}

static void reverse_rotate(t_node **header)
{
t_node	*last;

if (*header == NULL || (*header)->next == NULL) 
    return;
last = ft_lstlast(*header);
last->previous->next = NULL;
last->next = *header;
last->previous = NULL;
*header = last;
last->next->previous = last;
}

int main(void)
{
    t_node *header;

    t_node *a =malloc(sizeof(t_node));
    t_node *b =malloc(sizeof(t_node));
    t_node *c =malloc(sizeof(t_node));



    if (a == NULL || b == NULL || c == NULL)
        return 1;

    header = a;
    a->value = 7;
    a->next = b;
    a->previous = NULL;

    b->value = 70;
    b->next = c;
    b->previous = a;

    c->value = 700;
    c->next = NULL;
    c->previous = b;
    rotate(&header);
}


/* SWAP int main (void)
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
} */