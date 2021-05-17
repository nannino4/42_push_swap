#include "header.h"

void    init_data(t_data *data, int argc)
{
    data->a = 0;
    data->b = 0;
    data->first = 0;
    data->last = argc - 2;
}

int main(int argc, char **argv)
{
    t_data data;

    init_data(&data, argc);
    if (argc < 2)
        return (0);
    while (--argc)
    {
        append_element(&data.a, my_atoi(*(++argv)), 0);
        append_element(&data.b, my_atoi(*argv), 0);
    }
    set_indexes(data.a, &data.b, data.last + 1);
    //if (check_order(data.a, 0, data.last))
    //    return (0);
    if (data.last - data.first < 3)
    {
        first_a_to_b(&data.a, &data.b, data.first, (data.last + data.first) / 2);
        data.first = (data.last + data.first) / 2 + 1;
        while (data.last - data.first >= 3)
        {
            from_a_to_b(&data.a, &data.b, data.first, (data.last + data.first) / 2);
            data.first = (data.last + data.first) / 2 + 1;
        }
    }
    //else
        //sort_a(&data.a, &data.b, data.first, data.last);
}
