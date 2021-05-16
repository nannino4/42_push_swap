#include "header.h"

void    init_data(t_data *data, int argc)
{
    data->a = 0;
    data->b = 0;
    data->first_id = 0;
    data->last_id = argc - 2;
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
    set_indexes(data.a, &data.b, data.last_id + 1);
    //if (check_order(data.a, 0, data.last_id))
    //    return (0);
    if (data.last_id - data.first_id >= 5)
    {
        first_a_to_b(&data.a, &data.b, data.first_id, (data.last_id + data.first_id) / 2);
        data.first_id = (data.last_id + data.first_id) / 2 + 1;
        while (data.last_id - data.first_id >= 5)
        {
            from_a_to_b(&data.a, &data.b, data.first_id, (data.last_id + data.first_id) / 2);
            data.first_id = (data.last_id + data.first_id) / 2 + 1;
        }
    }
    //sort_a(&data.a, &data.b, data.first_id, data.last_id);
}
