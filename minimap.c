#include "cub3d.h"

void	draw_wall(t_cub *data, mlx_t *mlx, int x, int y)
{
	mlx_texture_t	*texture_wall;
	mlx_image_t		*img_wall;

	texture_wall = mlx_load_png("wood.png");
	if (!texture_wall)
		perror("ERR");
	img_wall = mlx_texture_to_image(mlx, texture_wall);
	if (!img_wall)
		perror("ERR");
	if (mlx_image_to_window(mlx, img_wall, x * data->scale_map, y * data->scale_map) < 0)
		perror("ERR");
}

void draw_direction(t_cub *data)
{
	double x = data->posX;
	double y = data->posY;
    int n = (fm(data->dirX) + fm(data->dirY)) * 50;
    double error = fm(data->dirX) - fm(data->dirY);
    while (n > 0)
    {
		if (((int)data->posX * data->scale_map + x) < 0 || ((int)data->posX * data->scale_map + x) > data->width * data->scale_map
			|| ((int)data->posY * data->scale_map + y) < 0 || ((int)data->posY * data->scale_map + y) > data->height * data->scale_map)
			break;
        mlx_put_pixel(data->img2, data->posX * data->scale_map + x, data->posY * data->scale_map + y, COLOR_RED);
	    if (error > 0)
        {
            x += data->dirX;
            error -= fm(data->dirY);
        }
        else
        {
            y += data->dirY;
            error += fm(data->dirX);
        }
		n--;
    }
}


void draw_player(t_cub *data)
{
	mlx_texture_t	*player;

	player = mlx_load_png("play.png");
	if (!player)
		perror("ERR");
	data->img_player = mlx_texture_to_image(data->mlx, player);
	if (!data->img_player)
		perror("ERR");
	mlx_resize_image(data->img_player, 10, 10);
	if (mlx_image_to_window(data->mlx, data->img_player, data->posX * data->scale_map, data->posY * data->scale_map) < 0)
		perror("ERR");
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


void minimap_background(t_cub *data) //Need to make decisions about scale
{
	int x;
	int y;
	//int scale;

	x = 0;
	y = 0;
	//data->scale_map = (data->width < data->height) ? WIDTH /data->width / 6 : HEIGHT / data->height / 6 ;
	//printf("Scale %d width %d height %d\n", data->scale_map, data->width, data->height);
	data->scale_map = 30;
	while (y <= (data->height * data->scale_map))
	{
		while (x < ((data->width -1)* data->scale_map))
		{
			mlx_put_pixel(data->img2, x, y, COLOR_BLUE);
			x++;
		}
		x = 0;
		y++;
	}
	draw_map(data);
	draw_player(data);
}