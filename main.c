#include "header.h"

void create_b(t_list **a, t_list **b, int m, int m2, int n_arg)
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
            if (*b && (*b)->n > m2)
            {
                rot_all(a, b);
            }
            else
            {
                rot_a(a);
            }
        }
    }
}

/*
void    order_a_and_b(t_list *a, t_list *b)
{
    //todo
}
*/

int main(int argc, char **argv)
{
    int n_arg;
    int m;
    int m2;
    t_list  *a;
    t_list  *b;

    a = 0;
    b = 0;
    n_arg = argc - 1;
    if (argc < 2)
        return (0);
    argv++;
    while (--argc)
    {
        append_element(&a, my_atoi(argv[n_arg - argc]));
        append_element(&b, my_atoi(argv[n_arg - argc]));
    }
    sort_stack(&b, n_arg);
    m = find_median(b, n_arg);
    m2 = find_median(b, n_arg / 2);
    destroy_list(&b);
    create_b(&a, &b, m, m2, n_arg / 2);
//    order_a_and_b(a, b);
}
