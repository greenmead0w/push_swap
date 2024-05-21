#ifndef PUSH_SWAP
#define PUSH_SWAP

#include "ps_libft/libft.h" // ft_printf, ft_split
#include <unistd.h> //write

#define INT_MAX 2147483647
#define INT_MIN -2147483648

typedef struct s_node
{
	int					value;
	int					current_position;
	int					final_index;
	int					push_price;
	bool				above_median;
	bool				cheapest;
	struct s_node	*target_node;
	struct s_node	*next;
	struct s_node	*previous;
}				t_node;	

//stack_build.c
long	ft_atol(const char *str);

//errors.c
int 	is_num(char *str);
int		is_duplicate(t_stack_node *a, int number);
void	free_split(char **argv);
void	free_stack(t_node **a);
void	unwind(t_node **a, char **argv, int flag);




#endif