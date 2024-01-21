#include "cub3d.h"


//just colored wall

// void draw_map_colored(t_cub *data)
// {
// 	int x = 0;
// 	int y = 0;
// 	int count_x = 0;
// 	int count_y = 0;

// 	while (y < data->height)
// 	{
// 		while (x < data->width)
// 		{
// 			if (data->matrix[y][x] == 30)
// 			{
// 				int count_x = 0;
// 				int count_y = 0;
// 				while (count_y < data->scale_map)
// 				{
// 					while (count_x < data->scale_map)
// 					{
// 						mlx_put_pixel(data->img2, x * data->scale_map + count_x, y * data->scale_map + count_y, COLOR_BLUE); // Fix: Corrected placement
// 						count_x++;
// 					}
// 					count_x = 0;
// 					count_y++;
// 				}
// 			}
// 			x++;
// 		}
// 		x = 0;
// 		y++;
// 	}
// }
void	draw_wall(t_cub *data, mlx_t *mlx, int x, int y)
{
	mlx_texture_t	*texture_wall;
	mlx_texture_t	*player;
	mlx_image_t		*img_wall;

	texture_wall = mlx_load_png("wall.png");
	if (!texture_wall)
		perror("ERR");
	img_wall = mlx_texture_to_image(mlx, texture_wall);
	if (!img_wall)
		perror("ERR");
	if (mlx_image_to_window(mlx, img_wall, x * data->scale_map, y * data->scale_map) < 0)
		perror("ERR");
}

void draw_direction(t_cub *data) //check for us
{

    double dx = fabs(data->dirX  - data->posX);
    double dy = fabs(data->dirY - data->posY);
    double x = data->posX;
    double y = data->posY;
    int n = 30;
    double x_inc = (data->dirX > data->posX) ? 1 : -1;
    double y_inc = (data->dirY > data->posY) ? 1 : -1;
    double error = dx - dy;
    dx *= 2;
    dy *= 2;

    for (; n > 0; --n)
    {
        mlx_put_pixel(data->img2, (int)data->posX * data->scale_map + x, (int)data->posY * data->scale_map + y, COLOR_RED);
        if (error > 0)
        {
            x += x_inc;
            error -= dy;
        }
        else
        {
            y += y_inc;
            error += dx;
        }
    }
}

void draw_player(t_cub *data)
{
	int x = 0;
	int y = 0;
	int mapX = (int)data->posX;
	int mapY = (int)data->posY;
	while(y < data->scale_map)
	{
		while(x < data->scale_map)
		{
			mlx_put_pixel(data->img2, mapX * data->scale_map + x, mapY * data->scale_map + y, COLOR_RED); // Fix: Corrected placement
			x++;
		}
		x = 0;
		y++;
	}
	draw_direction(data);

}

void draw_map(t_cub *data)
{
	int x = 0;
	int y = 0;

	while (y < data->height)
	{
		while (x < data->width)
		{
			if (data->matrix[y][x] == 1)
				draw_wall(data, data->mlx, x, y);
			// else
			// 	draw_floor(data, data->mlx, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}


void minimap_background(t_cub *data)
{
	int x;
	int y;
	int scale;

	x = 0;
	y = 0;
	data->scale_map = (data->width < data->height) ? WIDTH /data->width / 6 : HEIGHT / data->height / 6 ;
	printf("Scale %d width %d height %d\n", data->scale_map, data->width, data->height);

	while (y < data->height * data->scale_map)
	{
		while (x < data->width * data->scale_map)
		{
			mlx_put_pixel(data->img2, x, y, COLOR_BLUE); // Fix: Added y * scale
			x++;
		}
		x = 0;
		y++;
	}
	draw_map(data);
	draw_player(data);
}