/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arz <arz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 01:59:08 by arz               #+#    #+#             */
/*   Updated: 2020/05/12 23:57:52 by arz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	zoom(int key, t_fdf *data)
{
	int cur_zoom;
	int zoom_val;

	zoom_val = 5;
	cur_zoom = data->cam->zoom;
	if ((cur_zoom <= 5 &&
			(key == ZOOM_MINUS_L || key == ZOOM_MINUS_M || key == 5))
				|| (cur_zoom >= 100 && (key == ZOOM_PLUS_L || key == ZOOM_PLUS_M
					|| key == 4)))
		return ;
	if (key == ZOOM_PLUS_L || key == ZOOM_PLUS_M || key == 4)
		data->cam->zoom += zoom_val;
	else if (key == ZOOM_MINUS_L || key == ZOOM_MINUS_M || key == 5)
		data->cam->zoom -= zoom_val;
	else
		data->cam->zoom = ret_min((X_S_WIN / data->map->x_size / 2),
			(Y_S_WIN / data->map->y_size / 2));
	draw(data);
}

void	spin(int key, t_fdf *data)
{
	float spin_val;

	spin_val = 0.05;
	if (key == NUMPAD_8_L || key == NUMPAD_8_M)
		data->cam->x_angle -= spin_val;
	else if (key == NUMPAD_2_L || key == NUMPAD_2_M)
		data->cam->x_angle += spin_val;
	else if (key == NUMPAD_4_L || key == NUMPAD_4_M)
		data->cam->y_angle -= spin_val;
	else if (key == NUMPAD_6_L || key == NUMPAD_6_M)
		data->cam->y_angle += spin_val;
	else if (key == NUMPAD_1_L || key == NUMPAD_1_M)
		data->cam->z_angle += spin_val;
	else if (key == NUMPAD_3_L || key == NUMPAD_3_M)
		data->cam->z_angle -= spin_val;
	else if (key == NUMPAD_5_L || key == NUMPAD_5_M)
	{
		data->cam->x_angle = 0;
		data->cam->y_angle = 0;
		data->cam->z_angle = 0;
	}
	draw(data);
}

int		move(int key, t_fdf *data)
{
	int move_val;

	move_val = 6;
	if (key == UP_M || key == UP_L)
		data->cam->y_move -= move_val;
	else if (key == DOWN_M || key == DOWN_L)
		data->cam->y_move += move_val;
	else if (key == LEFT_M || key == LEFT_L)
		data->cam->x_move -= move_val;
	else
		data->cam->x_move += move_val;
	draw(data);
	return (0);
}

int		change_deep(int key, t_fdf *data)
{
	float deep_val;
	float cur_deep;

	deep_val = 0.05;
	cur_deep = data->cam->z_deep;
	printf("data->cam->z_deep -- %f \n", cur_deep);
	if (cur_deep >= 10.0 && (key == DEEP_MINUS_L || key == DEEP_MINUS_M))
		return (0);
	if (cur_deep <= 0.1 && (key == DEEP_PLUS_L || key == DEEP_PLUS_M))
		return (0);
	if (key == DEEP_PLUS_L || key == DEEP_PLUS_M)
		data->cam->z_deep -= deep_val;
	else if (key == DEEP_MINUS_L || key == DEEP_MINUS_M)
		data->cam->z_deep += deep_val;
	draw(data);
	return (0);
}

int		keys_hook(int key, t_fdf *data)
{
	if (key == ESC_L || key == ESC_M)
		exit(0);
	else if (key == DEEP_MINUS_L || key == DEEP_MINUS_M ||
			key == DEEP_PLUS_L || key == DEEP_PLUS_M)
		change_deep(key, data);
	else if ((key >= LEFT_M && key <= UP_M) || (key >= LEFT_L && key <= DOWN_L))
		move(key, data);
	else if (key == ISOMETRY_M || key == ISOMETRY_L)
		isometry(data);
	else if (key == ZOOM_PLUS_M || key == ZOOM_MINUS_M || key == ZOOM_ZERO_M
			|| key == ZOOM_PLUS_L || key == ZOOM_MINUS_L || key == ZOOM_ZERO_L)
		zoom(key, data);
	else if ((key <= NUMPAD_9_M && key >= NUMPAD_1_M)
			|| (key >= NUMPAD_4_L && key <= NUMPAD_1_L))
		spin(key, data);
	else if (key == COLOR_M || key == COLOR_L)
		change_color(data);
	return (0);
}
