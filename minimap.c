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
	mlx_resize_image(img_wall, data->scale_map, data->scale_map);
	if (!img_wall)
		ft_error("ERR");
	if (mlx_image_to_window(mlx, img_wall, x * data->scale_map, y * data->scale_map) < 0)
		ft_error("ERR");
}

void findOrientation(t_data *data, int x, double camera)
{
	double x1 = data->player->dirX + data->ray->planeX * camera;
	double y1 = data->player->dirY + data->ray->planeY * camera;
	if (x1 < 0)
		data->player->orientation = 0;
	else
		data->player->orientation = 1;
	if (y1 < 0)
		data->player->orientation += 1;
	else
		data->player->orientation += 3;
}

void draw_direction(t_data *data)
{
	double x = data->player->posX + data->scale_map / 2;
	double y = data->player->posY + data->scale_map / 2;
	
    int n = 50;//(fm(data->player->dirX) + fm(data->player->dirY)) * 50;
    double error = fm(data->player->dirX) - fm(data->player->dirY);
	// double x1 = data->player->dirX + data->ray->planeX * camera;
	// double y1 = data->player->dirY + data->ray->planeY * camera;
	// while(x < 10)
	// {
	// 	double camera = 2 * x / 10 - 1;
	// 	findOrientation(data, x, camera);
	// 	if (data->player->orientation == 1)
	// 	{
	// 		x = data->player->posX + data->scale_map / 2;
	// 		y = data->player->posY + data->scale_map / 2;
	// 	}
		while (n > 0)
		{
			if (((int)(data->player->posX * data->scale_map + x)) < 0 || ((int)(data->player->posX * data->scale_map + x)) > data->map_data->map_x * data->scale_map
				|| ((int)(data->player->posY * data->scale_map + y)) < 0 || ((int)(data->player->posY * data->scale_map + y)) > data->map_data->map_y * data->scale_map)
				break;
			mlx_put_pixel(data->img, data->player->posX * data->scale_map + x, data->player->posY * data->scale_map + y, COLOR_RED);
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
    // }
}


void draw_player(t_data *data)
{
	mlx_texture_t	*player_pic;
	mlx_image_t		*img_wall;

	player_pic = mlx_load_png("play.png");
	if (!player_pic)
		ft_error("ERR");
	data->img_player = mlx_texture_to_image(data->mlx, player_pic);
	if (!data->img_player)
		ft_error("ERR");
	mlx_resize_image(data->img_player, data->scale_map, data->scale_map);
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
		while (x < data->map_data->map_x)
		{
			if (data->map_data->map[y][x] == '1')
			{		
				draw_wall(data, data->mlx, x, y);
			}
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
	data->scale_map = 20; //temp
	// data->img2 = mlx_new_image(data->mlx, data->map_data->map_x * data->scale_map, data->map_data->map_y * data->scale_map); //for minimap
	// if (!data->img2 || (mlx_image_to_window(data->mlx, data->img2, 0, 0) < 0))
	// 	ft_error("Minimap image fail\n");
	//data->scale_map = (data->width < data->height) ? WIDTH /data->width / 6 : HEIGHT / data->height / 6 ;
	//printf("Scale %d width %d height %d\n", data->scale_map, data->width, data->height);
	while (y < (data->map_data->map_y * data->scale_map))
	{
		while (x < data->map_data->map_x * data->scale_map) //(x < ((data->width -1)* data->scale_map))
		{
			mlx_put_pixel(data->img, x, y, 0xFFFF00);
			x++;
		}
		x = 0;
		y++;
	}
	draw_map(data);
	draw_direction(data);
	draw_player(data);
	mlx_key_hook(data->mlx, (void *)&let_s_move, data);
}