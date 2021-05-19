#include "header.h"

int	my_atoi(char *s)
{
	long int	n;
	int			minus;

	n = 0;
	minus = 1;
	if (!s)
	{
		write(1, "\n\nerror\n\nmy_atoi found a null pointer as argument\n", 47);
		exit(1);
	}
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
	return (n * minus);
}

void	init_data(t_data *data, int first, int last)
{
	data->i = 0;
	data->middle = (last + first) / 2;
	data->n = data->middle + 1 - first;
}
