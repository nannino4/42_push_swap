#include "push_swap.h"

void	init_index(t_index *index)
{
	index->a = 0;
	index->b = 0;
	index->split = 0;
}

void	init_indexes(t_index *index)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = index->a;
	while (tmp->next)
	{
		i++;
		tmp = tmp->next;
	}
	index->first = 0;
	index->last = i;
}

int	check_order(t_list *a, int first, int last)
{
	int	i;

	i = first;
	while (i <= last && a)
	{
		if (a->index != i++)
			return (0);
		a = a->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_index	index;
	char **tmp;

	init_index(&index);
	if (argc < 2)
		return (0);
	while (*(++argv))
	{
		index.split = ft_split(*argv, ' ');
		tmp = index.split;
		while (*index.split)
		{
			append_element(&index.a, my_atoi(*(index.split)), 0);
			append_element(&index.b, my_atoi(*(index.split)), 0);
			free(*index.split++);
		}
		free(tmp);
	}
	init_indexes(&index);
	set_indexes(index.a, &index.b, index.last + 1);
	if (check_order(index.a, index.first, index.last))
		return (0);
	if (index.last + 1 - index.first > 5)
		first_a_to_b(&index.a, &index.b, index.first, index.last);
	else
		instant_sort(&index.a, &index.b, index.first, index.last);
	destroy_list(&index.a);
}
