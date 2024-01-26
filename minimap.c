#include "includes/cub3d.h"
#include "includes/parsing.h"
#include "lib42/include/libft.h"

void	draw_wall(t_data *data, mlx_t *mlx, int x, int y)
{
	mlx_texture_t	*texture_wall;
	mlx_image_t		*img_wall;

	texture_wall = mlx_load_png("wood.png");
	if (!texture_wall)
		ft_error("ERR");
	img_wall = mlx_texture_to_image(mlx, texture_wall);
	if (!img_wall)
		ft_error("ERR");
	if (mlx_image_to_window(mlx, img_wall, x * data->scale_map, y * data->scale_map) < 0)
		ft_error("ERR");
}

void draw_direction(t_data *data)
{
	double x = data->player->posX;
	double y = data->player->posY;
    int n = (fm(data->player->dirX) + fm(data->player->dirY)) * 50;
    double error = fm(data->player->dirX) - fm(data->player->dirY);
    while (n > 0)
    {
		if (((int)data->player->posX * data->scale_map + x) < 0 || ((int)data->player->posX * data->scale_map + x) > data->map_data->map_x * data->scale_map
			|| ((int)data->player->posY * data->scale_map + y) < 0 || ((int)data->player->posY * data->scale_map + y) > data->map_data->map_y * data->scale_map)
			break;
        mlx_put_pixel(data->img2, data->player->posX * data->scale_map + x, data->player->posY * data->scale_map + y, COLOR_RED);
	    if (error > 0)
        {
            x += data->player->dirX;
            error -= fm(data->player->dirY);
        }
        else
        {
            y += data->player->dirY;
            error += fm(data->player->dirX);
        }
		n--;
    }
}


void draw_player(t_data *data)
{
	mlx_texture_t	*player;

	player = mlx_load_png("play.png");
	if (!player)
		ft_error("ERR");
	data->img_player = mlx_texture_to_image(data->mlx, player);
	if (!data->img_player)
		ft_error("ERR");
	mlx_resize_image(data->img_player, 10, 10);
	if (mlx_image_to_window(data->mlx, data->img_player, data->player->posX * data->scale_map, data->player->posY * data->scale_map) < 0)
		ft_error("ERR");
	draw_direction(data);

}

void draw_map(t_data *data)
{
	int x = 0;
	int y = 0;

	while (y < data->map_data->map_y)
	{
		while (x < 100)
		{
			if (data->map_data->map[y][x] == 1)
				draw_wall(data, data->mlx, x, y);
			// else
			// 	draw_floor(data, data->mlx, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}


void minimap_background(t_data *data) //Need to make decisions about scale
{
	int x;
	int y;
	//int scale;

	x = 0;
	y = 0;
	//data->scale_map = (data->width < data->height) ? WIDTH /data->width / 6 : HEIGHT / data->height / 6 ;
	//printf("Scale %d width %d height %d\n", data->scale_map, data->width, data->height);
	data->scale_map = 30;
	while (y <= (data->map_data->map_y * data->scale_map))
	{
		while (x < WIDTH/2) //(x < ((data->width -1)* data->scale_map))
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