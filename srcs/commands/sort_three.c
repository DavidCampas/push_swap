#include "../../inc/push_swap.h"

void    sort_three(t_stack_node **a)
{
    t_stack_node    *biggest_node;

    biggest_node = find_max(*a);
    if (biggest_node == *a)//comp si el nmax esta arriba
        ra(a, false);// si es asi lo enviamos abajo
    else if ((*a)->next == biggest_node)//si el 2 es el mayor
        rra(a, false);
    if ((*a)->nbr > (*a)->next->nbr)// si el 1 es mas garnde que el 2 
        sa(a, false);//swap
}