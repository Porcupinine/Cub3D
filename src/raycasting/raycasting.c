/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 19:57:20 by laura             #+#    #+#             */
/*   Updated: 2024/02/19 15:52:38 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/parsing.h"
#include "../../includes/graphics.h"
#include "../../includes/utils.h"
#include "../../lib42/include/libft.h"

void	find_ray_direction(t_data *data, int x)
{
	double	camera;

	camera = 2 * x / (double)WIDTH - 1;
	data->ray->x1 = data->player->dirx + data->ray->planex * camera;
	data->ray->y1 = data->player->diry + data->ray->planey * camera;
	data->angle = atan2(data->player->diry, data->player->dirx);
}

double	norm_a(double *angle)
{
	if (*angle < 0)
		*angle += (2 * PI);
	if (*angle > (2 * PI))
		*angle -= (2 * PI);
	return (*angle);
}

void	raycasting(t_data *data)
{
	int		x;
	double	dist;

	x = 0;
	data->player->mapx = (int)data->player->posx;
	data->player->mapy = (int)data->player->posy;
	while (x < WIDTH)
	{
		find_ray_direction(data, x);
		find_intersection(data, data->ray->x1, data->ray->y1);
		dist = find_hit(data);
		data->wallx = data->player->posx + dist * data->ray->y1;
		draw_walls(data, dist, x);
		x++;
	}
}

void	init_raycast(t_data *data)
{
	double	dirlen;

	data->ray = ft_calloc(1, sizeof (t_ray));
	if (data->ray == NULL)
		clean_up(data, "Malloc fail\n");
	data->ray->sidex = 0.00;
	data->ray->sidey = 0.00;
	data->ray->stepx = 0;
	data->ray->stepy = 0;
	dirlen = sqrt(data->player->dirx * data->player->dirx \
	+ data->player->diry * data->player->diry);
	data->ray->planex = data->player->diry / dirlen * -0.66;
	data->ray->planey = -data->player->dirx / dirlen * -0.66;
	data->ray->x1 = 0.00;
	data->ray->y1 = 0.00;
}
