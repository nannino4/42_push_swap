#include "push_swap.h"

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

char	*ft_strncpy(char *dest, char *src, size_t n, size_t i)
{
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	*ft_next(char **a, int *size, char c, int i)
{
	char	*start;

	*size = 0;
	start = NULL;
	while (a[0][i])
	{
		if (a[0][i] == c && start)
		{
			a[0] = start + *size;
			return (start);
		}
		else if (a[0][i] != c && !start)
			start = &a[0][i];
		if (a[0][i] != c)
			*size += 1;
		i++;
	}
	a[0] = start + *size;
	if (!(*size))
		return (0);
	return (start);
}

char	**ft_split(const char *s, char c)
{
	int		size;
	char	**m;
	char	*n;
	char	*a;
	int		i;

	if (!s)
		return (NULL);
	a = (char *)s;
	i = 0;
	while (ft_next(&a, &size, c, 0))
		i++;
	m = (char **)malloc((i + 1) * sizeof(char *));
	i = 0;
	a = (char *)s;
	n = ft_next(&a, &size, c, 0);
	while (n)
	{
		m[i] = (char *)malloc((size + 1) * sizeof(char));
		ft_strncpy(m[i++], n, size, 0);
		n = ft_next(&a, &size, c, 0);
	}
	m[i] = 0;
	return (m);
}
