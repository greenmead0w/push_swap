/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzuloaga <mzuloaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:03:54 by mzuloaga          #+#    #+#             */
/*   Updated: 2024/06/03 13:15:58 by mzuloaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_dlist *header)
{
	if (header == NULL)
		return (1);
	while (header->next)
	{
		if (header->value > header->next->value)
			return (0);
		header = header->next;
	}
	return (1);
}

//routes algo to execute depending on stack size
static	void	route_algo(t_dlist *a, t_dlist *b)
{
	if (is_sorted(a) == 0)
	{
		if (ft_dlstsize(a) == 2)
			swap(&a, "sa");
		else if (ft_dlstsize(a) == 3)
			three_nodes(&a);
		else
			push_swap(&a, &b);
	}
}

int	main(int argc, char **argv)
{
	t_dlist	*a;
	t_dlist	*b;
	int		flag;
	char	**split_argv;

	a = NULL;
	b = NULL;
	flag = 0;
	if (argc == 1 || argv[1][0] == '\0')
		return (1);
	if (argc == 2)
	{
		flag = 1;
		split_argv = ft_split(argv[1], ' ');
		stack_build(&a, split_argv, flag);
	}
	else
		stack_build(&a, argv + 1, flag);
	route_algo(a, b);
	free_stack(&a);
	return (0);
}
