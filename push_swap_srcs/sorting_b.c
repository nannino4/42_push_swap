#include "push_swap.h"

void	sort_b_132(t_list **a, t_list **b)
{
	push_a(a, b);
	rot_a(a);
	push_a(a, b);
	push_a(a, b);
	rot_a(a);
	rot_a(a);
}

void	sort_b_213(t_list **a, t_list **b)
{
	push_a(a, b);
	push_a(a, b);
	rot_a(a);
	rot_a(a);
	push_a(a, b);
	rot_a(a);
}

void	sort_b_231(t_list **a, t_list **b)
{
	swap_b(b);
	push_a(a, b);
	push_a(a, b);
	push_a(a, b);
	rot_a(a);
	rot_a(a);
	rot_a(a);
}

void	sort_b_312(t_list **a, t_list **b)
{
	push_a(a, b);
	push_a(a, b);
	rot_a(a);
	push_a(a, b);
	rot_a(a);
	rot_a(a);
}

void	sort_b_321(t_list **a, t_list **b)
{
	push_a(a, b);
	push_a(a, b);
	push_a(a, b);
	rot_a(a);
	rot_a(a);
	rot_a(a);
}
