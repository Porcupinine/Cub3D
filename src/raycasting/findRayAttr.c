/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findRayAttr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:31:14 by laura             #+#    #+#             */
/*   Updated: 2024/02/19 14:07:09 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/parsing.h"
#include "../../lib42/include/libft.h"
#include <stdio.h>

int	hit_check(t_data *data, int map)
{
	if (data->ray->sideX < data->ray->sideY)
	{
		data->ray->sideX += data->ray->deltaX;
		map += data->ray->stepX;
		data->side = 0;
	}
	else
	{
		data->ray->sideY += data->ray->deltaY;
		map += data->ray->stepY;
		data->side = 1;
	}
	return (map);
}

double	find_hit(t_data *data)
{
	int		hit;
	double	dist;
	int		map_x;
	int		map_y;

	hit = 0;
	map_x = data->player->mapX;
	map_y = data->player->mapY;
	while (hit == 0)
	{
		if (data->ray->sideX < data->ray->sideY)
			map_x = hit_check(data, map_x);
		else
			map_y = hit_check(data, map_y);
		if (data->map_data->map[map_y][map_x] == '1')
			hit = 1;
	}
	if (data->side == 0)
		dist = data->ray->sideX - data->ray->deltaX;
	else
		dist = data->ray->sideY - data->ray->deltaY;
	return (dist);
}

void	find_first_step(t_data *data, double x1, double y1)
{
	int	x;
	int	y;

	x = data->player->mapX;
	y = data->player->mapY;
	data->ray->stepX = 1;
	data->ray->stepY = 1;
	if (x1 < 0)
	{
		data->ray->stepX = -1;
		data->ray->sideX = (data->player->posX - x) * data->ray->deltaX;
	}
	else
		data->ray->sideX = (x + 1.00 - data->player->posX) * data->ray->deltaX;
	if (y1 < 0)
	{
		data->ray->stepY = -1;
		data->ray->sideY = (data->player->posY - y) * data->ray->deltaY;
	}
	else
		data->ray->sideY = (y + 1.00 - data->player->posY) * data->ray->deltaY;
}

void	find_intersection(t_data *data, double x1, double y1)
{
	if (x1 == 0)
		data->ray->deltaX = INFINITY;
	else
		data->ray->deltaX = fm(1 / x1);
	if (y1 == 0)
		data->ray->deltaY = INFINITY;
	else
		data->ray->deltaY = fm(1 / y1);
	find_first_step(data, x1, y1);
}
