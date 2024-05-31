#include "push_swap.h"

//might need to be more explicit
void	operate(t_dlist **stack_header, t_dlist *to_move, char *stack)
{
	while (*stack_header != to_move)
	{
		if (to_move->top_half == 1)
			rotate(stack_header, ft_strjoin("r", stack)); 
		else	
			reverse_rotate(stack_header, ft_strjoin("rr",stack));	
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
		while(*a != to_move->bonded_node && *b != to_move)
			double_moves(a, b, "rrr");
	}
	//get_index(*a);
	//get_index(*b); // dudas de si me ayuda en algo
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
	//ft_printf("hello2\n");
	//at this point stack is ordered, but min_element might not be on top
	//will probably create another function for this
	get_index(*a); 
	min = min_node(*a);
	//printf("min node value is: %i, index is: %i, top half is: %i\n", min->value, min->index, min->top_half);
	printf("a points to: %i and a-next-value is: %i\n", (*a)->value, (*a)->next->value);
	if (min->top_half == 1)
		while (*a != min)
	{
		rotate(a, "ra");

	}
	else
		while (*a != min)
			reverse_rotate(a, "rra");
	//printf("finish\n");
}