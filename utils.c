#include "header.h"

void	sort_stack(t_list **b, int n_arg)
{
	int		n_tmp;
	t_list	*l_tmp;

	l_tmp = *b;
	while(n_arg--)
	{
		while ((*b)->next)
		{
			if ((*b)->n > (*b)->next->n)
			{
				n_tmp = (*b)->n;
				(*b)->n = (*b)->next->n;
				(*b)->next->n = n_tmp;
			}
			(*b) = (*b)->next;
		}
		*b = l_tmp;
	}
}

void	set_indexes(t_list *a, t_list **b, int n_arg)
{
	int		index;
	t_list	*tmp;

	sort_stack(b, n_arg);
	while (a)
	{
		tmp = *b;
		index = 0;
		while (a->n != (*b)->n)
		{
			*b = (*b)->next;
			index++;
		}
		*b = tmp;
		a->index = index;
		a = a->next;
	}
	destroy_list(b);
}

int	find_index(int my_index, t_list *list)
{
	int		distance;

	distance = 0;
	while (list->index != my_index)
	{
		distance++;
		list = list->next;
	}
	return (distance);
}

int	search_index(t_list *list, int index)
{
	while (list)
	{
		if (list->index == index)
			return (1);
		list = list->next;
	}
	return (0);
}

int	max_chunk_index(t_list *list, int index)
{
	while (search_index(list, index))
		index++;
	return (--index);
}
