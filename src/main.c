/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arz <arz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 01:59:08 by arz               #+#    #+#             */
/*   Updated: 2020/05/13 19:27:58 by arz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		mouse_scroll(int button, int x, int y, t_fdf *data)
{
	(void)x;
	if (y < 0)
		return (0);
	if (button == 4 || button == 5 || button == 3)
		zoom(button, data);
	return (0);
}

void	print_menu(t_fdf *data)
{
	char *menu;

	menu = "Numpad: spin";
	mlx_string_put(data->mlx_pntr, data->win_pntr, 10, 5, 0x03fc35, menu);
	menu = "Up, down, right, left: move";
	mlx_string_put(data->mlx_pntr, data->win_pntr, 10, 20, 0x03fc35, menu);
	menu = "+, -, 0, mouse scroll: zoom";
	mlx_string_put(data->mlx_pntr, data->win_pntr, 10, 35, 0x03fc35, menu);
	menu = "i : isometry";
	mlx_string_put(data->mlx_pntr, data->win_pntr, 10, 50, 0x03fc35, menu);
	menu = "c : color change";
	mlx_string_put(data->mlx_pntr, data->win_pntr, 10, 65, 0x03fc35, menu);
	menu = "<, >: deep change";
	mlx_string_put(data->mlx_pntr, data->win_pntr, 10, 80, 0x03fc35, menu);
}

int		main(int ac, char **av)
{
	t_fdf	*data;

	if (ac == 2 && (data = malloc_t_fdf()))
	{
		if (read_file(data, av[1]))
		{
			if (init_fdf(data))
			{
				draw(data);
				mlx_hook(data->win_pntr, 2, 1L << 0, keys_hook, data);
				mlx_hook(data->win_pntr, 4, 1L << 2, mouse_scroll, data);
				mlx_loop(data->mlx_pntr);
			}
			else
			{
				ft_printf("Error init fdf\n");
				exit(0);
			}
		}
	}
	else
		ft_printf("Usage ./fdf <map>\n");
	exit(0);
	return (0);
}
