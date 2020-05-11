/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arz <arz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 02:56:02 by arz               #+#    #+#             */
/*   Updated: 2020/05/10 17:20:32 by arz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_FDF_H
# define FDF_FDF_H
# include "../libft/includes/libft.h"
# include "controls_keys.h"
# include <fcntl.h>
# include <stdio.h>
# include "../minilibx_macos/mlx.h"
# include <math.h>
# include <limits.h>

# define X_S_WIN 1920
# define Y_S_WIN 1080
# define COLOR1 {0x000000, 0x808080, 0xFFFFFF}

typedef struct			s_coord
{
	int					x;
	int					y;
	int					z;
	int					col;
}						t_coord;

typedef struct			s_cam
{
	int					click;
	int					zoom;
	int					x_move;
	int					y_move;
	float				z_deep;
	double				x_angle;
	double				y_angle;
	double				z_angle;
	int					isometria;
}						t_cam;

typedef struct			s_map
{
	int					x_size;
	int					y_size;
	int					**matrix_map;
	int					color_id;
	int					**colors;
}						t_map;

typedef struct			s_fdf
{
	void				*img;
	char				*data_addr;
	int					b_p_p;
	int					size_line;
	int					endian;
	int					max_z;
	int					min_z;
	int					_3z;
	int					_6z;
	t_cam				*cam;
	t_map				*map;
	void				*mlx_pntr;
	void				*win_pntr;
}						t_fdf;

t_fdf					*malloc_t_fdf(void);
t_cam					*malloc_t_cam(void);
int						free_lst(t_list *lst);
int						init_fdf(t_fdf *data);
int						read_file(t_fdf *data, char *f_name);
int						create_matrix(t_fdf *data, t_list *lst);
t_coord					init_points(t_fdf *data, int x, int y);
int						ret_min(int a, int b);
void					print_menu(t_fdf *data);
int						keys_hook(int key, t_fdf *data);
int						move(int key, t_fdf *data);
void					zoom(int key, t_fdf *data);
int						change_deep(int key, t_fdf *data);
void					spin(int key, t_fdf *data);
void					isometry(t_fdf *data);
int						change_color(t_fdf *data);
int						linear_interpolation(t_coord *start, t_coord *end,
												int *x_y_current, int *delta);
int						**getcolor(void);
int						level_color(t_fdf *data, int z);
int						*putcolor(int a, int b, int c);
double					t_calculate(int a, int b, int c);
int						linear_interpolation(t_coord *start, t_coord *end,
												int *x_y_current, int *delta);
char					*skip_prev_digits(char *str);
void					list_to_matrix(int *matrix, t_list *lst, int x_size);
int						create_matrix(t_fdf *data, t_list *lsk);
void					pixel_putting(t_fdf *data, int *x_y, int color);
void					paint_line(t_fdf *data, t_coord a, t_coord b);
void					draw(t_fdf *data);
void					x_rotate(t_fdf *data, t_coord *crd);
void					y_rotate(t_fdf *data, t_coord *crd);
void					z_rotate(t_fdf *data, t_coord *crd);
void					img_projection(t_fdf *data, t_coord *crd);
void					print_map(t_fdf *data);
int						mouse_scroll(int button, int x, int y, t_fdf *data);
void					print_menu(t_fdf *data);

#endif
