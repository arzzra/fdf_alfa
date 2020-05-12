/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_free.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arz <arz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 03:12:07 by arz               #+#    #+#             */
/*   Updated: 2020/05/12 23:57:52 by arz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		free_lst(t_list *lst)
{
	t_list	*lsk;

	while (lst)
	{
		lsk = lst;
		lst = lst->next;
		free(lsk->content);
		free(lsk);
	}
	return (0);
}

void	free_int(int **massiv, int x)
{
	int		i;

	i = 0;
	while (i < x)
	{
		free(massiv[i]);
		i++;
	}
	free(massiv);
}

void	free_everything(t_fdf *data)
{
	if (data->map->matrix_map)
		free_int(data->map->matrix_map, data->map->y_size);
	if (data->map->colors)
		free_int(data->map->colors, 6);
	if (data->cam)
		free(data->cam);
	if (data->map)
		free(data->map);
	free(data);
}
