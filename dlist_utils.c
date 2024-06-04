/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzuloaga <mzuloaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:53:50 by mzuloaga          #+#    #+#             */
/*   Updated: 2024/06/04 11:31:31 by mzuloaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//get linked list size
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

//get last node in linked list
t_dlist	*ft_dlstlast(t_dlist *lst)
{
	if (lst != NULL)
	{
		while (lst->next != NULL)
			lst = lst->next;
	}
	return (lst);
}

//get node with min value
t_dlist	*min_node(t_dlist *header)
{
	t_dlist	*min_node;

	min_node = header;
	if (header == NULL)
		return (NULL);
	while (header != NULL)
	{
		if (header->value < min_node->value)
			min_node = header;
		header = header->next;
	}
	return (min_node);
}

//get node with max 
t_dlist	*largest_node(t_dlist *header)
{
	t_dlist	*l_node;

	l_node = header;
	if (header == NULL)
		return (NULL);
	while (header != NULL)
	{
		if (header->value > l_node->value)
			l_node = header;
		header = header->next;
	}
	return (l_node);
}

//get node with min cost
t_dlist	*return_min_cost(t_dlist *b)
{
	if (b == NULL)
		return (NULL);
	while (b != NULL)
	{
		if (b->min_cost == 1)
			return (b);
		b = b->next;
	}
	return (NULL);
}
