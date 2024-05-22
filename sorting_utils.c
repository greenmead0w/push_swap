#include "push_swap.h"

//smallest_node
//target_node
//stack_sorted

t_node *largest_node(t_node *header)
{
    t_node *l_node;

    l_node = header;s
    if (header == NULL)
        return(NULL);
    while(header != NULL)
    {
        if (header->value > l_node->value)
            l_node = header;
        header = header->next;
    }
    return (l_node);
}