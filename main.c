#include "push_swap.h"


int main(int argc, char **argv)
{
    t_node *a; //pointer to stack node || &a to modify the value of pointer a (which node is it pointing to)
    int flag;
    char **split_argv;

    flag = 0;
    if (argc == 1 || argv[1][0] == '\0')
        return 1;
    if (argc == 2)
    {
        flag = 1;
        split_argv = ft_split(argv[1]);
        stack_build(&a, split_argv, flag);
    }
    else
        stack_build(&a, argv + 1, flag);

    //check if stack_sorted
    //check if lstsize == 2 (and if it is swap)
    //



    return 0;    
}