/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_projection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arz <arz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 15:55:48 by arz               #+#    #+#             */
/*   Updated: 2020/05/09 00:12:21 by arz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"




static void	isometria(t_fdf *data, t_coord *crd)
{
	int prev_x;
	int prev_y;

	prev_x = crd->x;
	prev_y = crd->y;
	if (data->cam->isometria == 1)
	{
		crd->x = (prev_x - prev_y) * cos(0.523599);
		crd->y = -1 * crd->z + (prev_x + prev_y) * sin(0.523599);
	}
	else if (data->cam->isometria == 2)
	{
		crd->x = (prev_x - prev_y) * cos(0.46373398);
		crd->y = -1 * crd->z + (prev_x + prev_y) * sin(0.46373398);
	}
}


void	x_rotate(t_fdf *data, t_coord *crd)
{
	int prev_y;

	prev_y = crd->y;
	crd->y = prev_y * cos(data->cam->x_angle) + crd->z * sin(data->cam->x_angle);
	crd->z = -1 * prev_y * sin(data->cam->x_angle) + crd->z * cos(data->cam->x_angle);
}

void	y_rotate(t_fdf *data, t_coord *crd)
{
	int prev_x;

	prev_x = crd->x;
	crd->x = prev_x * cos(data->cam->y_angle) + crd->z * sin(data->cam->y_angle);
	crd->z = -1 * prev_x * sin(data->cam->x_angle) + crd->z * cos(data->cam->x_angle);
}

void	z_rotate(t_fdf *data, t_coord *crd)
{
	int prev_x;
	int prev_y;

	prev_x = crd->x;
	prev_y = crd->y;
	crd->x = prev_x * cos(data->cam->z_angle) - prev_y * sin(data->cam->z_angle);
	crd->y = prev_x * sin(data->cam->z_angle) + prev_y * cos(data->cam->z_angle);
}

void	img_projection(t_fdf *data, t_coord *crd)
{
	crd->x *= data->cam->zoom;
	crd->y *= data->cam->zoom;
	crd->z *= data->cam->zoom;
	crd->x -= (data->map->x_size * data->cam->zoom) / 2;
	crd->y -= (data->map->y_size * data->cam->zoom) / 2;
	x_rotate(data, crd);
	y_rotate(data, crd);
	z_rotate(data, crd);
	if (data->cam->isometria > 0)
		isometria(data, crd);
	crd->x += (X_S_WIN) / 2 + data->cam->x_move;
	crd->y += (Y_S_WIN + data->map->y_size * data->cam->zoom) / 3 + data->cam->y_move;
}
