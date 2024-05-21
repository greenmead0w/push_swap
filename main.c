#include "push_swap.h"


    int input_transform(int argc, char **argv)
    {
        int i = 0; 
        char **split_argv;

        if (argc == 1 || argv[1][0] == '\0')
            return 1;
        if (argc == 2) // what happens if "./push_swap 4"
        {
            split_argv = ft_split(argv[1], ' ');
            while(split_argv[i] != NULL)
            {
                argv[i+1] = split_argv[i];
               // ft_printf("split_argv[%i] is: %s\n", i+1, argv[i + 1]);
                i++;
            }
            argv[i+1] = NULL;
        }
        return (0);
    }

int main(int argc, char **argv)
{
   t_node *a; //pointer to stack node || &a to modify the value of pointer a (which node is it pointing to)

        int flag;

        flag = 0;
        if(input_transform(argc, argv) == 1)
            return (1);
        if (argc == 2)
            flag = 1;
        stack_build(&a, argv[1], flag);
        return 0;    
}