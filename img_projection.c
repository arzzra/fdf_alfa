/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_projection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arz <arz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 15:55:48 by arz               #+#    #+#             */
/*   Updated: 2020/05/08 16:53:58 by arz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"




static void	isometr(int *x, int *y, int z)
{
	int prev_x;
	int prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(0.523599);
	*y = -z + (prev_x + prev_y) * sin(0.523599);
}

void	img_projection(t_fdf *data, t_coord *crd)
{
	crd->x *= data->cam->zoom;
	crd->y *= data->cam->zoom;
	crd->z *= data->cam->zoom;
	crd->x -= (data->map->x_size * data->cam->zoom) / 2;
	crd->y -= (data->map->y_size * data->cam->zoom) / 2;
	if (data->cam->isometria > 0)
		isometr(&(crd->x), &(crd->y), crd->z);
	crd->x += (X_S_WIN) / 2 + data->cam->x_move;
	crd->y += (Y_S_WIN + data->map->y_size * data->cam->zoom) / 2 + data->cam->y_move;
}
