//
// Created by ARZ on 02.05.2020.
//

#ifndef FDF_FDF_H
#define FDF_FDF_H
# include "../libft/includes/libft.h"
#include <fcntl.h>
#include "../minilibx_macos/mlx.h"

typedef struct	s_fdf
{
	int 		x_size;
	int 		y_size;
	int**		matrix_map;

	int         zoom;
	int         win_height;
	int         win_width;
	void*		mlx_pntr;
	void*		win_pntr;
}				t_fdf;


/*
 *	read_file.c
 */

int 	read_file(t_fdf *data, char *f_name);

/*
 *	create_matrix.c
 */

int 	create_matrix(t_fdf *data, t_list *lst);
int		free_lst(t_list *lst);

#endif //FDF_FDF_H
