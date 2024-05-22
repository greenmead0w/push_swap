#include "push_swap.h"

/*check for the largest value, move to bottom
check for new largest, move to bottom 
*/
void three_nodes(t_node **header) 
{
    t_node largest;
    
    largest = largest_node(*header);
    if (*header == largest)
        rotate(header, "ra");
    else if ((*header)->next == largest)
        reverse_rotate(header, "rra");
    if((*header)->value > (*header)->next->value)
        swap(*header, "sa");
}