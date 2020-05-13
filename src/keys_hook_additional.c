/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_hook_additional.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arz <arz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 01:59:08 by arz               #+#    #+#             */
/*   Updated: 2020/05/12 23:57:52 by arz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	isometry(t_fdf *data)
{
	if (data->cam->isometria >= 0 && data->cam->isometria < 2)
		data->cam->isometria += 1;
	else
		data->cam->isometria = 0;
	data->cam->x_angle = 0;
	data->cam->y_angle = 0;
	data->cam->z_angle = 0;
	draw(data);
}

int		change_color(t_fdf *data)
{
	int color;

	color = data->map->color_id;
	if (color == 5)
		data->map->color_id = 0;
	else
		data->map->color_id += 1;
	draw(data);
	return (0);
}
