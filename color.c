/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arz <arz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 23:08:43 by arz               #+#    #+#             */
/*   Updated: 2020/05/09 00:01:03 by arz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"


int		*putcolor(int a, int b, int c)
{
	int		*color;

	if (!(color = malloc(sizeof(int) * 3)))
		return (NULL);
	color[0] = a;
	color[1] = b;
	color[2] = c;
	return (color);
}

int		**getcolor(void)
{
	int		**color;
	int		i;

	if (!(color = malloc(sizeof(int *) * 5)))
		return (NULL);
	if (!(color[0] = putcolor(0x000000, 0x808080, 0xFFFFFF)))
		return (NULL);
	if (!(color[1] = putcolor(0x0070e0, 0x42c6ff, 0xf3d85e)))
		return (NULL);
	if (!(color[2] = putcolor(0xb9280e, 0x3d231a, 0x27160c)))
		return (NULL);
	if (!(color[2] = putcolor(0xb9280e, 0x3d231a, 0x27160c)))
		return (NULL);
	if (!(color[3] = putcolor(0x124511, 0x1a0f0f, 0x888181)))
		return (NULL);
	if (!(color[4] = putcolor(0x0000ff, 0x00ff00, 0xff0000)))
		return (NULL);
	return (color);
}

int		level_color(t_fdf *data, int z)
{
	if (z <= data->_3z && z >= data->min_z)
	{
		return (data->map->colors[data->map->color_id][0]);
	}
	else if (z <= data->_6z && z > data->_3z)
	{
		return (data->map->colors[data->map->color_id][1]);
	}
	else if (z >= data->_6z && z > data->_6z)
	{
		return (data->map->colors[data->map->color_id][2]);
	}
	return (0);
}

double	t_calculate(int a, int b, int c)
{
	int		chis;
	int		znam;

	chis = c - a;
	znam = b - a;
	if (znam == 0)
		return (1.0);
	else
		return ((double)chis / znam);
}

int		linear_interpolation(t_coord *start, t_coord *end, int *x_y_current, int *delta)
{
	int		color[3];
	int		color2;
	double	t;
	int		part1;
	int		part2;

	if (start->col == end->col)
		return (end->col);
	if (delta[0] > delta[1])
		t = t_calculate(start->x, end->x, x_y_current[0]);
	else
		t = t_calculate(start->y, end->y, x_y_current[1]);
	part1 = (start->col >> 16) & 0xFF;
	part2 = (end->col >> 16) & 0xFF;
	color[0] = (int)(((1 - t) * part1 + t * part2));
	part1 = (start->col >> 8) & 0xFF;
	part2 = (end->col >> 8) & 0xFF;
	color[1] = (int)(((1 - t) * part1 + t * part2));
	part1 = start->col & 0xFF;
	part2 = end->col & 0xFF;
	color[2] = (int)(((1 - t) * part1 + t * part2));
	return ((color[0] << 16) | (color[1] << 8) | color[2]);
}
