#ifndef PUSH_SWAP
#define PUSH_SWAP

#include "ps_libft/libft.h" // ft_printf, ft_split
#include <unistd.h> //write

#define INT_MAX 2147483647
#define INT_MIN -2147483648

typedef struct s_dlist
{
	int					value;
	int					current_position;
	int					final_index;
	int					push_price;
	bool				above_median;
	bool				cheapest;
	struct s_dlist	*target_node;
	struct s_dlist	*next;
	struct s_dlist	*previous;
}				t_dlist;	

//stack_builder.c
long	ft_atol(const char *str);
void	stack_build(t_dlist **a, char **argv, int flag);

//errors.c
int 	is_num(char *str);
int		is_duplicate(t_dlist *a, int number);
void	free_split(char **argv);
void	free_stack(t_dlist **a);
void	unwind(t_dlist**a, char **argv, int flag, char *message); //char *message for debugging, tengo que quitar

//sorting.c
void three_nodes(t_dlist **header);

//sorting_utils.c
t_dlist *largest_node(t_dlist *header);

//commands.c
void swap(t_dlist **header, char *command);
void stack_push(t_dlist **a_header, t_dlist **b_header, char *command);
void rotate(t_dlist **header, char *command);
void reverse_rotate(t_dlist **header, char *command);

//dlist_utils
int	ft_dlstsize(t_dlist *lst);
t_dlist	*ft_dlstlast(t_dlist *lst);






#endif