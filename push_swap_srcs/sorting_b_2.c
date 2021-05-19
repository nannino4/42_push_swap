#include "push_swap.h"

void	sort_b_123(t_list **a, t_list **b)
{
	push_a(a, b);
	rot_a(a);
	push_a(a, b);
	rot_a(a);
	push_a(a, b);
	rot_a(a);
}
