/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arz <arz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 23:08:43 by arz               #+#    #+#             */
/*   Updated: 2020/05/08 17:40:02 by arz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"


// int		*putcolor(int a, int b, int c)
// {
// 	int		*color;

// 	color = malloc(sizeof(int) * 3);
// 	color[0] = a;
// 	color[1] = b;
// 	color[2] = c;
// 	return (color);
// }

// int		**getcolor(char **av, int ac)
// {
// 	int		**color;

// 	color = malloc(sizeof(int *) * 5);
// 	if (ac > 4)
// 	{
// 		color[0] = malloc(sizeof(int *) * 3);
// 		color[0][0] = ft_atoi(av[2]);
// 		color[0][1] = ft_atoi(av[3]);
// 		color[0][2] = ft_atoi(av[4]);
// 	}
// 	else
// 		color[0] = putcolor(0x000000, 0x808080, 0xFFFFFF);
// 	color[1] = putcolor(0x0070e0, 0x42c6ff, 0xf3d85e);
// 	color[2] = putcolor(0xb9280e, 0x3d231a, 0x27160c);
// 	color[3] = putcolor(0x124511, 0x1a0f0f, 0x888181);
// 	color[4] = putcolor(0x0000ff, 0x00ff00, 0xff0000);
// 	return (color);
// }

// int		level_color(t_fdf *data)
// {

// 	if (z < e->z_min || z > e->z_max)
// 		return (0);
// 	if (z <= e->z_mid && z >= e->z_min)
// 	{
// 		color.color1 = e->color[e->cnum][0];
// 		color.color2 = e->color[e->cnum][1];
// 		return (findcolor(&color, z, e->z_min, e->z_mid));
// 	}
// 	else if (z <= e->z_max && z >= e->z_mid)
// 	{
// 		color.color1 = e->color[e->cnum][1];
// 		color.color2 = e->color[e->cnum][2];
// 		return (findcolor(&color, z, e->z_mid, e->z_max));
// 	}
// 	return (0);
// }

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

// int		linear_interpolation(t_fdf *data, int *x_y, t_coord *start, t_coord *end)
// {
// 	int		rgb[3];
// 	int		part1;
// 	int		part2;
// 	int		color;

// 	if (start->col == end->col)
// 		return (end->col);
// 	if (start->)
// 	part1 = color1 >> 16;
// 	part2 = color2 >> 16;
// 	color = ((((z - abs(data->min_z)) * (part2 - part1)) / (data->max_z - abs(data->min_z))) + part1) * 256 * 256;
// 	part1 = color1 >> 8;
// 	part2 = color2 >> 8;
// 	color += (((((z - abs(data->min_z)) * (part2 - part1)) / (data->max_z - abs(data->min_z))) + part1) * 256;
// 	part1 = color1 % 256;
// 	part2 = color2 % 256;
// 	color += ((((z - abs(data->min_z)) * (part2 - part1)) / (data->max_z - abs(data->min_z))) + part1);
// 	return (color);
// }
