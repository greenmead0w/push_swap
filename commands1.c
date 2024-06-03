/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzuloaga <mzuloaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:04:02 by mzuloaga          #+#    #+#             */
/*   Updated: 2024/06/03 13:30:11 by mzuloaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_dlist **header, char *command)
{
	if (ft_dlstsize(*header) < 2)
		return ();
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
void	stack_push(t_dlist **a_header, t_dlist **b_header, char *command)
{
	t_dlist	*temp;

	if (ft_dlstsize(*a_header) == 0)
		return ();
	temp = *a_header;
	*a_header = (*a_header)->next;
	if (*a_header != NULL)
		(*a_header)->previous = NULL;
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

void	rotate(t_dlist **header, char *command)
{
	t_dlist	*last;
	int		size;

	size = ft_dlstsize(*header);
	if (header == NULL || *header == NULL || size == 1)
		return ;
	last = ft_dlstlast(*header);
	last->next = *header;
	*header = (*header)->next;
	(*header)->previous = NULL;
	last->next->previous = last;
	last->next->next = NULL;
	if (command != NULL)
		ft_printf("%s\n", command);


}

void	reverse_rotate(t_dlist **header, char *command)
{
	t_dlist	*last;
	int		len;

	len = ft_dlstsize(*header);
	if (NULL == *header || NULL == header || 1 == len)
		return ;
	last = ft_dlstlast(*header);
	last->previous->next = NULL;
	last->next = *header;
	last->previous = NULL;
	*header = last;
	last->next->previous = last;
	if (command != NULL)
		ft_printf("%s\n", command);
}

void	double_moves(t_dlist **header_a, t_dlist **header_b, char *command)
{
	if (ft_strncmp(command, "rr", 3) == 0)
	{
		rotate(header_a, NULL);
		rotate(header_b, NULL);
	}
	else if (ft_strncmp(command, "rrr", 3) == 0)
	{
		reverse_rotate(header_a, NULL);
		reverse_rotate(header_b, NULL);
        //printf("a value is: %i, b value is: %i\n",
		//(*header_a)->value, (*header_b)->value);
	}
	ft_printf("%s\n", command);
}

