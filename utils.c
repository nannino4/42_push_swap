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

int find_median(t_list *head, int n_arg)
{
    n_arg /= 2;
    while (n_arg--)
    {
        head = head->next;
    }
    return (head->n);
}

void    set_index(t_list *a, t_list *b)
{
    int index;
    t_list *tmp;

    while (a)
    {
        tmp = b;
        index = 0;
        while (a->n != b->n)
        {
            b = b->next;
            index++;
        }
        b = tmp;
        a->index = index;
        a = a->next;
    }
}
