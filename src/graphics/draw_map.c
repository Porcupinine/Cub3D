/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:00:10 by laura             #+#    #+#             */
/*   Updated: 2024/01/31 14:37:02 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../MLX42/include/MLX42/MLX42.h"
#include "../../includes/structs.h"
#include "../../lib42/include/libft.h"
#include "../../includes/cub3d.h"
#include "../../includes/graphics.h"
#include "../../includes/utils.h"

void draw_env(t_data *data)
{
	int x;
	int y;

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

int	find_wall(t_data *cub_data, int x, int y)
{
	int color;

	color = 0;
	if (cub_data->side == 0 && cub_data->ray->x1 >= 0 && cub_data->ray->y1 <= 0)
		color = get_pixel_color(cub_data->walls->w, x, y); //1 west
	else if(cub_data->side == 0 && cub_data->ray->x1 >= 0 && cub_data->ray->y1 >= 0)
		color = get_pixel_color(cub_data->walls->w, x, y); //1 west
	else if (cub_data->side == 0 && cub_data->ray->x1 <= 0 && cub_data->ray->y1 <= 0)
		color = get_pixel_color(cub_data->walls->e, x, y); //2 east
	else if(cub_data->side == 0 && cub_data->ray->x1 <= 0 && cub_data->ray->y1 >= 0)
		color = get_pixel_color(cub_data->walls->e, x, y); //2 east
	else if (cub_data->side == 1 && cub_data->ray->x1 >= 0 && cub_data->ray->y1 <= 0)
		color = get_pixel_color(cub_data->walls->s, x, y); //3 south
	else if(cub_data->side == 1 && cub_data->ray->x1 <= 0 && cub_data->ray->y1 <= 0)
		color = get_pixel_color(cub_data->walls->s, x, y); //3 south
	else if (cub_data->side == 1 && cub_data->ray->x1 <= 0 && cub_data->ray->y1 >= 0)
		color = get_pixel_color(cub_data->walls->n, x, y); //4 north
	else if(cub_data->side == 1 && cub_data->ray->x1 >= 0 && cub_data->ray->y1 >= 0)
		color = get_pixel_color(cub_data->walls->n, x, y); //4 north
	return(color);
}

void	drawVerticalLine(t_data *cub_data, int tex_x, int x)
{
	int		y;
	int		color;
	int		tex_y;
	double	step;
	double	tex_pos;

	y = cub_data->walls->draw_start;
	step = 1.0 * TXT_HEIGHT / cub_data->walls->line_height;
	tex_pos = (cub_data->walls->draw_start - HEIGHT / 2 + cub_data->walls->line_height / 2) * step;
	while (y <= cub_data->walls->draw_end)
	{
		tex_y = (int)tex_pos & (TXT_HEIGHT - 1);
		tex_pos += step;
		color = find_wall(cub_data, tex_x, tex_y);
		mlx_put_pixel(cub_data->img, x, y, color);
		y++;
	}
}

void	findWallHeight(t_data *data, double dist, int x)
{
	int tex_x;

	if ((int)dist != 0)
		data->walls->line_height = (int)(HEIGHT / dist);
//	else
//		data->walls->line_height = HEIGHT;
//	printf("\ndist %f\n", dist);
//	data->walls->draw_start = HEIGHT / 2 - data->walls->line_height / 2;
	data->walls->draw_start = HEIGHT / 2 -data->walls->line_height / 2;
	if (data->walls->draw_start < 0)
		data->walls->draw_start = 0;
	data->walls->draw_end = HEIGHT / 2 + data->walls->line_height / 2;
	if (data->walls->draw_end >= HEIGHT)
		data->walls->draw_end = HEIGHT - 1;
	tex_x = find_texture_x(data, dist);
	drawVerticalLine(data, tex_x, x);
}
