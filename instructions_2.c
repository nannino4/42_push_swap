#include "header.h"

void    rev_rot_a(t_list **head)
{
    rev_rot_list(head);
    write(1, "rra\n", 4);
}

void    rev_rot_b(t_list **head)
{
    rev_rot_list(head);
    write(1, "rrb\n", 4);
}

void    rot_all(t_list **a, t_list **b)
{
    rot_list(a);
    rot_list(b);
    write(1, "rr\n", 3);
}

void    rot_a(t_list **head)
{
    rot_list(head);
    write(1, "ra\n", 3);
}

void    rot_b(t_list **head)
{
    rot_list(head);
    write(1, "rb\n", 3);
}