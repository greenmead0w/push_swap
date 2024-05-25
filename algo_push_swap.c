#include "push_swap.h"

//needs to be modified
void	finish_rotation(t_stack_node **stack,
							t_stack_node *top_node,
							char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
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
		while(*a != to_move->bonded_node && *b != to_move)
			double_moves(a, b, "rrr");
	}
	get_index(*a);
	get_index(*b);
	//finish_rotation needs to be added


}

void	push_swap(t_dlist **a, t_dlist **b)
{
	t_dlist	*smallest;
	int				size_a;

	size_a = ft_dlstsize(*a);
	/*if (size_a == 5)
		handle_five(a, b);*/
	else
	{
		while (size_a-- > 3)
			stack_push(a, b, "pb");
	}
	three_sort(a);
	while (*b != NULL)
	{
		set_node_data(*a, *b);
		execute_moves(a, b);
	}
	//at this point stack is ordered, but min_element might not be on top
	//will probably create another function foor this
	set_current_position(*a); 
	smallest = find_smallest(*a);
	if (smallest->above_median)
		while (*a != smallest)
			ra(a, false);
	else
		while (*a != smallest)
			rra(a, false);
}