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
	{
		wall_x = cub_data->player->posY + dist * cub_data->player->dirY;
		printf("posY: %f\ndist: %f\ndiry: %f\n", cub_data->player->posY, dist, cub_data->player->dirY);
		printf("wall_x = %f + %f * %f\n", cub_data->player->posY, dist, cub_data->player->dirY);
	}
	else
	{
		wall_x = cub_data->player->posX + dist * cub_data->player->dirX;
		printf("posx: %f\ndist: %f\ndirx: %f\n", cub_data->player->posX, dist, cub_data->player->dirX);
		printf("wall_x = %f + %f * %f\n", cub_data->player->posY, dist, cub_data->player->dirY);
	}
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)512);
	if (cub_data->side == 0 && cub_data->player->dirX > 0)
	{
		tex_x = 512 - tex_x - 1;
		printf("tex_x = %d - %d - 1\n", 512, tex_x);
	}
	if (cub_data->side == 1 && cub_data->player->dirY < 0)
	{
		tex_x = 512 - tex_x - 1;
		printf("tex_x = %d - %d - 1\n", 512, tex_x);
	}
	printf("wall_x: %f\ntex_x: %d\n\n", wall_x, tex_x);
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
