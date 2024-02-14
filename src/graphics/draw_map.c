/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:00:10 by laura             #+#    #+#             */
/*   Updated: 2024/02/06 14:00:32 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../MLX42/include/MLX42/MLX42.h"
#include "../../includes/structs.h"
#include "../../lib42/include/libft.h"
#include "../../includes/cub3d.h"
#include "../../includes/graphics.h"
#include "../../includes/utils.h"

void	draw_env(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < HEIGHT / 2)
				mlx_put_pixel(data->img, x, y, data->map_data->celling);
			else
				mlx_put_pixel(data->img, x, y, data->map_data->floor);
			x++;
		}
		y++;
	}
}

int get_pixel_color(mlx_texture_t *texture, int x, int y)
{
	int	r;
	int	g;
	int	b;
	int rgba;

	r = texture->pixels[(y * texture->width + x) * texture->bytes_per_pixel];
	g = texture->pixels[(y * texture->width + x) * texture->bytes_per_pixel + 1];
	b = texture->pixels[(y * texture->width + x) * texture->bytes_per_pixel + 2];
	rgba = get_rgba(r, g, b, 255);
	return (rgba);
}

void find_wall(t_data *cub_data)
{
	if (cub_data->side == 0 && cub_data->ray->x1 >= 0)
		cub_data->walls->texture = cub_data->walls->w;
	else if (cub_data->side == 0 && cub_data->ray->x1 <= 0)
		cub_data->walls->texture = cub_data->walls->e;
	else if (cub_data->side == 1 && cub_data->ray->y1 <= 0)
		cub_data->walls->texture = cub_data->walls->s;
	else if (cub_data->side == 1 && cub_data->ray->y1 >= 0)
		cub_data->walls->texture = cub_data->walls->n;
	cub_data->walls->current_height = cub_data->walls->texture->height;
	cub_data->walls->current_width = cub_data->walls->texture->width;
}

void	drawVerticalLine(t_data *cub_data, int tex_x, int x)
{
	int		y;
	int		color;
	int		tex_y;
	double	step;
	double	tex_pos;

	y = cub_data->walls->draw_start;
	step = 1.0 * cub_data->walls->current_height / cub_data->walls->line_height;
	tex_pos = (cub_data->walls->draw_start - ((double)HEIGHT / 2.0) + ((double)cub_data->walls->line_height / 2.0)) * step;
	while (y <= cub_data->walls->draw_end)
	{
		tex_y = (int)tex_pos & (int)(cub_data->walls->current_height - 1);
		tex_pos += step;
		color = get_pixel_color(cub_data->walls->texture, tex_x, tex_y);
		mlx_put_pixel(cub_data->img, x, y, color);
		//printf("tex_x: %d   tex_y: %d   color: %d\n", tex_x, tex_y, color);
		y++;
	}
}

void	findWallHeight(t_data *data, double dist, int x)
{
	int tex_x;

	if ((int)dist != 0)
		data->walls->line_height = (int)(HEIGHT / dist);
	else
		data->walls->line_height = HEIGHT;
	data->walls->draw_start = HEIGHT / 2 -data->walls->line_height / 2;
	if (data->walls->draw_start < 0)
		data->walls->draw_start = 0;
	data->walls->draw_end = HEIGHT / 2 + data->walls->line_height / 2;
	if (data->walls->draw_end >= HEIGHT)
		data->walls->draw_end = HEIGHT - 1;
	find_wall(data);
	tex_x = find_texture_x(data, dist);
	printf("dist 3: %f  tex_x: %d\n", dist, tex_x);
	drawVerticalLine(data, tex_x, x);
}
//TODO print dir and diry and dirx for all rays

