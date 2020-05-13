/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arz <arz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 02:57:39 by arz               #+#    #+#             */
/*   Updated: 2020/05/13 00:58:05 by arz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		counter_digits(char *line)
{
	int	i;
	int	counter;
	int	flg;

	i = -1;
	counter = 0;
	flg = 0;
	while (line[++i] != '\0')
	{
		if ((line[i] >= '0' && line[i] <= '9') || line[i] == '-')
		{
			if (flg == 0)
			{
				flg = 1;
				counter++;
			}
			else if (flg == 1 && (line[i] == '+' || line[i] == '-'))
				return (-1);
		}
		else if (line[i] == ' ')
			flg = 0;
		else
			return (-1);
	}
	return (counter);
}

t_list	*add_lst(t_list *head, char *line)
{
	t_list	*iter;

	iter = head;
	if (!iter)
	{
		if ((iter = ft_lstnew(NULL, 0)))
		{
			iter->content = (void *)line;
			return (iter);
		}
	}
	else
	{
		while (iter->next)
			iter = iter->next;
		if ((iter->next = ft_lstnew(NULL, 0)))
		{
			iter->next->content = (void *)line;
			return (head);
		}
	}
	return (NULL);
}

t_list	*save_on_list(int fd, t_fdf *data)
{
	char	*line;
	t_list	*ret;

	ret = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (data->map->x_size == -1)
			data->map->x_size = counter_digits(line);
		else if ((counter_digits(line)) != data->map->x_size)
		{
			free(line);
			return (free_lst(ret) == 0 ? NULL : NULL);
		}
		if (!(ret = add_lst(ret, line)))
		{
			free(line);
			return (free_lst(ret) == 0 ? NULL : NULL);
		}
		data->map->y_size++;
	}
	return (ret);
}

int		read_file(t_fdf *data, char *f_name)
{
	int		fd;
	t_list	*lst;

	if ((fd = open(f_name, O_RDONLY)) > 1)
	{
		if (!(lst = save_on_list(fd, data)))
		{
			ft_printf("Error read from file\n");
			return (0);
		}
		if (!(create_matrix(data, lst)))
		{
			ft_printf("Error init map\n");
			return (0);
		}
		free_lst(lst);
		close(fd);
		return (1);
	}
	ft_printf("Error! Bad file name\n");
	exit(1);
}
