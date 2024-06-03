#include "push_swap.h"

//might need to be more explicit
void	operate(t_dlist **stack_header, t_dlist *to_move, char *stack)
{
	while (*stack_header != to_move)
	{
		if (to_move->top_half == 1)
			rotate(stack_header, ft_strjoin("r", stack)); //valgrind leaks
		else	
			reverse_rotate(stack_header, ft_strjoin("rr",stack));	//valgrind leaks
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
	//printfs		
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