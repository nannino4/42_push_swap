#include "push_swap.h"

void	swap_all(t_list **a, t_list **b)
{
	if (*a && (*a)->next)
		swap_list(a);
	if (*b && (*b)->next)
		swap_list(b);
	write(1, "ss\n", 3);
}

void	push_a(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (*b)
	{
		append_element(a, (*b)->n, (*b)->index);
		rev_rot_list(a);
		tmp = (*b)->next;
		remove_element(*b);
		*b = tmp;
		write(1, "pa\n", 3);
	}
}

void	push_b(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (*a)
	{
		append_element(b, (*a)->n, (*a)->index);
		rev_rot_list(b);
		tmp = (*a)->next;
		remove_element(*a);
		*a = tmp;
		write(1, "pb\n", 3);
	}
}

void	swap_a(t_list **a)
{
	if (*a && (*a)->next)
		swap_list(a);
	write(1, "sa\n", 3);
}

void	swap_b(t_list **b)
{
	if (*b && (*b)->next)
		swap_list(b);
	write(1, "sb\n", 3);
}
