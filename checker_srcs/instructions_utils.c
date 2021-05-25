#include "checker.h"

void	rev_rot_list(t_list **head)
{
	t_list	*tmp;
	t_list	*first;
	t_list	*last;

	tmp = *head;
	if (!(*head) || !(*head)->next)
		return ;
	tmp = go_to_end(tmp);
	first = tmp;
	first->next = *head;
	(*head)->prev = first;
	last = tmp->prev;
	last->next = 0;
	first->prev = 0;
	*head = first;
}

void	rot_list(t_list **head)
{
	t_list	*tmp;
	t_list	*first;
	t_list	*last;

	tmp = *head;
	if (!(*head) || !(*head)->next)
		return ;
	last = *head;
	first = (*head)->next;
	first->prev = 0;
	tmp = go_to_end(tmp);
	tmp->next = last;
	last->prev = tmp;
	last->next = 0;
	*head = first;
}

void	swap_list(t_list **head)
{
	t_list	*first;
	t_list	*second;

	first = (*head)->next;
	second = *head;
	second->next = (*head)->next->next;
	second->prev = first;
	first->prev = 0;
	first->next = second;
	(*head) = first;
}

void	rev_rot_all(t_list **a, t_list **b)
{
	rev_rot_list(a);
	rev_rot_list(b);
}
