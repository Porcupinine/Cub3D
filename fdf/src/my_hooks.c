/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 20:57:20 by akrepkov          #+#    #+#             */
/*   Updated: 2023/06/04 13:42:12 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/MLX42/include/MLX42/MLX42.h"
#include "../libs/libft/libft.h"
#include "fdf.h"

void	my_size(mlx_key_data_t keydata, t_fdf *data)
{
	if (keydata.key == MLX_KEY_EQUAL && keydata.action == MLX_PRESS)
	{
		drawing_line(data, 0x000000);
		data->zoom += data->zoom / 8;
		drawing_line(data, 0xFFFFFF);
	}
	if (keydata.key == MLX_KEY_MINUS && keydata.action == MLX_PRESS)
	{
		drawing_line(data, 0x000000);
		if (data->zoom >= 2)
			data->zoom -= data->zoom / 8;
		drawing_line(data, 0xFFFFFF);
	}
}

void	let_s_move(mlx_key_data_t keydata, t_fdf *data)
{
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
	{
		drawing_line(data, 0x000000);
		data->p_y -= HEIGHT / 20;
		drawing_line(data, 0xFFFFFF);
	}
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
	{
		drawing_line(data, 0x000000);
		data->p_y += HEIGHT / 20;
		drawing_line(data, 0xFFFFFF);
	}
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
	{
		drawing_line(data, 0x000000);
		data->p_x -= WIDTH / 20;
		drawing_line(data, 0xFFFFFF);
	}
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
	{
		drawing_line(data, 0x000000);
		data->p_x += WIDTH / 20;
		drawing_line(data, 0xFFFFFF);
	}
}

void	rotating(mlx_key_data_t keydata, t_fdf *data)
{
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
	{
		drawing_line(data, 0x000000);
		data->a += M_PI / 18;
		drawing_line(data, 0xFFFFFF);
	}
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
	{
		drawing_line(data, 0x000000);
		data->a -= M_PI / 18;
		drawing_line(data, 0xFFFFFF);
	}
}

void	my_hook(mlx_key_data_t keydata, t_fdf *data)
{
	my_size (keydata, data);
	let_s_move (keydata, data);
	rotating (keydata, data);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window(data->mlx);
		exit(0);
	}
	if (keydata.key == MLX_KEY_1 && keydata.action == MLX_PRESS)
	{
		drawing_line(data, 0x000000);
		data->zoom_z += 2;
		drawing_line(data, 0xFFFFFF);
	}
	if (keydata.key == MLX_KEY_2 && keydata.action == MLX_PRESS)
	{
		drawing_line(data, 0x000000);
		data->zoom_z -= 2;
		drawing_line(data, 0xFFFFFF);
	}
}
