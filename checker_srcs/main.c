#include "checker.h"

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

void	do_other_moves(t_list **a, t_list **b, char *line)
{
	if (!ft_strncmp(line, "sb", 3))
		swap_b(b);
	else if (!ft_strncmp(line, "ss", 3))
		swap_all(a, b);
	else if (!ft_strncmp(line, "ra", 3))
		rot_a(a);
	else if (!ft_strncmp(line, "rb", 3))
		rot_b(b);
	else if (!ft_strncmp(line, "rr", 3))
		rot_all(a, b);
	else if (!ft_strncmp(line, "rra", 3))
		rev_rot_a(a);
	else if (!ft_strncmp(line, "rrb", 3))
		rev_rot_b(b);
	else if (!ft_strncmp(line, "rrr", 3))
		rev_rot_all(a, b);
	else
	{
		write(2, "\n\nError\nInvalid command\n\n", 25);
		free(line);
		exit(1);
	}
}

void	make_moves(t_list **a, t_list **b)
{
	char	*line;
	int		n;

	n = 1;
	while (n)
	{
		n = get_next_line(0, &line);
		if (n == 0)
			return ;
		else if (!ft_strncmp(line, "pa", 3))
			push_a(a, b);
		else if (!ft_strncmp(line, "pb", 3))
			push_b(a, b);
		else if (!ft_strncmp(line, "sa", 3))
			swap_a(a);
		else
			do_other_moves(a, b, line);
		free(line);
	}
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
			append_element(&index.b, my_atoi(*(index.split++)), 0);
			free(*index.split++);
		}
		free(tmp);
	}
	init_indexes(&index);
	set_indexes(index.a, &index.b, index.last + 1);
	make_moves(&index.a, &index.b);
	if (check_order(index.a, index.first, index.last) && !index.b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	if (index.a)
		destroy_list(&index.a);
	if (index.b)
		destroy_list(&index.b);
}
