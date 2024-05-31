#ifndef PUSH_SWAP
#define PUSH_SWAP

#include "ps_libft/libft.h" // ft_printf, ft_split
#include <unistd.h> //write

#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define LONG_MAX 9223372036854775807

typedef struct s_dlist
{
	int					value;
	int					index;
	int					cost;
	int				top_half; //of the stack
	int				min_cost; //1 if node min cost to move
	struct s_dlist	*bonded_node;
	struct s_dlist	*next;
	struct s_dlist	*previous;
}				t_dlist;	

//stack_builder.c
long	ft_atol(const char *str);
void	add_stack(t_dlist **a, int value);
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


//commands.c
void swap(t_dlist **header, char *command);
void stack_push(t_dlist **a_header, t_dlist **b_header, char *command);
void rotate(t_dlist **header, char *command);
void reverse_rotate(t_dlist **header, char *command);
void double_moves(t_dlist **header_a, t_dlist **header_b, char *command);

//dlist_utils
int	ft_dlstsize(t_dlist *lst);
t_dlist	*ft_dlstlast(t_dlist *lst);
t_dlist *largest_node(t_dlist *header);
t_dlist *return_min_cost(t_dlist *b);
t_dlist *min_node(t_dlist *header);

//algo_push_swap.c
void	push_swap(t_dlist **a, t_dlist **b);
void execute_moves(t_dlist **a, t_dlist **b);
void	operate(t_dlist **stack_header, t_dlist *to_move, char *stack);

//algo_set_node_data.c
void	set_node_data(t_dlist *a, t_dlist *b);
void	get_min_cost(t_dlist *b);
void	get_cost(t_dlist *a, t_dlist *b);
void	bond_nodes(t_dlist *a, t_dlist *b);
void	get_index(t_dlist *header);






#endif