/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arz <arz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 18:07:24 by arz               #+#    #+#             */
/*   Updated: 2020/05/12 23:57:52 by arz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	init_delta_error_sign(t_coord *a, t_coord *b,
	int *delta, int *sign)
{
	delta[0] = abs(b->x - a->x);
	delta[1] = abs(b->y - a->y);
	sign[0] = a->x < b->x ? 1 : -1;
	sign[1] = a->y < b->y ? 1 : -1;
}

void		pixel_putting(t_fdf *data, int *x_y, int color)
{
	int		pos;

	if (x_y[0] >= 0 && x_y[0] < X_S_WIN && x_y[1] >= 0 && x_y[1] < Y_S_WIN)
	{
		pos = (x_y[0] * data->b_p_p / 8) + (x_y[1] * data->size_line);
		data->data_addr[pos] = color;
		data->data_addr[pos + 1] = color >> 8;
		data->data_addr[pos + 2] = color >> 16;
	}
}

void		paint_line(t_fdf *data, t_coord a, t_coord b)
{
	int		delta[2];
	int		error[2];
	int		sign[2];
	int		x_y[2];

	init_delta_error_sign(&a, &b, delta, sign);
	x_y[0] = a.x;
	x_y[1] = a.y;
	error[0] = delta[0] - delta[1];
	while (x_y[0] != b.x || x_y[1] != b.y)
	{
		pixel_putting(data, x_y, linear_interpolation(&a, &b, x_y, delta));
		if ((error[1] = error[0] * 2) > (-delta[1]))
		{
			error[0] -= delta[1];
			x_y[0] += sign[0];
		}
		if (error[1] < delta[0])
		{
			error[0] += delta[0];
			x_y[1] += sign[1];
		}
	}
}

void		draw(t_fdf *data)
{
	int		x;
	int		y;

	ft_bzero(data->data_addr, X_S_WIN * Y_S_WIN * (data->b_p_p / 8));
	y = 0;
	while (y < data->map->y_size)
	{
		x = 0;
		while (x < data->map->x_size)
		{
			if (x < data->map->x_size - 1)
				paint_line(data, init_points(data, x, y),
					init_points(data, x + 1, y));
			if (y < data->map->y_size - 1)
				paint_line(data, init_points(data, x, y),
					init_points(data, x, y + 1));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_pntr, data->win_pntr, data->img, 0, 0);
	print_menu(data);
}
