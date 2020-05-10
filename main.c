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

int		mouse_scroll(int button, int x, int y, t_fdf *data)
{
	(void)x;
	if (y < 0)
		return (0);
	if (button == 4 || button == 5 || button == 3)
		zoom(button, data);
	return (0);
}

void	print_menu(t_fdf *data)
{
	char *menu;

	menu = "Numpad: spin";
	mlx_string_put(data->mlx_pntr, data->win_pntr, 10, 5, 0x03fc35, menu);
	menu = "Up, down, right, left: move";
	mlx_string_put(data->mlx_pntr, data->win_pntr, 10, 20, 0x03fc35, menu);
	menu = "+, -, 0, mouse scroll: zoom";
	mlx_string_put(data->mlx_pntr, data->win_pntr, 10, 35, 0x03fc35, menu);
	menu = "i : isometry";
	mlx_string_put(data->mlx_pntr, data->win_pntr, 10, 50, 0x03fc35, menu);
	menu = "<, > : color change";
	mlx_string_put(data->mlx_pntr, data->win_pntr, 10, 65, 0x03fc35, menu);
	menu = "4, 5, 6: deep change";
	mlx_string_put(data->mlx_pntr, data->win_pntr, 10, 80, 0x03fc35, menu);
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
				mlx_hook(data->win_pntr, 2, 0, keys_hook, data);
				// mlx_expose_hook(e.win, expose_hook, &e);
				mlx_hook(data->win_pntr, 4, 0, mouse_scroll, data);
				mlx_loop(data->mlx_pntr);
			}
		}
	}
	return 0;
}
