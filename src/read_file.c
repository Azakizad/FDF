/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azakizad <azakizad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:16:03 by azakizad          #+#    #+#             */
/*   Updated: 2022/07/29 22:49:11 by azakizad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_height(char *file_name)
{
	char	*line;
	int		fd;
	int		height;

	fd = open(file_name, O_RDONLY, 0);
	if (fd < 1)
	{
		perror("map error");
		exit(0);
	}
	line = get_next_line(fd);
	height = 0;
	while (line != NULL)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (height);
}

int	get_width(char *file_name)
{
	char	*line;
	int		fd;
	int		width;

	fd = open(file_name, O_RDONLY, 0);
	if (fd < 1)
	{
		perror("map error");
		exit(0);
	}
	line = get_next_line(fd);
	width = wd_counter(line, ' ');
	free(line);
	close(fd);
	return (width);
}

void	read_file(char *file_name, t_fdf *data)
{
	int		fd;
	int		i;
	char	*line;

	data->height = get_height(file_name);
	data->width = get_width(file_name);
	data->shift_x = 0;
	data->shift_y = 0;
	data->zoom = 20;
	data->z_matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
	i = 0;
	while (i <= data->height)
		data->z_matrix[i++] = (int *)malloc(sizeof(int) * (data->width + 1));
	fd = open(file_name, O_RDONLY, 0);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		fill_the_matrix(data->z_matrix[i], line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	free(line);
}

void	fill_the_matrix(int *line, char *str)
{
	char	**nums;
	int		i;

	nums = ft_split(str, ' ');
	i = 0;
	while (nums && nums[i])
	{
		free(nums[i]);
		line[i] = ft_atoi(nums[i]);
		i++;
	}
	free(nums);
	nums = NULL;
}
