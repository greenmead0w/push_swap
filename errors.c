#include "push_swap.h"


int is_num(char *str)
{
    int i;

    i = 0;
    if (str[i] == '+' || str[i] == '-' && ft_isdigit(str[i+1]) == 0 ) // qué pasa si input es ./pus_swap +
        return 0;
    i++;
    while(str[i] != '\0')
    {
        if (ft_isdigit(str[i] == 0))
            return 0;
        i++;
    }
    return 1;
}

int is_duplicate(t_node *a, int number)
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

void	free_stack(t_node **a)
{
	t_node	*tmp;
	t_node	*current;

	if (a == NULL)
		return ;
	current = *a;
	while (current != NULL)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*a = NULL; // para evitar dangling pointers
}
void	unwind(t_node **a, char **argv, int flag)
{
	free_stack(a);
	if (flag == 1)
		free_split(argv);
	write(2, "Error\n", 6);
	exit(1);
}