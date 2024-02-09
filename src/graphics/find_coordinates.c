/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_coordinates.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lpraca-l <lpraca-l@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/07 14:21:20 by lpraca-l      #+#    #+#                 */
/*   Updated: 2024/02/07 14:21:20 by lpraca-l      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../MLX42/include/MLX42/MLX42.h"
#include "../../includes/structs.h"
#include "../../lib42/include/libft.h"
#include "../../includes/cub3d.h"
#include "../../includes/utils.h"

int	find_texture_x(t_data *cub_data, double dist)
{
	double	wall_x;
	int		tex_x;

	if (cub_data->side == 0)
		wall_x = cub_data->player->posY + dist * cub_data->player->dirY;
	else
		wall_x = cub_data->player->posX + dist * cub_data->player->dirX;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)cub_data->walls->current_width);
	if (cub_data->side == 0 && cub_data->player->dirX > 0)
		tex_x = (int)cub_data->walls->current_width - tex_x - 1;
	if (cub_data->side == 1 && cub_data->player->dirY < 0)
		tex_x = (int)cub_data->walls->current_width - tex_x - 1;
	return (tex_x);
}
