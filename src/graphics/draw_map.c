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

int find_wall(t_data *cub_data, int x, int y)
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

void	drawVerticalLine(t_data *cub_data, int x, int y_start, int y_end, int color)
{
	int	y;

	y = y_start;
	while (y <= y_end)
	{
		color = find_wall(cub_data, x, y);
		mlx_put_pixel(cub_data->img, x, y, color);
		y++;
	}
}

void	findWallHeight(t_data *data, double dist, int x)
{
	int	lineHeight;
	int	drawStart;
	int	drawEnd;

	if ((int)dist != 0)
		lineHeight = (int)(HEIGHT / dist);
	else
		lineHeight = HEIGHT;
	printf("\ndist %f\n", dist);
	drawStart = HEIGHT / 2 - lineHeight / 2;
	if (drawStart < 0)
		drawStart = 0;
	drawEnd = HEIGHT / 2 + lineHeight / 2;
	if (drawEnd >= HEIGHT)
		drawEnd = HEIGHT - 1;
	drawVerticalLine(data, x, drawStart, drawEnd, 0xFF0000FF);
}
