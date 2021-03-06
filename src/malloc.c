/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arz <arz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 02:57:39 by arz               #+#    #+#             */
/*   Updated: 2020/05/12 23:57:52 by arz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_map	*malloc_t_map(void)
{
	t_map	*mp;

	if ((mp = (t_map*)malloc(sizeof(t_map))))
	{
		mp->matrix_map = NULL;
		mp->x_size = -1;
		mp->y_size = 0;
		mp->color_id = 0;
		if (!(mp->colors = getcolor()))
		{
			free(mp);
			return (NULL);
		}
	}
	return (mp);
}

t_cam	*malloc_t_cam(void)
{
	t_cam	*cm;

	if ((cm = (t_cam*)malloc(sizeof(t_cam))))
	{
		cm->click = 0;
		cm->zoom = 1;
		cm->z_deep = 1;
		cm->x_move = 0;
		cm->y_move = 0;
		cm->x_angle = 0;
		cm->y_angle = 0;
		cm->z_angle = 0;
		cm->isometria = 0;
	}
	return (cm);
}

t_fdf	*malloc_t_fdf(void)
{
	t_fdf	*data;

	if ((data = (t_fdf*)malloc(sizeof(t_fdf))))
	{
		data->img = NULL;
		data->data_addr = NULL;
		data->b_p_p = 0;
		data->size_line = 0;
		data->endian = 0;
		data->cam = NULL;
		data->mlx_pntr = NULL;
		data->win_pntr = NULL;
		if ((data->map = malloc_t_map()))
			return (data);
	}
	return (NULL);
}
