#include "includes/cub3d.h"
#include "includes/parsing.h"
#include "lib42/include/libft.h"

void draw_player(t_data *data)
{
	if (mlx_image_to_window(data->mlx, data->map->img_player, 6 * data->scale_map, 3 * data->scale_map) < 0)
		ft_error("Minimap images fail");
}

void draw_square(t_data *data, int draw_x, int draw_y, int color)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < data->scale_map)
	{
		while (x < data->scale_map)
		{
			mlx_put_pixel(data->img, draw_x * data->scale_map + x, draw_y * data->scale_map + y, color);
			x++;
		}
		x = 0;
		y++;
	}
}

void draw_map(t_data *data)
{
	int y = 7;
	int x = 13;
	int draw_x = 0;
	int draw_y = 0;
	while (y > 0)
	{
		draw_y = (int)(data->player->posY) + y - 3;
		x = 13;
		while (x > 0)
		{

			draw_x = (int)(data->player->posX) + x - 6;
			if (draw_x < 0 || draw_x >= data->map_data->map_x || draw_y < 0 || draw_y >= data->map_data->map_y)
				draw_square(data, x, y, 0x5A5AFFFF);
			else if (data->map_data->map[draw_y][draw_x] == '1')
				draw_square(data, x, y, 0xA1A1FFFF);
			else
				draw_square(data, x, y, 0xFFFFFFFF);
			x--;
		}
		y--;
	}
	draw_player(data);
}
