#ifndef PUSH_SWAP
#define PUSH_SWAP

#include "ps_libft/libft.h" // ft_printf, ft_split
#include <unistd.h> //write

#define INT_MAX 2147483647
#define INT_MIN -2147483648

typedef struct s_list
{
	int					value;
	int					current_position;
	int					final_index;
	int					push_price;
	bool				above_median;
	bool				cheapest;
	struct s_list	*target_node;
	struct s_list	*next;
	struct s_ist	*previous;
}				t_list;	

//stack_builder.c
long	ft_atol(const char *str);

//errors.c
int 	is_num(char *str);
int		is_duplicate(t_list *a, int number);
void	free_split(char **argv);
void	free_stack(t_list **a);
void	unwind(t_list **a, char **argv, int flag);

//sorting.c

//sorting_utils.c
t_list *largest_node(t_list *header);

//commands.c
void swap(t_list **header, char *command);
void stack_push(t_list **a_header, t_list **b_header, char *command);
void rotate(t_list **header, char *command);
void reverse_rotate(t_list **header, char *command);







#endif