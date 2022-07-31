/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azakizad <azakizad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:04:03 by azakizad          #+#    #+#             */
/*   Updated: 2022/07/22 21:00:00 by azakizad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "Libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <math.h>

typedef struct dfdf
{
	int		width;
	int		height;
	int		**z_matrix;
	int		zoom;
	int		color;
	int		shift_x;
	int		shift_y;
	float	x_step;
	float	y_step;
	int		max;
	int		z;
	int		z1;

	void	*mlx_ptr;
	void	*win_ptr;
}	t_fdf;

typedef struct s_cord
{
	float	x;
	float	y;
}	t_cord;

int		get_height(char *file_name);
int		get_width(char *file_name);
void	read_file(char *file_name, t_fdf *data);
void	fill_the_matrix(int *line, char *str);
int		wd_counter(char *str, char c);
void	drawing_al(t_cord cord, float x1, float y1, t_fdf *data);
float	mod(float i);
void	draw(t_fdf *data);
void	isometric(float *x, float *y, int z);
int		key(int key, t_fdf *data);
int		set_color(t_fdf *data);
int		ft_close(void *param);
float	max(float a, float b);
float	mod(float i);

#endif