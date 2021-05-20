#include "checker.h"

void	init_index(t_index *index, int argc)
{
	index->first = 0;
	index->last = argc - 2;
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
	t_list	*a;
	t_list	*b;

	a = 0;
	b = 0;
	init_index(&index, argc);
	if (argc < 2)
		return (0);
	while (--argc)
	{
		append_element(&a, my_atoi(*(++argv)), 0);
		append_element(&b, my_atoi(*(argv)), 0);
	}
	set_indexes(a, &b, index.last + 1);
	make_moves(&a, &b);
	if (check_order(a, index.first, index.last) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	if (a)
		destroy_list(&a);
	if (b)
		destroy_list(&b);
}
