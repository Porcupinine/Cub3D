/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:05:45 by laura             #+#    #+#             */
/*   Updated: 2024/02/19 14:08:13 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/utils.h"
#include "includes/graphics.h"
#include "includes/checks.h"
#include "includes/parsing.h"
#include "includes/cub3d.h"
#include "lib42/include/libft.h"
#include <stdio.h>

void	game_loop(t_data *data)
{
	draw_env(data);
	raycasting(data);
	if (data->scale_map > 2 && data->scale_map < 100)
	{
		init_map_images(data);
		draw_map(data, 7, 13);
	}
	mlx_key_hook(data->mlx, (void *)&let_s_move, data);
	mlx_mouse_hook(data->mlx, (void *)&mousing, data);
	mlx_loop(data->mlx);
}

int	main(int argc, char **argv)
{
	t_data	*cub_data;

	if (argc != 2)
	{
		printf("wrong amount of args!\n");
		return (1);
	}
	cub_data = ft_calloc(1, sizeof(t_data));
	if (cub_data == NULL)
		clean_up(cub_data, "Malloc fail\n");
	cub_data->mlx = mlx_init(WIDTH, HEIGHT, "CUB", true);
	if (!cub_data->mlx)
		clean_up(cub_data, "MLX initialization fail\n");
	get_data(cub_data, argv[1]);
	check_map(cub_data);
	check_values(cub_data);
	init_image(cub_data);
	game_loop(cub_data);
	mlx_terminate(cub_data->mlx);
	delete_texture(cub_data);
	free_cub(cub_data);
	return (0);
}
