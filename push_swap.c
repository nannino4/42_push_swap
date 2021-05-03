#include "header.h"

int atoi(char *s)
{
    long int    n;
    int minus;

    n = 0;
    minus = 1;
    if (!s)
    {
        write(1, "\n\nerror\n\natoi found a null pointer as argument\n", 47);
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

t_list  *create_lelem(int n)
{
    t_list  *elem;

    elem = malloc(sizeof(t_list));
    if (!elem)
    {
        write(1, "\n\nerror\n\nallocation failed\n", 27);
        exit(1);
    }
    elem->prev = 0;
    elem->next = 0;
    elem->n = n;
    return elem; 
}

t_list  *go_to_end(t_list *list)
{
    while (list->next)
    {
        list = list->next;
    }
    return (list);
}

void    append_element(t_list *head, char *string)
{
    if (!head)
    {
        head = create_lelem(atoi(string));
        return ;
    }
    head = go_to_end(head);
    head->next = create_lelem(atoi(string));
    head->next->prev = head;
}

void    sort_stack(t_list *list)
{
    int n_tmp;
    t_list  *l_tmp;

    l_tmp = list;
    while(l_tmp->next)
        {
        while (list->next)
        {
            if (list->n > list->next->n)
            {
                n_tmp = list->n;
                list->n = list->next->n;
                list->next->n = n_tmp;
            }
            list = list->next;
        }
        l_tmp = l_tmp->next;
    }
}

int find_median(t_list *head, int n_arg)
{
    n_arg /= 2;
    while (n_arg--)
    {
        head = head->next;
    }
    return (head->n);
}

void    destroy_list(t_list *list)
{
    t_list  *tmp;

    while (list)
    {
        tmp = list;
        list = list->next;
        free(tmp);
    }
}

t_list  *create_b(t_list *a)
{
    t_list  *b;

    //todo
    return (b);
}

void    order_a_and_b(t_list *a, t_list *b)
{
    //todo
}

int main(int argc, char **argv)
{
    int n_arg;
    int m;
    t_list  *a;
    t_list  *b;

    a = 0;
    b = 0;
    n_arg = argc - 1;
    if (argc < 2)
        return (0);
    while (--argc)
    {
        append_element(a, argv[n_arg - argc - 1]);
        append_element(b, argv[n_arg - argc - 1]);
    }
    sort_stack(b);
    m = find_median(b, n_arg);
    destroy_list(b);
    b = create_b(a);
    order_a_and_b(a, b);
}
