#ifndef HEADER_H
# define HEADER_H

typedef struct s_list
{
    int n;
    struct s_list   *prev;
    struct s_list   *next;
}   t_list;

#endif