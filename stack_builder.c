/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_builder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzuloaga <mzuloaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:16:12 by mzuloaga          #+#    #+#             */
/*   Updated: 2024/06/03 13:20:13 by mzuloaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// function atol (same as atoi, but helps us with integer overflowing cases)
// what would happen if I used atoi (int min | int max)

/*why atol and not atoi?*/
long	ft_atol(const char *str)
{
	long		result;
	size_t		negative;
	size_t		i;

	result = 0;
	negative = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		negative *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * negative);
}

/*
*/
void	add_stack(t_dlist **a, int value)
{
	t_dlist	*node;
	t_dlist	*last_node;

	if (a == NULL)
		return ;
	node = malloc(sizeof(t_dlist));
	if (node == NULL)
		return ;
	node->next = NULL;
	node->value = value;
	if (*a == NULL)
	{
		*a = node;
		node->previous = NULL;
	}
	else
	{
		last_node = ft_dlstlast(*a);
		last_node->next = node;
		node->previous = last_node;
	}
}

/*if num then atol; if overflow or duplicate then unwind
if number not filtered out then it gets added to the stack
*/
void	stack_build(t_dlist **a, char **argv, int flag)
{
	long	value;
	int		i;

	i = 0;
	while (argv[i] != NULL)
	{
		if (is_num(argv[i]) == 0) 
			unwind(a, argv, flag, "is_num");
		value = ft_atol(argv[i]);
		if (value < INT_MIN || value > INT_MAX)
			unwind(a, argv, flag, "value");
		if (is_duplicate(*a, (int)value) == 0)
			unwind(a, argv, flag, "is_duplicate");
		add_stack(a, (int)value);
		i++;
	}
	if (flag == 1)
		free_split(argv);
}