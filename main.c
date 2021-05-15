#include "header.h"

int l_len(t_list *list)
{
    int len;

    len = 0;
    while (list)
    {
        len++;
        list = list->next;
    }
    return (len);
}

int check_order(t_list *list, int first_id, int last_id)
{
    //todo check if elements are in order
    return (1);
}

void    sort_a(t_list **a, t_list **b, int first_id, int last_id)
{
    //todo sort with 5 or less elements
}

void from_b_to_a(t_list **a, t_list **b, int first_id, int last_id)
{
    int n;

    n = ((first_id + last_id) / 2) - first_id;
    if (n <= 2)
    {
        sort_b(a, b, first_id, last_id);
    }
    while (n)
    {
        if ((*b)->index <= ((first_id + last_id) / 2) && (*b)->index >= first_id)
        {
            push_a(a, b);
            n--;
        }
        else
        {
            rot_b(b);
        }   
    }
    if (check_order(*a, first_id, ((first_id + last_id) / 2)))
        return ;
}

void    set_a_position(t_list **a, int index)
{
    int distance;

    if (index > 0)
    {
        distance = find_index(index - 1, *a);
        if (distance > l_len(*a) / 2)
        {
            while ((*a)->index != index - 1)
                rev_rot_a(a);
            rot_a(a);
        }
        else
        {
            while ((*a)->index != index - 1)
                rot_a(a);
            rot_a(a);
        }
    }
}

void from_a_to_b(t_list **a, t_list **b, int first_id, int last_id)
{
    int n;

    n = last_id - first_id;
    while (n)
    {
        while (!((*a)->index <= last_id && (*a)->index >= first_id))
            rot_a(a);
        push_b(a, b);
        n--;
    }
    set_a_position(a, first_id);


    if (check_order(*b, first_id, ((first_id + last_id) / 2)))
        send_a(a, b, first_id, ((first_id + last_id) / 2));
    else
        from_b_to_a(a, b, first_id, ((first_id + last_id) / 2));
    if (!check_order(*a, ((first_id + last_id) / 2) + 1, last_id))
        from_a_to_b(a, b, ((first_id + last_id) / 2) + 1, last_id);


    if (!check_order(*b, first_id, l_len(*a) - 1))
        if (l_len(*a) - 0 <= 5)
            sort_a(a, b, 0, l_len(*a) - 1);
        else
            from_a_to_b(a, b, 0, (l_len(*a) + 0) / 2);
}

void    init_data(t_data *data, int argc)
{
    data->a = 0;
    data->b = 0;
    data->n_arg = argc - 1;
    data->first_id = 0;
    data->last_id = (argc - 2) / 2;
}

int main(int argc, char **argv)
{
    t_data data;

    init_data(&data, argc);
    if (argc < 2)
        return (0);
    while (--argc)
    {
        append_element(&data.a, my_atoi(*(++argv)), 0);
        append_element(&data.b, my_atoi(*argv), 0);
    }
    set_indexes(data.a, &data.b, data.n_arg);
    if (check_order(data.a, 0, max_index(data.a)))
        return ;
    while (data.last_id - data.first_id > 5 && check_order(data.a, data.first_id, data.last_id))
    {
        data.first_id = data.last_id + 1;
        data.last_id = (max_index(data.a) + data.first_id) / 2;
    }
    if (data.last_id - data.first_id <= 5)
        sort_a(&data.a, &data.b, data.first_id, data.last_id);
    else
        from_a_to_b(&data.a, &data.b, data.first_id, data.last_id);
}
