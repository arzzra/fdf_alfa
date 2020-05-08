/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arz <arz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 01:59:08 by arz               #+#    #+#             */
/*   Updated: 2020/05/08 01:53:58 by arz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"


void 	zoom(int key, t_fdf *data)
{
	int cur_zoom;
	int zoom_val;

	zoom_val = 5;
	cur_zoom = data->cam->zoom;
	if ((cur_zoom <= 5 && key == 78) || (cur_zoom >= 75 && key == 69))
		return;
	mlx_clear_window(data->mlx_pntr, data->win_pntr);
	if (key == 69 || key == 65451)
		data->cam->zoom += zoom_val;
	else if (key == 78 || key == 65453)
		data->cam->zoom -= zoom_val;
	else
		data->cam->zoom = 40;
	draw(data);
}

void 	move(int key, t_fdf *data)
{
	int move_val;

	move_val = 55;
	printf("keys = %d \n", key);
	mlx_clear_window(data->mlx_pntr, data->win_pntr);
	if (key == 89 || key == 91 || key == 92)
		data->cam->y_move -= move_val;
	if (key == 86 || key == 89 || key == 83)
		data->cam->x_move -= move_val;
	if (key == 83 || key == 84 || key == 85)
		data->cam->y_move += move_val;
	if (key == 88 || key == 92 || key == 85)
		data->cam->x_move += move_val;
	if (key == 87)
	{
		data->cam->x_move = 0;
		data->cam->y_move = 0;
	}
	draw(data);
}


int		keys_hook(int key, t_fdf *data)
{
	printf("keys = %d \n", key);
	if (key == 53)
		exit(0);
	else if (key == 69 || key == 78 || key == 82 || key == 65451 || 65453)
		zoom(key, data);
	else if (key <= 92 && key >= 83 && key != 90)
		move(key, data);
	return (0);
}
