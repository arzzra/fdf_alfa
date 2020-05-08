/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arz <arz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 16:09:29 by arz               #+#    #+#             */
/*   Updated: 2020/05/08 17:02:37 by arz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

int		ret_min(int a, int b)
{
	return (a >= b ? b: a);
}

t_coord	init_points(t_fdf *data, int x, int y)
{
	t_coord	crd;

	crd.x = x;
	crd.y = y;
	crd.z = data->map->matrix_map[y][x];
	if (crd.z > 0)
		crd.col = 0x9A1F6A;
	else
		crd.col = 0xF3AF3D;
	img_projection(data, &crd);
	return (crd);
}
