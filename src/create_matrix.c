/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arz <arz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 23:08:43 by arz               #+#    #+#             */
/*   Updated: 2020/05/09 00:01:03 by arz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*skip_prev_digits(char *str)
{
	int		i;
	int		flg;

	i = 0;
	flg = 0;
	while (str[i] != '\0')
	{
		if (flg == 1 && str[i] == ' ')
			return (&(str)[i]);
		else if (str[i] == '-' || (str[i] >= '0' && str[i] <= '9'))
			flg = 1;
		i++;
	}
	return (NULL);
}

void	list_to_matrix(int *matrix, t_list *lst, int x_size)
{
	int		i;
	char	*str;

	i = 0;
	str = (char*)lst->content;
	while (i < x_size && str)
	{
		matrix[i] = ft_atoi(str);
		str = skip_prev_digits(str);
		i++;
	}
}

int		create_matrix(t_fdf *data, t_list *lsk)
{
	int		**matrix;
	int		i;
	t_list	*lst;

	lst = lsk;
	matrix = NULL;
	if ((matrix = (int**)malloc(sizeof(int*) * data->map->y_size)))
	{
		i = 0;
		while (i < data->map->y_size && lst)
		{
			if (!(matrix[i] = (int*)malloc(sizeof(int) * data->map->x_size)))
				return (0);
			list_to_matrix(matrix[i], lst, data->map->x_size);
			i++;
			lst = lst->next;
		}
		data->map->matrix_map = matrix;
	}
	if (!matrix)
		return (free_lst(lsk));
	return (1);
}
