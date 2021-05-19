#include "push_swap.h"

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
	}
	if (*s || (minus == 1 && n > INT32_MAX) || \
			(minus == -1 && n - 1 > INT32_MAX))
	{
		write(1, "\n\nError\nInvalid input format\n\n", 30);
		exit(1);
	}
	return (n * minus);
}

void	init_data(t_data *data, int first, int last)
{
	data->i = 0;
	data->middle = (last + first) / 2;
	data->n = data->middle + 1 - first;
}
