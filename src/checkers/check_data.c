/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_data.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: akrepkov <akrepkov@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/29 14:57:43 by lpraca-l      #+#    #+#                 */
/*   Updated: 2024/02/17 08:27:56 by laura         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"
#include "../../includes/utils.h"
#include "../../lib42/include/libft.h"
#include "../../includes/graphics.h"
#include <math.h>

void	check_values(t_data *cub_data)
{
	if (cub_data->map_data->no_path == NULL || \
	cub_data->map_data->so_path == NULL || \
	cub_data->map_data->we_path == NULL || \
	cub_data->map_data->ea_path == NULL)
		clean_up(cub_data, "Invalid map. Missing information\n");
	load_textures(cub_data);
}

void	find_direction(t_data *cub_data, char dir)
{
	if (dir == 'N' || dir == 'S')
		cub_data->player->dirx = 0;
	if (dir == 'E' || dir == 'W')
		cub_data->player->diry = 0;
	if (dir == 'E')
		cub_data->player->dirx = 1;
	if (dir == 'W')
		cub_data->player->dirx = -1;
	if (dir == 'N')
		cub_data->player->diry = -1;
	if (dir == 'S')
		cub_data->player->diry = 1;
	cub_data->angle = atan2(cub_data->player->diry, cub_data->player->dirx);
}
