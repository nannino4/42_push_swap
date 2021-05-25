#include "checker.h"

void	invalid_input_error(void)
{
	write(1, "\n\nError\nInvalid input format\n\n", 30);
	exit(1);
}

int	my_atoi(char *s)
{
	long int	n;
	int			minus;

	n = 0;
	minus = 1;
	if (*s == '-')
	{
		minus = -1;
		s++;
	}
	while (*s <= '9' && *s >= '0' && *s)
	{
		n *= 10;
		n += *s - '0';
		s++;
		if ((minus == 1 && n > INT32_MAX) || \
				(minus == -1 && n - 1 > INT32_MAX))
			invalid_input_error();
	}
	if (*s)
		invalid_input_error();
	return (n * minus);
}

void	sort_stack(t_list **b, int n_arg)
{
	int		n_tmp;
	t_list	*l_tmp;

	l_tmp = *b;
	while (n_arg--)
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

void	check_duplicates(t_list *b)
{
	while (b->next)
	{
		if (b->n == b->next->n)
		{
			write(2, "\n\nError\nThere are duplicates\n\n", 30);
			exit(1);
		}
		b = b->next;
	}
}

void	set_indexes(t_list *a, t_list **b, int n_arg)
{
	int		index;
	t_list	*tmp;

	sort_stack(b, n_arg);
	check_duplicates(*b);
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
