#include "push_swap.h"


// que pasa si solo un argumento
// que pasa si entre argumentos hay más de un espacio

int main(int argc, char **argv)
{
    t_dlist *a; //pointer to stack node || &a to modify the value of pointer a (which node is it pointing to)
    int flag;
    char **split_argv;

    flag = 0;
    if (argc == 1 || argv[1][0] == '\0')
        return 1; //printear un mensaje igual bien
    if (argc == 2)
    {
        flag = 1;
        split_argv = ft_split(argv[1], ' ');
        stack_build(&a, split_argv, flag);
    }
    else
        stack_build(&a, argv + 1, flag);

    t_dlist *current = a;
    int i = 0;
    while (current!= NULL) {
        printf("node %i value is: %d\n", i, current->value);
        current = current->next;
        i++;
    }
    printf("------------------\n");
    if (ft_dlstsize(a) == 3)
        three_nodes(&a);
    current = a;

    while (current!= NULL) {
        printf("node %i value is: %d\n", i, current->value);
        printf("node %i memory address is: %p", i, current);
        printf("node %i previous is: %p\n", i, current->previous);
        printf("node %i next is: %p\n", i, current->next);
        current = current->next;
        i++;
    }

    //check if stack_sorted
    //check if lstsize == 2 (and if it is swap)
    //


    free_stack(&a);
    return 0;    
}