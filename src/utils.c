/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azakizad <azakizad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 14:13:26 by azakizad          #+#    #+#             */
/*   Updated: 2022/07/24 10:21:07 by azakizad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	wd_counter(char *str, char c)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = ft_split(str, c);
	if (!str || !c)
		return (0);
	while (tmp[i])
	{
		free(tmp[i]);
		++i;
	}
	free(tmp);
	return (i);
}

int	set_color(t_fdf *data)
{
	if (data->z || data->z1)
		return (0xffffff);
	return (0x32A956);
}

int	ft_close(void *param)
{
	(void)param;
	exit(0);
}
