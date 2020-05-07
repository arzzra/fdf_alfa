/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arz <arz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 01:59:08 by arz               #+#    #+#             */
/*   Updated: 2020/05/07 02:08:59 by arz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

void 	zoom(int key, t_fdf *data)
{
	int cur_zoom;

	cur_zoom = data->cam->zoom;
	printf("zoom: %d\n", cur_zoom);
	if ((cur_zoom <= 5 && key == 78) || (cur_zoom >= 75 && key == 69))
		return;
	mlx_clear_window(data->mlx_pntr, data->win_pntr);
	if (key == 69)
		data->cam->zoom += 5;
	else if (key == 78)
		data->cam->zoom -= 5;
	else
		data->cam->zoom = 40;
	draw(data);
}

int		keys_hook(int key, t_fdf *data)
{
	if (key == 53)
		exit(0);
	else if (key == 69 || key == 78 || key == 82)
		zoom(key, data);
	printf("%d\n", key);
	return (0);
}
