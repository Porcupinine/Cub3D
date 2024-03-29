/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:00:10 by laura             #+#    #+#             */
/*   Updated: 2024/02/19 16:03:46 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../MLX42/include/MLX42/MLX42.h"
#include "../../includes/structs.h"
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

static int	get_pixel_color(mlx_texture_t *t, int x, int y)
{
	int	r;
	int	g;
	int	b;
	int	rgba;

	r = t->pixels[(y * t->width + x) * t->bytes_per_pixel];
	g = t->pixels[(y * t->width + x) * t->bytes_per_pixel + 1];
	b = t->pixels[(y * t->width + x) * t->bytes_per_pixel + 2];
	rgba = get_rgba(r, g, b, 255);
	return (rgba);
}

static void	find_wall(t_data *cub_data)
{
	if (cub_data->side == 0 && cub_data->ray->x1 > 0)
		cub_data->walls->texture = cub_data->walls->e;
	else if (cub_data->side == 0 && cub_data->ray->x1 < 0)
		cub_data->walls->texture = cub_data->walls->w;
	else if (cub_data->side == 1 && cub_data->ray->y1 < 0)
		cub_data->walls->texture = cub_data->walls->n;
	else if (cub_data->side == 1 && cub_data->ray->y1 > 0)
		cub_data->walls->texture = cub_data->walls->s;
	cub_data->walls->current_height = cub_data->walls->texture->height;
	cub_data->walls->current_width = cub_data->walls->texture->width;
}

static void	draw_vertical_line(t_data *cub_data, int tex_x, int x)
{
	int		y;
	int		color;
	int		tex_y;
	double	step;
	double	tex_pos;

	y = cub_data->walls->draw_start;
	step = 1.0 * cub_data->walls->current_height / cub_data->walls->line_height;
	tex_pos = (cub_data->walls->draw_start - ((double)HEIGHT / 2.0) + \
	((double)cub_data->walls->line_height / 2.0)) * step;
	while (y < cub_data->walls->draw_end)
	{
		tex_y = (int)tex_pos;
		tex_pos += step;
		color = get_pixel_color(cub_data->walls->texture, tex_x, tex_y);
		mlx_put_pixel(cub_data->img, x, y, color);
		y++;
	}
}

void	draw_walls(t_data *data, double dist, int x)
{
	int	tex_x;

	data->walls->line_height = (int)(HEIGHT / dist);
	data->walls->draw_start = (HEIGHT / 2 - data->walls->line_height / 2);
	if (data->walls->draw_start < 0)
		data->walls->draw_start = 0;
	data->walls->draw_end = HEIGHT / 2 + data->walls->line_height / 2;
	if (data->walls->draw_end >= HEIGHT)
		data->walls->draw_end = HEIGHT - 1;
	find_wall(data);
	tex_x = find_texture_x(data, dist);
	draw_vertical_line(data, tex_x, x);
}
