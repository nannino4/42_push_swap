#include "header.h"

void create_b(t_list **a, t_list **b, int m, int n_arg)
{
    *b = 0;
    while (n_arg)
    {
        if ((*a)->n < m)
        {
            push_b(a, b);
            n_arg--;
        }
        else
        {
            rot_a(a);
        }
    }
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

void    order_b(t_list **a, t_list **b, int n_arg)
{
    int current_index;
    int distance;

    current_index = n_arg / 2;
    while (--current_index)
    {
        distance = find_index(current_index, *b);
        if (distance > n_arg / 4)
        {
            distance = (n_arg / 2) - distance;
            while (distance--)
                rev_rot_b(b);
        }
        else
        {
            while (distance--)
                rot_b(b);
        }
        push_a(a, b);
    }
    n_arg /= 2;
    while (n_arg--)
        push_b(a, b);
}

void    order_a(t_list **a, t_list **b, int n_arg)
{
    int current_index;
    int distance;

    current_index = n_arg;
    while (--current_index >= n_arg / 2)
    {
        distance = find_index(current_index, *a);
        if (distance > n_arg / 4)
        {
            distance = (n_arg / 2) - distance;
            while (distance--)
                rev_rot_a(a);
        }
        else
        {
            while (distance--)
                rot_a(a);
        }
        push_b(a, b);
    }
    while (n_arg--)
        push_a(a, b);
}

int main(int argc, char **argv)
{
    t_data data;

    data.a = 0;
    data.b = 0;
    data.n_arg = argc - 1;
    if (argc < 2)
        return (0);
    argv++;
    while (--argc)
    {
        append_element(&data.a, my_atoi(argv[data.n_arg - argc]));
        append_element(&data.b, my_atoi(argv[data.n_arg - argc]));
    }
    sort_stack(&data.b, data.n_arg);
    set_index(data.a, data.b);
    data.m = find_median(data.b, data.n_arg);
    destroy_list(&data.b);
    create_b(&data.a, &data.b, data.m, data.n_arg / 2);
    order_b(&data.a, &data.b, data.n_arg);
    order_a(&data.a, &data.b, data.n_arg);
}
