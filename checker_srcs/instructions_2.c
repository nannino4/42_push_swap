#include "checker.h"

void	rev_rot_a(t_list **a)
{
	rev_rot_list(a);
}

void	rev_rot_b(t_list **b)
{
	rev_rot_list(b);
}

void	rot_all(t_list **a, t_list **b)
{
	rot_list(a);
	rot_list(b);
}

void	rot_a(t_list **a)
{
	rot_list(a);
}

void	rot_b(t_list **b)
{
	rot_list(b);
}
