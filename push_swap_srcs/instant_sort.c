#include "push_swap.h"

void	instant_sort_3(t_list **a, t_list **b, int first, int last)
{
	if ((*a)->index == first)
	{
		if ((*a)->next->index != first + 1)
			instant_sort_a_132(a, b);
	}
	else if ((*a)->index == first + 1)
	{
		if ((*a)->next->index == first)
			instant_sort_a_213(a, b);
		else
			instant_sort_a_231(a, b);
	}
	else
	{
		if ((*a)->next->index == first)
			instant_sort_a_312(a, b);
		else
			instant_sort_a_321(a, b);
	}
	last = last + 1;
}

void	instant_sort_5(t_list **a, t_list **b, int first, int last)
{
	int	n;

	n = 2;
	while (n)
	{
		while ((*a)->index > first + 1)
			rot_a(a);
		push_b(a, b);
		n--;
	}
	instant_sort_3(a, b, first + 2, last);
	if ((*b)->index == first)
		swap_b(b);
	push_a(a, b);
	push_a(a, b);
}

void	instant_sort_4(t_list **a, t_list **b, int first, int last)
{
	int	n;

	n = 2;
	while (n)
	{
		while ((*a)->index > first + 1)
			rot_a(a);
		push_b(a, b);
		n--;
	}
	if ((*a)->index == last)
		swap_a(a);
	if ((*b)->index == first)
		swap_b(b);
	push_a(a, b);
	push_a(a, b);
}

void	instant_sort_2(t_list **a, t_list **b, int first, int last)
{
	if ((*a)->index != first)
		swap_a(a);
	*b = *b;
	last = last + 1;
}

void	instant_sort(t_list **a, t_list **b, int first, int last)
{
	if (last + 1 - first == 5)
		instant_sort_5(a, b, first, last);
	else if (last + 1 - first == 4)
		instant_sort_4(a, b, first, last);
	else if (last + 1 - first == 3)
		instant_sort_3(a, b, first, last);
	else if (last + 1 - first == 2)
		instant_sort_2(a, b, first, last);
}
