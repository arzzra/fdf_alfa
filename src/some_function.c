/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arz <arz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 16:09:29 by arz               #+#    #+#             */
/*   Updated: 2020/05/12 23:57:52 by arz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ret_min(int a, int b)
{
	return (a >= b ? b : a);
}

t_coord	init_points(t_fdf *data, int x, int y)
{
	t_coord	crd;

	crd.x = x;
	crd.y = y;
	crd.z = data->map->matrix_map[y][x];
	crd.col = level_color(data, crd.z);
	img_projection(data, &crd);
	return (crd);
}
