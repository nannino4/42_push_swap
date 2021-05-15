#include "header.h"

int my_atoi(char *s)
{
    long int    n;
    int minus;

    n = 0;
    minus = 1;
    if (!s)
    {
        write(1, "\n\nerror\n\nmy_atoi found a null pointer as argument\n", 47);
        exit(1);
    }
    if (*s == '-')
    {
        minus = -1;
        s++;
    }
    while (*s <= '9' && *s >= '0' && *s)
    {
        n *= 10;
        n += *s - '0';
        s++;
    }
    return (n * minus);
}

void    sort_stack(t_list **b, int n_arg)
{
    int n_tmp;
    t_list  *l_tmp;

    l_tmp = *b;
    while(n_arg--)
    {
        while ((*b)->next)
        {
            if ((*b)->n > (*b)->next->n)
            {
                n_tmp = (*b)->n;
                (*b)->n = (*b)->next->n;
                (*b)->next->n = n_tmp;
            }
            (*b) = (*b)->next;
        }
        *b = l_tmp;
    }
}

void    set_indexes(t_list *a, t_list **b, int n_arg)
{
    sort_stack(b, n_arg);
    int index;
    t_list *tmp;

    while (a)
    {
        tmp = *b;
        index = 0;
        while (a->n != (*b)->n)
        {
            *b = (*b)->next;
            index++;
        }
        *b = tmp;
        a->index = index;
        a = a->next;
    }
    destroy_list(b);
}

int find_index(int my_index, t_list *list)
{
    int distance;

    distance = 0;
    while (list->index != my_index)
    {
        distance++;
        list = list->next;
    }
    return (distance);
}

int max_index(t_list *list)
{
    int max_index;

    max_index = 0;
    while (list)
    {
        if (list->index > max_index)
            max_index = list->index;
        list = list->next;
    }
    return (max_index);
}
