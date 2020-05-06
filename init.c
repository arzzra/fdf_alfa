/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arz <arz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 14:54:36 by arz               #+#    #+#             */
/*   Updated: 2020/05/07 01:02:58 by arz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

int		init_fdf(t_fdf *data)
{
	if (!(data->cam = malloc_t_cam()))
		return (0);
	if (!(data->mlx_pntr = mlx_init()))
		return (0);
	if (!(data->win_pntr = mlx_new_window(data->mlx_pntr, X_S_WIN, Y_S_WIN, "FDF")))
		return (0);
	if (!(data->img = mlx_new_image(data->mlx_pntr, X_S_WIN, Y_S_WIN)))
		return (0);
	data->data_addr = mlx_get_data_addr(data->img, &(data->b_p_p),
	&(data->size_line), &(data->endian));
	data->cam->zoom = ret_min((X_S_WIN / data->map->x_size / 2), (Y_S_WIN / data->map->y_size / 2));
	return (1);
}
