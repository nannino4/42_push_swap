#include "header.h"

void    init_index(t_index *index, int argc)
{
    index->first = 0;
    index->last = argc - 2;
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
    set_index(a, &b, index.last + 1);
    //if (check_order(a, 0, index.last))
    //    return (0);
    if (index.last - index.first >= 3)
        first_a_to_b(&a, &b, index.first, index.last);
    //else
        //sort_a(&a, &b, index.first, index.last);
}
