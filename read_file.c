
#include "./includes/fdf.h"

int		counter_digits(char *line)
{
	int 	i;
	int 	counter;
	int		flg;

	i = 0;
	counter = 0;
	flg = 0;
	while (line[i] != '\0')
	{
		if ((line[i] >= '0' && line[i] <= '9') || line[i] == '-')
		{
			if (flg == 0)
			{
				flg = 1;
				counter++;
			}
			else if (flg == 1 && (line[i] == '+' || line[i] == '-'))
				return (0);
		}
		else if (line[i] == ' ')
			flg = 0;
		i++;
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
	int 	y;
	int		x;
	t_list	*ret;

	y = 0;
	x = -1;
	ret = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (x == -1)
			x = counter_digits(line);
		else if ((counter_digits(line)) != x)
		{
		    free(line);
		    return (free_lst(ret));
		}
		if (!(ret = add_lst(ret, line)))
		{
            free(line);
            return (free_lst(ret));
        }
		y++;
	}
	data->y_size = y;
	data->x_size = x;
	return (ret);
}

int 	read_file(t_fdf *data, char *f_name)
{
	int 	fd;
	t_list	*lst;

	if ((fd = open(f_name, O_RDONLY)) > 1)
	{
		if (!(lst = save_on_list(fd, data)))
		{
		    printf("Error read\n");
            return (0);
        }
		if (!(create_matrix(data, lst)))
			return (0);
		return (1);
	}
    printf("Error! Bad name file\n");
	exit(1);
	return (0);
}
