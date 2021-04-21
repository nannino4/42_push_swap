#include "header.h"

int my_atoi(char *s)
{
    long int n;

    return ((int)n);
}

int main(int argc, char **argv)
{
    int *stack[2];
    int i;
    int size[2];

    size[0] = argc - 1;
    size[1] = 0;
    stack[0] = (int *)malloc(sizeof(int) * argc - 1);
    stack[1] = (int *)malloc(sizeof(int) * argc - 1);
    if (!stack[0] || !stack[1])
    {
        write(1, "\nerror\nallocation of stack 'a' and/or 'b' failed\n\n", 44);
        return (1);
    }
    i = 0;
    while (i + 1 < argc)
    {
        stack[0][i] = my_atoi(argv[i + 1]);
        i++;
    }
    return (0);
}
