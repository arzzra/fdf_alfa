#include "./includes/fdf.h"


void    print_map(t_fdf *data)
{
    int     i;
    int     j;

    i = 0;
    while (i < data->map->y_size)
    {
        j = 0;
        while (j < data->map->x_size)
        {
            printf("% d",data->map->matrix_map[i][j]);
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
			// print_map(data);
			if (init_fdf(data))
			{
				printf("bpp = %d  s_lize = %d ENDIAN = %d \n" , data->b_p_p, data->size_line, data->endian);
				draw(data);
				mlx_key_hook(data->win_pntr, keys_hook, data);
				// mlx_expose_hook(e.win, expose_hook, &e);
				mlx_loop(data->mlx_pntr);
			}
		}
	}
	return 0;
}
