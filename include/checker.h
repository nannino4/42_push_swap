#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 1

typedef struct s_list
{
	int				n;
	int				index;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

typedef struct s_index
{
	int		first;
	int		last;
	t_list	*a;
	t_list	*b;
	char	**split;
}	t_index;

/*
** gnl.c
*/

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
int		find_ch(char const *s, char c);
char	*ft_strdup(const char *s1);

/*
** instructions_2.c
*/

void	rev_rot_a(t_list **a);
void	rev_rot_b(t_list **b);
void	rot_a(t_list **a);
void	rot_b(t_list **b);
void	rot_all(t_list **a, t_list **b);

/*
** instructions_utils.c
*/

void	rev_rot_list(t_list **head);
void	rot_list(t_list **head);
void	swap_list(t_list **head);
void	rev_rot_all(t_list **a, t_list **b);

/*
** instructions.c
*/

void	push_a(t_list **a, t_list **b);
void	push_b(t_list **a, t_list **b);
void	swap_a(t_list **a);
void	swap_b(t_list **b);
void	swap_all(t_list **a, t_list **b);

/*
** list_utils.c
*/

t_list	*create_lelem(int n, int index);
t_list	*go_to_end(t_list *list);
void	append_element(t_list **head, int n, int index);
void	destroy_list(t_list **list);
void	remove_element(t_list *l_elem);

/*
** utils.c
*/

int		my_atoi(char *s);
void	sort_stack(t_list **b, int n_arg);
void	set_indexes(t_list *a, t_list **b, int n_arg);
int		check_order(t_list *list, int first, int last);
int		ft_strncmp(const char *s1, const char *s2, int n);
char	**ft_split(const char *s, char c);

#endif
