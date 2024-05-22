#include "push_swap.h"


//find way to sort 5 node
//create array to store every number from stack A
//merge sort array
//assign each node in stack A an integer representing its position in sorted array
//put every node in stack b (except for 3 nodes, which will be sorted following 3 node algo)
//per node, calculate how many steps it takes to put it in the right place in A


/*index_init --> calls function array_populate, assigns an index to every node, calls array sorting function
array_populate--> puts every nodes value in array
merge_sort -->orders values in array


*/



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

