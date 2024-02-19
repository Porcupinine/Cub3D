/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:57:25 by akrepkov          #+#    #+#             */
/*   Updated: 2024/02/19 15:48:56 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/parsing.h"
#include "../../lib42/include/libft.h"

void	move_forward(t_data *data)
{
	if (wall_check(data, data->player->posy + data->player->diry * 0.8, \
		data->player->posx + data->player->dirx * 0.8) == 0)
	{
		data->player->posy += data->player->diry * 0.8;
		data->player->posx += data->player->dirx * 0.8;
		update_images(data);
	}
}

void	move_back(t_data *data)
{
	if (wall_check(data, data->player->posy - data->player->diry * 0.8, \
		data->player->posx - data->player->dirx * 0.8) == 0)
	{
		data->player->posy -= data->player->diry * 0.8;
		data->player->posx -= data->player->dirx * 0.8;
		update_images(data);
	}
}

void	move_right(t_data *data)
{
	if (wall_check(data, data->player->posy + data->player->dirx * 0.8, \
		data->player->posx - data->player->diry * 0.8) == 0)
	{
		data->player->posy += data->player->dirx * 0.8;
		data->player->posx -= data->player->diry * 0.8;
		update_images(data);
	}
}

void	move_left(t_data *data)
{
	if (wall_check(data, data->player->posy - data->player->dirx * 0.8, \
		data->player->posx + data->player->diry * 0.8) == 0)
	{
		data->player->posy -= data->player->dirx * 0.8;
		data->player->posx += data->player->diry * 0.8;
		update_images(data);
	}
}
