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

	wall_x = 0;
	if (cub_data->side == 0)
		wall_x = cub_data->player->posY + dist * cub_data->player->dirY;
	else
		wall_x = cub_data->player->posX + dist * cub_data->player->dirX;
	tex_x = (int)(wall_x * (double)TXT_WIGHT);
	if (cub_data->side == 0 && cub_data->player->dirX > 0)
		tex_x = TXT_WIGHT - tex_x - 1;
	if (cub_data->side == 1 && cub_data->player->dirY < 0)
		tex_x = TXT_WIGHT - tex_x - 1;
	return (tex_x);
}

//int find_texture_y(t_data *cub_data)
//{
//	int		tex_y;
//	double	step;
//	double	tex_pos;
//
//	step = 1.0 * TXT_HEIGHT / cub_data->walls->line_height;
//	tex_pos = (cub_data->walls->draw_start - HEIGHT / 2 + cub_data->walls->line_height / 2) * step;
//	tex_y = (int)tex_pos & (TXT_HEIGHT - 1);
//	tex_pos += step;
//	return (tex_y);
//}
