 #include "./includes/fdf.h"
#include <math.h>
#include <stdio.h>
#define MAX(A, B) (A > B ? A : B)

float	fmodule(float i)
{
    return (i < 0) ? -i : i;
}

void	isometric(float *x, float *y, int z)
{
    double gradus;
    int previous_x;
    int previous_y;
    previous_x = *x;
    previous_y = *y;

    gradus = 0.523599;
    *x = (float)(((previous_x) - (previous_y)) * cos(gradus));
    *y = (float)(((previous_x) + (previous_y)) * sin(gradus)- z);
}


void	line_l(float x,float y,float x1,float y1, t_fdf *data) {
    float step_x;
    float step_y;
    float max;
    int z;
    int z1;
    int color;
    int g = 400;

    z = data->matrix_map[(int)y][(int)x];
    z1 = data->matrix_map[(int)y1][(int)x1];

    x1 *= data->zoom;
    y1 *= data->zoom;
    x *= data->zoom;
    y *= data->zoom;

    color = (z || z1) ? 0xe80c0c : 0xffffff;

    isometric(&x, &y, z);
    isometric(&x1, &y1, z1);
    x1 += g;
    y1 += g;
    x += g;
    y += g;
    step_x = x1 - x;
    step_y = y1 - y;
    max = MAX(fmodule(step_x), fmodule(step_y));
    step_x /= max;
    step_y /= max;
    while ((int) (x - x1) || (int) (y - y1)) {
        mlx_pixel_put(data->mlx_pntr, data->win_pntr, (int)x, (int)y, color);
        x += step_x;
        y += step_y;
    }
}

//void	print_menu(t_fdf *data)
//{
//    char *menu;
//
//    menu = "←, →, ↑, ↓ - перемещение в пространстве";
//    mlx_string_put(data->mlx_pntr, data->win_pntr, 10, 5, 0x03fc35, menu);
//    menu = "5, spase: 3d/2d mode; +, -: zoom";
//    mlx_string_put(data->mlx_pntr, data->win_pntr, 10, 20, 0x03fc35, menu);
//    menu = "8, 2: z-scale; 4, 6: rotation";
//    mlx_string_put(data->mlx_pntr, data->win_pntr, 10, 35, 0x03fc35, menu);
//    menu = "f: full screen mode";
//    mlx_string_put(data->mlx_pntr, data->win_pntr, 10, 50, 0x03fc35, menu);
//}



void	draw_line(t_fdf *data)
{
    int		y;
    int		x;


    //print_menu(data);
    y = 0;
    while (y < data->y_size)
    {
        x = 0;
        while (x < data->x_size)
        {
            if (x < data->x_size - 1)
                line_l((float)x,(float)y,(float)(x+1),(float)y, data);
            if (y < data->y_size - 1)
                line_l((float)x,(float)y,(float)x ,(float)(y + 1), data);
            x++;
        }
        y++;
    }
}

int     button_handler(int button, t_fdf *data)
{
    if (button == 53)
    {
        mlx_destroy_window(data->mlx_pntr, data->win_pntr);
        free(data);
        exit(0);
    }
//    if (button == 69)
//    {
//        mlx_clear_window(data->mlx_pntr, data->win_pntr);
//        data->zoom += 5;
//        draw_line(data);
//    }
//    if (button == 78)
//    {
//        mlx_clear_window(data->mlx_pntr, data->win_pntr);
//        data->zoom -= 5;
//        draw_line(data);
//    }
//    printf("кнопка - %d\n", button);
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
		data->zoom = 10;
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
            //printf("%3d",data->matrix_map[i][j]);
            j++;
        }
        //printf("\n");
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
            //printf("GOOD\n");
            print_map(data);
            init_win(data);
            draw_line(data);
            //printf("%d %d", data->x_size, data->y_size);
            mlx_key_hook(data->win_pntr, button_handler, data);
            mlx_loop(data->mlx_pntr);
        }
	}
	return 0;
}
