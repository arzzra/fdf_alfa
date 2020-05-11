/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arz <arz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 14:54:36 by arz               #+#    #+#             */
/*   Updated: 2020/05/10 17:02:51 by arz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

static void	z_min_max(t_fdf *data)
{
	int		i;
	int		j;

	data->min_z = INT_MAX;
	data->max_z = INT_MIN;
	i = 0;
	while (i < data->map->y_size)
	{
		j = 0;
		while (j < data->map->x_size)
		{
			if (data->map->matrix_map[i][j] <=
					INT_MAX && data->map->matrix_map[i][j] > data->max_z)
				data->max_z = data->map->matrix_map[i][j];
			if (data->map->matrix_map[i][j] >=
					INT_MIN && data->map->matrix_map[i][j] < data->min_z)
				data->min_z = data->map->matrix_map[i][j];
			j++;
		}
		i++;
	}
	data->_3z = (data->min_z + data->max_z) / 3;
	data->_6z = data->_3z * 2;
}

int			init_fdf(t_fdf *data)
{
	if (!(data->cam = malloc_t_cam()))
		return (0);
	if (!(data->mlx_pntr = mlx_init()))
		return (0);
	if (!(data->win_pntr =
			mlx_new_window(data->mlx_pntr, X_S_WIN, Y_S_WIN, "FDF")))
		return (0);
	if (!(data->img = mlx_new_image(data->mlx_pntr, X_S_WIN, Y_S_WIN)))
		return (0);
	data->data_addr = mlx_get_data_addr(data->img, &(data->b_p_p),
	&(data->size_line), &(data->endian));
	z_min_max(data);
	data->cam->zoom = ret_min((X_S_WIN / data->map->x_size / 2),
		(Y_S_WIN / data->map->y_size / 2));
	return (1);
}
