/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:48:48 by lpraca-l          #+#    #+#             */
/*   Updated: 2024/02/06 15:01:21 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../MLX42/include/MLX42/MLX42.h"
#include "../../includes/structs.h"
#include "../../lib42/include/libft.h"
#include "../../includes/parsing.h"
#include "../../includes/utils.h"

void	load_textures(t_data *cub_data)
{
	cub_data->walls = ft_calloc(1, sizeof (t_cub_textures));
	if (cub_data->walls == NULL)
		clean_up(cub_data, "Malloc fail\n");
	cub_data->walls->n = mlx_load_png(cub_data->map_data->no_path);
	cub_data->walls->s = mlx_load_png(cub_data->map_data->so_path);
	cub_data->walls->e = mlx_load_png(cub_data->map_data->ea_path);
	cub_data->walls->w = mlx_load_png(cub_data->map_data->we_path);
	if (!cub_data->walls->w || \
		!cub_data->walls->n || \
		!cub_data->walls->s || \
		!cub_data->walls->e)
		clean_up(cub_data, "Texture fail\n");
}

void	delete_texture(t_data *cub_data)
{
	if (cub_data->walls->n != NULL)
		mlx_delete_texture(cub_data->walls->n);
	if (cub_data->walls->s != NULL)
		mlx_delete_texture(cub_data->walls->s);
	if (cub_data->walls->e != NULL)
		mlx_delete_texture(cub_data->walls->e);
	if (cub_data->walls->w != NULL)
		mlx_delete_texture(cub_data->walls->w);
	if (cub_data->map->player_png != NULL)
		mlx_delete_texture(cub_data->map->player_png);
}
