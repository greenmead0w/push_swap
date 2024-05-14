#include "push_swap.h"

int main(int argc, char **argv)
{
    int i = argc - 2;
    //I should modify ft_split so argv[0] is now NULL?
    argv = ft_split(argv[1], ' ');
    while (argv[i] != NULL)
    {
        ft_printf("argv[%i] is: %s\n", i, argv[i]);
        i++;
    }
    return 0;

}