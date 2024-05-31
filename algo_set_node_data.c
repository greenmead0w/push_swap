#include "push_swap.h"


/*as if stack is array each element is indexed and
sets above_median property*/
void	get_index(t_dlist *header)
{
	int	i;
	int	median;

	i = 0;
	if (header == NULL)
		return ;
	median = ft_dlstsize(header) / 2; // 11 / 2 = 5
	while (header != NULL)
	{
		header->index = i;
		if (i <= median)
			header->top_half = 1;
		else
			header->top_half = 0;
		header = header->next;
		i++;
	}
}

/*for every node in stack b find its friend node in stack a:
    1. closest to value but bigger element (6 is closer than 7 to 5) 
    2. if no bigger number, smallest number*/
void	bond_nodes(t_dlist *a, t_dlist *b)
{
	t_dlist	*temp_a;
	t_dlist	*bond;
	long	closest_value;

	while (b != NULL)
	{
		closest_value = LONG_MAX;
		temp_a = a;
		while (temp_a != NULL)
		{
			if (temp_a->value > b->value
				&& temp_a->value < closest_value)
			{
				closest_value = temp_a->value;
				bond = temp_a;
			}
			temp_a = temp_a->next;
		}
		if (closest_value == LONG_MAX)
			b->bonded_node = min_node(a);
		else
			b->bonded_node = bond;
		b = b->next;
	}
}

//cost of pushing bond node + node in b to the top of each stack
void	get_cost(t_dlist *a, t_dlist *b)
{
	int	size_a;
	int	size_b;

	size_a = ft_dlstsize(a);
	size_b = ft_dlstsize(b);
	while (b != NULL)
	{
		b->cost = b->index;
		if (b->top_half == 0)
			b->cost = size_b - (b->index);
		if (b->bonded_node->top_half)
			b->cost += b->bonded_node->index;
		else
			b->cost += size_a - (b->bonded_node->index);
		b = b->next;
	}
}

//find node with min cost and set its property to true
void	get_min_cost(t_dlist *b)
{
	int			cost;
	t_dlist	*min_cost_node;

	if (b == NULL)
		return ;
	cost = b->cost;
	min_cost_node = b;
	while (b != NULL)
	{
		if (b->cost < cost)
		{
			cost = b->cost;
			min_cost_node = b;
		}
		b = b->next;
	}
	min_cost_node->min_cost = 1;
}


void	set_node_data(t_dlist *a, t_dlist *b)
{
	get_index(a);
	get_index(b);
    bond_nodes(a, b);
	get_cost(a, b);
	get_min_cost(b);
}