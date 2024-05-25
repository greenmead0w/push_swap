#include "push_swap.h"

int	ft_dlstsize(t_dlist *lst)
{
	int	i;

	i = 0;
	if (lst == NULL)
		return (i);
	i++;
	while (lst -> next != NULL)
	{
		lst = lst -> next;
		i++;
	}
	return (i);
}

t_dlist	*ft_dlstlast(t_dlist *lst)
{
	if (lst != NULL)
	{
		while (lst->next != NULL)
			lst = lst->next;
	}
	return (lst);
}

t_dlist *min_value(t_dlist *header)
{
	int min;
	t_dlist min_node;

	if (header == NULL)
		return NULL;
	min = header->value;
	while (header != NULL)
	{
		if (header->value < min)
		{
			min = header->value;
			min_node = header;
		}
		header = header->next;
	}
	return min_node;
}

t_dlist *return_min_cost(t_dlist *b)
{
	if (b == NULL)
		return NULL;

	while (b != NULL)
	{
		if (b->min_cost == 1)
			return b;
		b = b->next;
	}
	return NULL;

} 