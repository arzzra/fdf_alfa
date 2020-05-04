#include "./includes/fdf.h"

t_fdf	*malloc_t_fdf(void)
{
	t_fdf	*data;

	if (!(data = (t_fdf*)malloc(sizeof(t_fdf))))
	{
		data->matrix_map = NULL;
		data->mlx_pntr = NULL;
		data->x_size = 0;
		data->y_size = 0;

	}
	return (data);
}

void    print_map(t_fdf *data)
{
    int     i;
    int     j;

    i = 0;
    while (i < data->y_size)
    {
        j = 0;
        while (j < data->x_size)
        {
            printf("%3d",data->matrix_map[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}

int		main(int ac, char **av)
{
	t_fdf	*data;

	if (ac == 2 && (data = malloc_t_fdf()))
	{
		if (read_file(data, av[1]))
		{
            printf("GOOD\n");
            print_map(data);
        }
	}
	return 0;
}
