#include "../../inc/push_swap.h"

int             stack_len(t_stack_node *stack)
{
    int count;

    if (!stack)
        return (0);
    count = 0;
    while (stack)
    {
        stack = stack->next;
        count++;
    }
    return (count);
}

t_stack_node    *find_last(t_stack_node *stack)
{
    if (!stack)
        return (NULL);
    while (stack->next)
        stack = stack->next;
    return (stack);
}  
bool            stack_sorted(t_stack_node *stack)
{
    if (!stack)
        return (1);
    while (stack->next)
    {
        if (stack->nbr > stack->next->nbr)//para cada nodo compara su valor con el del siguiente
            return (false);// si es mayor no esta ordenada
        stack = stack->next;
    }
    return (true);
}

t_stack_node    *find_min(t_stack_node *stack)
{
    long            min;
    t_stack_node    *min_node;//almacena el nodo con el valor minimo
    
    if (!stack)
        return (NULL);
    min = LONG_MAX; //cualquier valor sea menor
    while (stack)
    {
        if (stack->nbr < min)
        {
            min = stack->nbr;
            min_node = stack;
        }
        stack = stack->next;
    }
    return (min_node);
}

t_stack_node    *find_max(t_stack_node *stack)
{
    long            max;
    t_stack_node    *max_node;

    if (!stack)
        return (NULL);
    max = LONG_MIN;
    while (stack)
    {
        if (stack->nbr > max)
        {
            max = stack->nbr;
            max_node = stack;
        }
        stack = stack->next;
    }
    return (max_node);
}