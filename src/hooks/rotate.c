/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:57:39 by akrepkov          #+#    #+#             */
/*   Updated: 2024/02/19 15:50:29 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/parsing.h"
#include "../../lib42/include/libft.h"

void	update_images(t_data *data)
{
	draw_env(data);
	raycasting(data);
	if (data->scale_map > 2 && data->scale_map < 100)
		draw_map(data, 7, 13);
}

int	wall_check(t_data *data, double y_end, double x_end)
{
	if (data->map_data->map[(int)y_end][(int)x_end] == '1')
		return (-1);
	return (0);
}

void	rotate_left(t_data *data, double angle)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = data->player->dirx;
	data->player->dirx = data->player->dirx * cos(angle) + \
		data->player->diry * sin(angle);
	data->player->diry = -old_dirx * sin(angle) + \
		data->player->diry * cos(angle);
	old_planex = data->ray->planex;
	data->ray->planex = data->ray->planex * cos(angle) + \
		data->ray->planey * sin(angle);
	data->ray->planey = -old_planex * sin(angle) + \
		data->ray->planey * cos(angle);
	update_images(data);
}

void	rotate_right(t_data *data, double angle)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = data->player->dirx;
	data->player->dirx = data->player->dirx * cos(angle) - \
		data->player->diry * sin(angle);
	data->player->diry = old_dirx * sin(angle) + \
		data->player->diry * cos(angle);
	old_planex = data->ray->planex;
	data->ray->planex = data->ray->planex * cos(angle) - \
		data->ray->planey * sin(angle);
	data->ray->planey = old_planex * sin(angle) + \
		data->ray->planey * cos(angle);
	update_images(data);
}
