#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
    int n;
    struct s_list   *prev;
    struct s_list   *next;
}   t_list;

/*
** instructions_2.c
*/

void    rev_rot_a(t_list **head);
void    rev_rot_b(t_list **head);
void    rot_a(t_list **head);
void    rot_b(t_list **head);
void    rot_all(t_list **a, t_list **b);

/*
** instructions_utils.c
*/

void    rev_rot_list(t_list **head);
void    rot_list(t_list **head);
void    swap_list(t_list **head);
void    rev_rot_all(t_list **a, t_list **b);

/*
** instructions.c
*/

void    push_a(t_list **a, t_list **b);
void    push_b(t_list **a, t_list **b);
void    swap_a(t_list **a);
void    swap_b(t_list **b);
void    swap_all(t_list **a, t_list **b);

/*
** list_utils.c
*/

t_list  *create_lelem(int n);
t_list  *go_to_end(t_list *list);
void    append_element(t_list **head, int n);
void    destroy_list(t_list **list);
void    remove_element(t_list *l_elem);

/*
** utils.c
*/

int my_atoi(char *s);
void    sort_stack(t_list **list, int n_arg);
int find_median(t_list *head, int n_arg);


#endif