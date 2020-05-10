/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arz <arz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 01:59:08 by arz               #+#    #+#             */
/*   Updated: 2020/05/08 19:53:04 by arz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"


void 	zoom(int key, t_fdf *data)
{
	int cur_zoom;
	int zoom_val;

	zoom_val = 5;
	cur_zoom = data->cam->zoom;
	if ((cur_zoom <= 5 && (key == 78 || key == 5)) || (cur_zoom >= 75 && (key == 69 || key == 4)))
		return;
	if (key == 69 || key == 65451 || key == 4)
		data->cam->zoom += zoom_val;
	else if (key == 78 || key == 65453 || key == 5)
		data->cam->zoom -= zoom_val;
	else
		data->cam->zoom = 40;
	draw(data);
}

void 	spin(int key, t_fdf *data)
{
	float spin_val;

	spin_val = 5 * M_PI / 180;
	if (key == 89 || key == 91 || key == 92)
		data->cam->x_angle -= spin_val;
	if (key == 86 || key == 89 || key == 83)
		data->cam->y_angle -= spin_val;
	if (key == 83 || key == 84 || key == 85)
		data->cam->x_angle += spin_val;
	if (key == 88 || key == 92 || key == 85)
		data->cam->y_angle += spin_val;
	if (key == 87)
	{
		data->cam->y_angle = 0;
		data->cam->x_angle = 0;
	}
	draw(data);
}

void	isometr(int key, t_fdf *data)
{
	if (key == 105 || key == 34)
	{
		if (data->cam->isometria >= 0 && data->cam->isometria < 2)
			data->cam->isometria += 1;
		else
			data->cam->isometria = 0;
	}
	draw(data);
}

int 	change_color(int key, t_fdf *data)
{
	int color;

	color = data->map->color_id;
	if (key == 47)
	{
		if (color == 4)
			data->map->color_id = 0;
		else
			data->map->color_id += 1;
	}
	else
	{
		if (color == 0)
			data->map->color_id = 4;
		else
			data->map->color_id -= 1;
	}
	draw(data);
	return (0);
}

int move(int key, t_fdf *data)
{
	int move_val;

	printf("data->cam->x_move -- %d ----- data->cam->y_move -- %d\n", data->cam->x_move, data->cam->y_move);
	move_val = 6;
	if (key == 126)
		data->cam->y_move -= move_val;
	else if (key == 125)
		data->cam->y_move += move_val;
	else if (key == 123)
		data->cam->x_move -= move_val;
	else
		data->cam->x_move += move_val;
	printf("data->cam->x_move -- %d ----- data->cam->y_move -- %d\n", data->cam->x_move, data->cam->y_move);
	draw(data);
	return (0);
}

int change_deep(int key, t_fdf *data)
{
	int deep_val;

	printf("data->cam->z_deep -- %f \n", data->cam->z_deep);
	deep_val = 10;
	if (key == 21)
		data->cam->z_deep -= deep_val;
	else if (key == 22)
		data->cam->z_deep += deep_val;
	else
		data->cam->y_move = 0;
	draw(data);
	return (0);
}

int		keys_hook(int key, t_fdf *data)
{
	printf("keys = %d \n", key);
	if (key == 53)
		exit(0);
	else if (key >= 123 && key <= 126)
		move(key, data);
	else if (key == 105 || key == 34)
		isometr(key, data);
	else if (key == 69 || key == 78 || key == 82 || key == 65451 || key == 65453)
		zoom(key, data);
	else if (key <= 92 && key >= 83 && key != 90)
		spin(key, data);
	else if (key == 47 || key == 43)
		change_color(key, data);
	else if (key >= 21 && key <= 23)
		change_deep(key, data);
	return (0);
}
