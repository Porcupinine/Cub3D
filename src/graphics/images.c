/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   images.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/17 21:16:18 by laura         #+#    #+#                 */
/*   Updated: 2024/02/17 21:16:18 by laura         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/parsing.h"
#include "../../includes/utils.h"
#include "libft.h"

void	init_map_images(t_data *data)
{
	data->map = ft_calloc(1, sizeof(t_minimap));
	if (!data->map)
		clean_up(data, "Malloc fail\n");
	data->map->player_png = mlx_load_png("textures/dot.png");
	if (!data->map->player_png)
		clean_up(data, "Downloading png fail\n");
	data->map->img_player = mlx_texture_to_image(data->mlx, \
		data->map->player_png);
	if (!data->map->img_player)
		clean_up(data, "Minimap images fail");
	mlx_resize_image(data->map->img_player, data->scale_map, data->scale_map);
	if (mlx_image_to_window(data->mlx, data->map->img_player, \
		6 * data->scale_map, 3 * data->scale_map) < 0)
		clean_up(data, "Minimap images to window fail");
	data->strimage = mlx_put_string(data->mlx, "Stop rotating! You make me dizzy", \
		WIDTH / 2, HEIGHT / 2);
	if (!data->strimage)
		clean_up(data, "Message fail");
	data->strimage->enabled = false;
}

void	init_image(t_data *data)
{
	if (WIDTH < HEIGHT)
		data->scale_map = WIDTH / 50;
	else
		data->scale_map = HEIGHT / 50;
//	data->mlx = mlx_init(WIDTH, HEIGHT, "CUB", true);
//	if (!data->mlx)
//		clean_up(cub_data, "MLX initialization fail\n");
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (mlx_image_to_window(data->mlx, data->img, 0, 0) < 0)
		clean_up(data, "Drawing image fail\n");
	data->mini_img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (mlx_image_to_window(data->mlx, data->mini_img, 0, 0) < 0)
		clean_up(data, "Drawing image fail\n");
	init_raycast(data);
}
