#include "push_swap.h"

/*check for the largest value, move to bottom
check for new largest, move to bottom 
*/
void three_nodes(t_dlist **header) 
{
    t_dlist *largest;
    
    largest = largest_node(*header);
    if (*header == largest)
        rotate(header, "ra");
    else if ((*header)->next == largest)
        reverse_rotate(header, "rra");
    if((*header)->value > (*header)->next->value)
        swap(header, "sa");
}

void operate(t_dlist **stack_header, t_dlist *to_move, char *stack)
{
    char *operation;

    while (*stack_header != to_move)
    {
        if (to_move->top_half == 1)
        {
            operation = ft_strjoin("r", stack);
            rotate(stack_header, operation);
            free(operation);
        }
        else
        {
            operation = ft_strjoin("rr", stack);
            reverse_rotate(stack_header, operation);
            free(operation);
        }
    }
}


void execute_moves(t_dlist **a, t_dlist **b)
{
	t_dlist *to_move;

	to_move = return_min_cost(*b);
	if (to_move->top_half == 1 && to_move->bonded_node->top_half == 1)
	{
		while(*a != to_move->bonded_node && *b != to_move)
			double_moves(a, b, "rr");
	}
	else if (to_move->top_half == 0 && to_move->bonded_node->top_half == 0)
	{
		//printf("a value is: %i, to_move->bonded_node value is: %i, to_move value is: %i, b value is: %i\n", 
		//(*a)->value, to_move->bonded_node->value, to_move->value, (*b)->value);
		while(*a != to_move->bonded_node && *b != to_move)
		{
			double_moves(a, b, "rrr");
			//printf("a value is: %i, to_move->bonded_node value is: %i, to_move value is: %i, b value is: %i\n", 
			//(*a)->value, to_move->bonded_node->value, to_move->value, (*b)->value);
		}
	}
	get_index(*a);
	get_index(*b); // dudas de si me ayuda en algo
	operate(b, to_move, "b");
	operate(a, to_move->bonded_node, "a");
	stack_push(b, a, "pa");
}

void	push_swap(t_dlist **a, t_dlist **b)
{
	t_dlist	*min;
	int				size_a;

	size_a = ft_dlstsize(*a);
	while (size_a-- > 3)
		stack_push(a, b, "pb");
	three_nodes(a);
	while (*b != NULL)
	{
		set_node_data(*a, *b);
		execute_moves(a, b);
	}
	get_index(*a); 
	min = min_node(*a);
	if (min->top_half == 1)
		while (*a != min)
		{
			rotate(a, "ra");
		}
	else
		while (*a != min)
			reverse_rotate(a, "rra");
}