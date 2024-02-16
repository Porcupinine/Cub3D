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

void	load_textures(t_data *cub_data)
{
	cub_data->walls = ft_calloc(1, sizeof (t_cub_textures));
	if (cub_data->walls == NULL)
		ft_error("Malloc fail\n");
	cub_data->walls->n = mlx_load_png(cub_data->map_data->no_path);
	cub_data->walls->s = mlx_load_png(cub_data->map_data->so_path);
	cub_data->walls->e = mlx_load_png(cub_data->map_data->ea_path);
	cub_data->walls->w = mlx_load_png(cub_data->map_data->we_path);
	if (!cub_data->walls->w || \
		!cub_data->walls->n || \
		!cub_data->walls->s || \
		!cub_data->walls->e)
		ft_error("Texture fail\n");
}
