#include "header.h"
/*
void    sort_a(t_list **a, t_list **b, int first_id, int last_id)
{
    //todo sort with 5 or less elements
}

void    sort_b(t_list **a, t_list **b, int first_id, int last_id)
{
    //todo sort with 5 or less elements
}
*/
void from_b_to_a(t_list **a, t_list **b, int first_id, int last_id)
{
    int n;

    n = last_id + 1 - first_id;
    while (n)
    {
        while (!((*b)->index <= last_id && (*b)->index >= first_id))
            rot_b(b);
        push_a(a, b);
        n--;
    }
    while (last_id - first_id >= 5)
    {
        from_a_to_b(a, b, first_id, (last_id + first_id) / 2);
        first_id = (last_id + first_id) / 2 + 1;
    }
//    sort_a(a, b, first_id, last_id);
}

void from_a_to_b(t_list **a, t_list **b, int first_id, int last_id)
{
    int n;
    int i;

    i = 0;
    n = last_id + 1 - first_id;
    while (n)
    {
        while (!((*a)->index <= last_id && (*a)->index >= first_id))
        {
            rot_a(a);
            i++;
        }
        push_b(a, b);
        n--;
    }
    while (i--)
        rev_rot_a(a);
    while (last_id - first_id >= 5)
    {
        from_b_to_a(a, b, (last_id + first_id) / 2 + 1, last_id);
        last_id = (last_id + first_id) / 2;
    }
//    sort_b(a, b, first_id, last_id);
}

void first_a_to_b(t_list **a, t_list **b, int first_id, int last_id)
{
    int n;

    n = last_id + 1 - first_id;
    while (n)
    {
        while (!((*a)->index <= last_id && (*a)->index >= first_id))
            rot_a(a);
        push_b(a, b);
        n--;
    }
    while (last_id - first_id >= 5)
    {
        from_b_to_a(a, b, (last_id + first_id) / 2 + 1, last_id);
        last_id = (last_id + first_id) / 2;
    }
//    sort_b(a, b, first_id, last_id);
}
