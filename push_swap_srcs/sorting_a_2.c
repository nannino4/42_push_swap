#include "push_swap.h"

void	sort_a_123(t_list **a, t_list **b)
{
	rot_a(a);
	rot_a(a);
	rot_a(a);
	*b = *b;
}
