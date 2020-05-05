 #include "./includes/fdf.h"

int     button_handler(int button, t_fdf *data)
{
    if (button == 53)
    {
        mlx_destroy_window(data->mlx_pntr, data->win_pntr);
        free(data);
        exit(0);
    }
    return (0);
}

void init_win(t_fdf *data)
{
    data->mlx_pntr = mlx_init();
    data->win_pntr = mlx_new_window(data->mlx_pntr, data->win_width, data->win_height, "FDF");
}


t_fdf	*malloc_t_fdf(void)
{
	t_fdf	*data;

	if ((data = (t_fdf*)malloc(sizeof(t_fdf))))
	{
		data->matrix_map = NULL;
		data->x_size = 0;
		data->y_size = 0;
        data->win_width = 1200;
        data->win_height = 800;
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
            init_win(data);
            mlx_key_hook(data->win_pntr, button_handler, data);
            mlx_loop(data->mlx_pntr);
        }
	}
	return 0;
}
