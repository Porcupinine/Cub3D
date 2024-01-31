/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_walls.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lpraca-l <lpraca-l@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/29 16:48:48 by lpraca-l      #+#    #+#                 */
/*   Updated: 2024/01/29 16:48:48 by lpraca-l      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../MLX42/include/MLX42/MLX42.h"
#include "../../includes/structs.h"
#include "../../lib42/include/libft.h"

void	load_textures(t_data *cub_data)
{
	cub_data->walls.n = mlx_load_png(cub_data->map_data->no_path);
	if (!cub_data->walls.n)
		ft_error("Texture fail\n");
	cub_data->walls.s = mlx_load_png(cub_data->map_data->so_path);
	if (!cub_data->walls.s)
		ft_error("Texture fail\n");
	cub_data->walls.e = mlx_load_png(cub_data->map_data->ea_path);
	if (!cub_data->walls.e)
		ft_error("Texture fail\n");
	cub_data->walls.w = mlx_load_png(cub_data->map_data->we_path);
	if (!cub_data->walls.w)
		ft_error("Texture fail\n");
}

//TODO find wich wall we want to place the texture



