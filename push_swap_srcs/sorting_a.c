#include "push_swap.h"

void	sort_a_132(t_list **a, t_list **b)
{
	rot_a(a);
	swap_a(a);
	rot_a(a);
	rot_a(a);
	*b = *b;
}

void	sort_a_213(t_list **a, t_list **b)
{
	swap_a(a);
	rot_a(a);
	rot_a(a);
	rot_a(a);
	*b = *b;
}

void	sort_a_231(t_list **a, t_list **b)
{
	push_b(a, b);
	swap_a(a);
	rot_a(a);
	push_a(a, b);
	rot_a(a);
	rot_a(a);
}

void	sort_a_312(t_list **a, t_list **b)
{
	push_b(a, b);
	rot_a(a);
	rot_a(a);
	push_a(a, b);
	rot_a(a);
}

void	sort_a_321(t_list **a, t_list **b)
{
	push_b(a, b);
	swap_a(a);
	rot_a(a);
	rot_a(a);
	push_a(a, b);
	rot_a(a);
}
