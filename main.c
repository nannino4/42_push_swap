#include "header.h"

void    init_index(t_index *index, int argc)
{
    index->first = 0;
    index->last = argc - 2;
}

int check_order(t_list *a, int first, int last)
{
    int i;

    i = first;
    while (i <= last)
    {
        if (a->index != i++)
            return (0);
        a = a->next;
    }
    return (1);
}

int main(int argc, char **argv)
{
    t_index index;
    t_list *a;
    t_list *b;

    a = 0;
    b = 0;
    init_index(&index, argc);
    if (argc < 2)
        return (0);
    while (--argc)
    {
        append_element(&a, my_atoi(*(++argv)), 0);
        append_element(&b, my_atoi(*argv), 0);
    }
    set_indexes(a, &b, index.last + 1);
    if (check_order(a, 0, index.last))
        return (0);
    if (index.last + 1 - index.first > 5)
        first_a_to_b(&a, &b, index.first, index.last);
    else
        instant_sort(&a, &b, index.first, index.last);
}
