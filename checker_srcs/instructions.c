#include "checker.h"

void	swap_all(t_list **a, t_list **b)
{
	swap_list(a);
	swap_list(b);
}

void	push_a(t_list **a, t_list **b)
{
	t_list	*tmp;

	append_element(a, (*b)->n, (*b)->index);
	rev_rot_list(a);
	tmp = (*b)->next;
	remove_element(*b);
	*b = tmp;
}

void	push_b(t_list **a, t_list **b)
{
	t_list	*tmp;

	append_element(b, (*a)->n, (*a)->index);
	rev_rot_list(b);
	tmp = (*a)->next;
	remove_element(*a);
	*a = tmp;
}

void	swap_a(t_list **a)
{
	swap_list(a);
}

void	swap_b(t_list **b)
{
	swap_list(b);
}
