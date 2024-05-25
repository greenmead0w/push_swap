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