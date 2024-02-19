/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:58:52 by laura             #+#    #+#             */
/*   Updated: 2024/02/19 13:59:54 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/parsing.h"
#include "../../includes/graphics.h"
#include "../../includes/utils.h"
#include <stdio.h>

void	stop_cursoring(double xpos, double ypos, t_data *data)
{
	data->strimage->enabled = false;
}

void	cursoring_2(double xpos, double ypos, t_data *data)
{
	data->r_d2 = xpos;
	if (data->r_d2 < data->r_d)
		rotate_left(data, 0.015);
	else if (data->r_d2 >= data->r_d)
		rotate_right(data, 0.015);
}

void	cursoring(double xpos, double ypos, t_data *data)
{
	data->r_d = xpos;
	mlx_cursor_hook(data->mlx, (void *)&cursoring_2, data);
}

void	mousing(mouse_key_t button, action_t action, \
	modifier_key_t mods, t_data *data)
{
	if (button == MLX_MOUSE_BUTTON_LEFT && action == MLX_PRESS)
	{
		data->strimage->enabled = true;
		mlx_cursor_hook(data->mlx, (void *)&cursoring, data);
	}
	if (button == MLX_MOUSE_BUTTON_LEFT && action == MLX_RELEASE)
	{
		mlx_cursor_hook(data->mlx, (void *)&stop_cursoring, data);
	}
}

void	let_s_move(mlx_key_data_t keydata, t_data *data)
{
	double	angle;

	angle = 0.2;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move_forward(data);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		move_back(data);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		move_right(data);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		move_left(data);
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		rotate_left(data, angle);
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		rotate_right(data, angle);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_terminate(data->mlx);
		delete_texture(data);
		free_cub(data);
		exit(EXIT_SUCCESS);
	}
}
