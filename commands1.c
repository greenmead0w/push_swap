#include "push_swap.h"

void swap(t_dlist **header, char *command)
{
    if (ft_dlstsize(*header) < 2)
        return;
    *header = (*header)->next;
    (*header)->previous->previous = *header;
    (*header)->previous->next = (*header)->next;
    if ((*header)->next != NULL)
        (*header)->next->previous = (*header)->previous;
    (*header)->next = (*header)->previous;
    (*header)->previous = NULL;
    ft_printf("%s\n", command);

}
//push a_header on top of b_header
void stack_push(t_dlist **a_header, t_dlist **b_header, char *command) 
{
    t_dlist *temp;

    if (ft_dlstsize(*a_header) == 0) 
        return;
   temp = *a_header;
    *a_header = (*a_header)->next; //parenthesis because first *a_header, then go to next
    if (*a_header != NULL) 
        (*a_header)->previous = NULL; // If there's a next node, set its previous to NULL
    if (ft_dlstsize(*b_header) == 0) 
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
    ft_printf("%s\n", command);
}

void rotate(t_dlist **header, char *command)
{
	t_dlist	*last;
	int				size;

	size = ft_dlstsize(*header);
	if (header == NULL|| *header == NULL || size == 1)
		return ;
	last = ft_dlstlast(*header);
	last->next = *header;
	*header = (*header)->next;
	(*header)->previous = NULL;
	last->next->previous = last;
	last->next->next = NULL;
    if (command != NULL)
    {
        ft_printf("%s\n", command);
        ft_printf("bug\n");
    }

}

void reverse_rotate(t_dlist **header, char *command)
{
    t_dlist	*last;
    if (*header == NULL || (*header)->next == NULL)
        return;
    last = ft_dlstlast(*header);
    last->previous->next = NULL;
    last->next = *header;
    last->previous = NULL;
    *header = last;
    last->next->previous = last;
    if (command != NULL)
    {
        ft_printf("%s\n", command);
        ft_printf("bug\n");
    }
}

void double_moves(t_dlist **header_a, t_dlist **header_b, char *command)
{
    if (ft_strncmp(command, "rr", 2) == 0)
    {
        rotate(header_a, NULL); //duda efecto pasar argumento null
        rotate(header_b, NULL);
        ft_printf("%s\n", command);
    }
    else
    {
        reverse_rotate(header_a, NULL); //duda efecto pasar argumento null
        reverse_rotate(header_b, NULL);
        ft_printf("%s\n", command);
    }
}

