#include "push_swap.h"

void	sort_3_a(t_list **a, t_list **b, int first, int last)
{
	if ((*a)->index == first)
	{
		if ((*a)->next->index == first + 1)
			sort_a_123(a, b);
		else
			sort_a_132(a, b);
	}
	else if ((*a)->index == first + 1)
	{
		if ((*a)->next->index == first)
			sort_a_213(a, b);
		else
			sort_a_231(a, b);
	}
	else
	{
		if ((*a)->next->index == first)
			sort_a_312(a, b);
		else
			sort_a_321(a, b);
	}
	last = last + 1;
}

void	sort_a(t_list **a, t_list **b, int first, int last)
{
	if (last + 1 - first == 3)
		sort_3_a(a, b, first, last);
	else
	{
		if ((*a)->index == first)
		{
			rot_a(a);
			rot_a(a);
		}
		else
		{
			swap_a(a);
			rot_a(a);
			rot_a(a);
		}
	}
}

void	sort_3_b(t_list **a, t_list **b, int first, int last)
{
	if ((*b)->index == first)
	{
		if ((*b)->next->index == first + 1)
			sort_b_123(a, b);
		else
			sort_b_132(a, b);
	}
	else if ((*b)->index == first + 1)
	{
		if ((*b)->next->index == first)
			sort_b_213(a, b);
		else
			sort_b_231(a, b);
	}
	else
	{
		if ((*b)->next->index == first)
			sort_b_312(a, b);
		else
			sort_b_321(a, b);
	}
	last = last + 1;
}

void	sort_b(t_list **a, t_list **b, int first, int last)
{
	if (last + 1 - first == 3)
		sort_3_b(a, b, first, last);
	else
	{
		if ((*b)->index == first)
		{
			push_a(a, b);
			rot_a(a);
			push_a(a, b);
			rot_a(a);
		}
		else
		{
			push_a(a, b);
			push_a(a, b);
			rot_a(a);
			rot_a(a);
		}
	}
}
