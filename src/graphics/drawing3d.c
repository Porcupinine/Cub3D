#include "../../includes/utils.h"
#include "../../includes/checks.h"
#include "../../includes/parsing.h"
#include "../../includes/cub3d.h"
#include "../../lib42/include/libft.h"
#include <stdio.h>

void	draw_dark_line(t_data *cub_data, int x, int y1, int y2, double dark)
{
	int	red;
	int	green;
	int	blue;
	int	new;

	red = 64;
	green = 77;
	blue = 129;
	if (dark == 0)
		dark = 1;
	new = get_rgba(red, green, blue, (int)(255.00 * dark) / 10.00);
	if (dark > 10)
		new = get_rgba(red, green, blue, 255);
	while (y1 <= y2)
	{
		mlx_put_pixel(cub_data->img, x, y1, new);
		y1++;
	}
}

void	draw_vertical_line(t_data *cub_data, int x, int y_start, int y_end, int color)
{
	int	y;

	y = y_start;
	while (y <= y_end)
	{
		mlx_put_pixel(cub_data->img, x, y, color);
		y++;
	}
}

void	find_wall_height(t_data *data, double dist, int x)
{
	int	line_height;
	int	draw_start;
	int	draw_end;

	if ((int)dist != 0)
		line_height = (int)(HEIGHT / dist);
	else
		line_height = HEIGHT;
	draw_start = HEIGHT / 2 - line_height / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = HEIGHT / 2 + line_height / 2;
	if (draw_end >= HEIGHT)
		draw_end = HEIGHT - 1;
	//draw_vertical_line(data, x, drawStart, drawEnd, 0xFF0000FF);
	//draw_dark_line(data, x, draw_start, draw_end, dist);
	add_textures(data, x, line_height, draw_start, draw_end, dist);
}
 