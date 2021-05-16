#include "header.h"

int my_atoi(char *s)
{
    long int    n;
    int minus;

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
/*
int check_order(t_list *list, int first_id, int last_id)
{
    //todo check if elements are in order
    return (1);
}
*/
