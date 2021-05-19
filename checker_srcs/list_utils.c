#include "checker.h"

t_list	*create_lelem(int n, int index)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (!elem)
	{
		write(1, "\n\nerror\n\nallocation failed\n", 27);
		exit(1);
	}
	elem->prev = 0;
	elem->next = 0;
	elem->n = n;
	elem->index = index;
	return (elem);
}

t_list	*go_to_end(t_list *list)
{
	while (list->next)
	{
		list = list->next;
	}
	return (list);
}

void	append_element(t_list **head, int n, int index)
{
	t_list	*l_tmp;

	l_tmp = *head;
	if (!*head)
	{
		*head = create_lelem(n, index);
		return ;
	}
	l_tmp = go_to_end(l_tmp);
	l_tmp->next = create_lelem(n, index);
	l_tmp->next->prev = l_tmp;
}

void	destroy_list(t_list **list)
{
	t_list	*tmp;

	while (*list)
	{
		tmp = *list;
		*list = (*list)->next;
		tmp->prev = 0;
		tmp->next = 0;
		tmp->index = 0;
		tmp->n = 0;
		free(tmp);
	}
}

void	remove_element(t_list *l_elem)
{
	if (l_elem->prev)
	{
		l_elem->prev->next = l_elem->next;
	}
	if (l_elem->next)
	{
		l_elem->next->prev = l_elem->prev;
	}
	free(l_elem);
}
