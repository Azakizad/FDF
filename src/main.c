/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azakizad <azakizad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:03:45 by azakizad          #+#    #+#             */
/*   Updated: 2022/07/29 20:21:55 by azakizad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	*data;

	if (argc)
	{
		data = (t_fdf *)malloc(sizeof(t_fdf));
		data->mlx_ptr = mlx_init();
		data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
		read_file(argv[1], data);
		draw(data);
		mlx_key_hook(data->win_ptr, key, data);
		mlx_hook(data->win_ptr, 17, 0, ft_close, data);
		mlx_loop(data->mlx_ptr);
	}
	perror("wrong amount of arguments");
	exit(0);
}
