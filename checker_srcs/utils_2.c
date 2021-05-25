#include "checker.h"

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

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i] || !s1[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
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
