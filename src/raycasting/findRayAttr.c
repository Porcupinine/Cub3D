/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findRayAttr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:31:14 by laura             #+#    #+#             */
/*   Updated: 2024/02/19 15:51:59 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/parsing.h"
#include "../../lib42/include/libft.h"
#include <stdio.h>

int	hit_check(t_data *data, int map)
{
	if (data->ray->sidex < data->ray->sidey)
	{
		data->ray->sidex += data->ray->deltax;
		map += data->ray->stepx;
		data->side = 0;
	}
	else
	{
		data->ray->sidey += data->ray->deltay;
		map += data->ray->stepy;
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
	map_x = data->player->mapx;
	map_y = data->player->mapy;
	while (hit == 0)
	{
		if (data->ray->sidex < data->ray->sidey)
			map_x = hit_check(data, map_x);
		else
			map_y = hit_check(data, map_y);
		if (data->map_data->map[map_y][map_x] == '1')
			hit = 1;
	}
	if (data->side == 0)
		dist = data->ray->sidex - data->ray->deltax;
	else
		dist = data->ray->sidey - data->ray->deltay;
	return (dist);
}

void	find_first_step(t_data *data, double x1, double y1)
{
	int	x;
	int	y;

	x = data->player->mapx;
	y = data->player->mapy;
	data->ray->stepx = 1;
	data->ray->stepy = 1;
	if (x1 < 0)
	{
		data->ray->stepx = -1;
		data->ray->sidex = (data->player->posx - x) * data->ray->deltax;
	}
	else
		data->ray->sidex = (x + 1.00 - data->player->posx) * data->ray->deltax;
	if (y1 < 0)
	{
		data->ray->stepy = -1;
		data->ray->sidey = (data->player->posy - y) * data->ray->deltay;
	}
	else
		data->ray->sidey = (y + 1.00 - data->player->posy) * data->ray->deltay;
}

void	find_intersection(t_data *data, double x1, double y1)
{
	if (x1 == 0)
		data->ray->deltax = INFINITY;
	else
		data->ray->deltax = fm(1 / x1);
	if (y1 == 0)
		data->ray->deltay = INFINITY;
	else
		data->ray->deltay = fm(1 / y1);
	find_first_step(data, x1, y1);
}
