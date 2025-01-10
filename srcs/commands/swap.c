#include "../../inc/push_swap.h"

static void swap(t_stack_node **top)
{
    if (!*top || !(*top)->next)
        return ;
    *top = (*top)->next;
    (*top)->prev->prev = *top;
    (*top)->prev->next = (*top)->next;
    if ((*top)->next)
        (*top)->next->prev = (*top)->prev;
    (*top)->next = (*top)->prev;
    (*top)->prev = NULL;
}

void    sa(t_stack_node **a, bool print)
{
    swap(a);
    if(!print)
        ft_printf("sa\n");
}

void    sb(t_stack_node **b, bool print)
{
    swap(b);
    if(!print)
        ft_printf("sb\n");
}

void    ss(t_stack_node **a, t_stack_node **b, bool print)
{
    swap(a);
    swap(b);
    if(!print)
        ft_printf("ss\n");
}