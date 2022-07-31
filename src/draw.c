/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azakizad <azakizad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 22:23:59 by azakizad          #+#    #+#             */
/*   Updated: 2022/07/29 23:18:04 by azakizad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	mod(float i)
{
	if (i < 0)
		return (-i);
	return (i);
}

float	max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

void	isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(1);
	*y = (*x + *y) * sin(0.567) - z;
}

void	drawing_al(t_cord cord, float x1, float y1, t_fdf *data)
{
	data->z = data->z_matrix[(int)cord.y][(int)cord.x];
	data->z1 = data->z_matrix[(int)y1][(int)x1];
	cord.x *= data->zoom;
	cord.y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;
	data->color = set_color(data);
	isometric(&cord.x, &cord.y, data->z);
	isometric(&x1, &y1, data->z1);
	cord.x += data->shift_x;
	cord.y += data->shift_y;
	x1 += data->shift_x;
	y1 += data->shift_y;
	data->x_step = x1 - cord.x;
	data->y_step = y1 - cord.y;
	data->max = max(mod(data->x_step), mod(data->y_step));
	data->x_step /= (float) data->max;
	data->y_step /= (float) data->max;
	while ((int)(cord.x - x1) || (int)(cord.y - y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr,
			cord.x + 500, cord.y + 250, data->color);
		cord.x += data->x_step;
		cord.y += data->y_step;
	}
}

void	draw(t_fdf *data)
{
	t_cord	cord;

	cord.y = 0;
	while (cord.y < data->height)
	{
		cord.x = 0;
		while (cord.x < data->width)
		{
			if (cord.x < data->width - 1)
				drawing_al(cord, cord.x + 1, cord.y, data);
			if (cord.y < data->height - 1)
				drawing_al(cord, cord.x, cord.y + 1, data);
			cord.x++;
		}
		cord.y++;
	}
}
