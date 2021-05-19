#include "push_swap.h"

void	from_b_to_a(t_list **a, t_list **b, int first, int last)
{
	int	n;
	int	middle;

	middle = (last + first) / 2;
	n = last - middle;
	while (n)
	{
		while (!((*b)->index <= last && (*b)->index > middle))
			rot_b(b);
		push_a(a, b);
		n--;
	}
	if (middle + 1 - first > 3)
		from_b_to_a(a, b, first, middle);
	else
		sort_b(a, b, first, middle);
	if (last - middle > 3)
		from_a_to_b(a, b, middle + 1, last);
	else
		sort_a(a, b, middle + 1, last);
}

void	from_a_to_b(t_list **a, t_list **b, int first, int last)
{
	t_data	data;

	init_data(&data, first, last);
	while (data.n)
	{
		while (!((*a)->index <= data.middle && (*a)->index >= first))
		{
			rot_a(a);
			data.i++;
		}
		push_b(a, b);
		data.n--;
	}
	while (data.i--)
		rev_rot_a(a);
	if (data.middle + 1 - first > 3)
		from_b_to_a(a, b, first, data.middle);
	else
		sort_b(a, b, first, data.middle);
	if (last - data.middle > 3)
		from_a_to_b(a, b, data.middle + 1, last);
	else
		sort_a(a, b, data.middle + 1, last);
}

void	first_a_to_b(t_list **a, t_list **b, int first, int last)
{
	int		n;
	int		middle;

	middle = (last + first) / 2;
	n = middle + 1 - first;
	while (n)
	{
		while (!((*a)->index <= middle && (*a)->index >= first))
			rot_a(a);
		push_b(a, b);
		n--;
	}
	if (middle + 1 - first > 3)
		from_b_to_a(a, b, first, middle);
	else
		sort_b(a, b, first, middle);
	if (last - middle > 3)
		from_a_to_b(a, b, middle + 1, last);
	else
		sort_a(a, b, middle + 1, last);
}
