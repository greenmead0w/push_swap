/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzuloaga <mzuloaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:32:06 by mzuloaga          #+#    #+#             */
/*   Updated: 2024/06/04 11:37:30 by mzuloaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//returns 1 if num, 0 if not
int	is_num(char *str)
{
	int	i;

	i = 0;
	if (!(str[i] == '+' || str[i] == '-') && (str[i] < '0' || str[i] > '9'))
		return (0);
	if ((str[i] == '+' || str[i] == '-') && ft_isdigit(str[i + 1]) == 0)
		return (0);
	i++;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

//returns 0 if num is duplicate
int	is_duplicate(t_dlist *a, int number)
{
	while (a != NULL)
	{
		if (a->value == number)
			return (0);
		a = a->next;
	}
	return (1);
}

void	free_split(char **argv)
{
	int	i;

	i = 0;
	if (argv == NULL || *argv == NULL)
		return ;
	while (argv[i] != NULL)
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	free_stack(t_dlist **a)
{
	t_dlist	*tmp;
	t_dlist	*current;

	if (a == NULL)
		return ;
	current = *a;
	while (current != NULL)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*a = NULL;
}

void	unwind(t_dlist **a, char **argv, int flag)
{
	free_stack(a);
	if (flag == 1)
		free_split(argv);
	write(2, "Error\n", 6);
	exit(1);
}
