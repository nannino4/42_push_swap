#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

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

typedef struct s_data
{
	int	n;
	int	middle;
	int	i;
}	t_data;

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
int		find_index(int my_index, t_list *list);
int		check_order(t_list *list, int first, int last);
void	init_data(t_data *data, int first, int last);
char	**ft_split(const char *s, char c);

/*
** quicksort.c
*/

void	first_a_to_b(t_list **a, t_list **b, int first, int last);
void	from_a_to_b(t_list **a, t_list **b, int first, int last);;
void	from_b_to_a(t_list **a, t_list **b, int first, int last);
void	sort_b(t_list **a, t_list **b, int first, int last);
void	sort_a(t_list **a, t_list **b, int first, int last);

void	instant_sort(t_list **a, t_list **b, int first, int last);

void	instant_sort_a_132(t_list **a, t_list **b);
void	instant_sort_a_213(t_list **a, t_list **b);
void	instant_sort_a_231(t_list **a, t_list **b);
void	instant_sort_a_312(t_list **a, t_list **b);
void	instant_sort_a_321(t_list **a, t_list **b);

void	sort_b_123(t_list **a, t_list **b);
void	sort_b_132(t_list **a, t_list **b);
void	sort_b_213(t_list **a, t_list **b);
void	sort_b_231(t_list **a, t_list **b);
void	sort_b_312(t_list **a, t_list **b);
void	sort_b_321(t_list **a, t_list **b);

void	sort_a_123(t_list **a, t_list **b);
void	sort_a_132(t_list **a, t_list **b);
void	sort_a_213(t_list **a, t_list **b);
void	sort_a_231(t_list **a, t_list **b);
void	sort_a_312(t_list **a, t_list **b);
void	sort_a_321(t_list **a, t_list **b);

#endif
