/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azakizad <azakizad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 06:36:46 by azakizad          #+#    #+#             */
/*   Updated: 2022/07/23 08:24:37 by azakizad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key(int key, t_fdf *data)
{
	if (key == 125)
		data->shift_y -= 20;
	if (key == 126)
		data->shift_y += 20;
	if (key == 124)
		data->shift_x -= 20;
	if (key == 123)
		data->shift_x += 20;
	if (key == 69)
		data->zoom += 2;
	if (key == 78)
	{
		if (data->zoom >= 2)
			data->zoom -= 2;
	}
	if (key == 53)
		exit(0);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}
