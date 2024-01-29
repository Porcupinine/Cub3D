#include "includes/cub3d.h"
#include "includes/parsing.h"
#include <stdio.h>

void	delete_images(t_data *data)
{
	mlx_delete_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(data->mlx, data->img, 0, 0);
//	testing(data);
	mlx_delete_image(data->mlx, data->img_player);
	minimap_background(data);
}

int wall_check(t_data *data, double y_end, double x_end)
{
	int	x;
	int	y;
	x = (int)x_end;
	y = (int)y_end;
	printf("WALL CHECK W POS: %d, %d, matrix %d\n", x, y, data->map_data->map[y][x]);
	if (data->map_data->map[y][x] == 1)
	{
		//add calculation to be closer to wall	
		return (-1);
	}
	return (0);
}

void let_s_move(mlx_key_data_t keydata, t_data *data)
{

	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
	{
		printf("PRESSED W POS: %f %f DIR: %f %f\n", data->player->posX, data->player->posY, data->player->dirX, data->player->dirY);
		if (wall_check(data, data->player->posY + data->player->dirY, data->player->posX + data->player->dirX) == 0)
		{
			data->player->posY += data->player->dirY;
			data->player->posX += data->player->dirX;
		}
		delete_images(data);
	}
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
	{
		if (wall_check(data, data->player->posY - data->player->dirY, data->player->posX - data->player->dirX) == 0)
		{
			data->player->posY -= data->player->dirY;
			data->player->posX -= data->player->dirX;
		}
		printf("PRESSED S POS: %f %f DIR: %f %f\n", data->player->posX, data->player->posY, data->player->dirX, data->player->dirY);
		delete_images(data);
	}
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
	{
		if (wall_check(data, data->player->posY - data->player->dirX, data->player->posX + data->player->dirY) == 0)
		{
			data->player->posY -= data->player->dirX;
			data->player->posX += data->player->dirY;
		}
		delete_images(data);
	}
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
	{
		if (wall_check(data, data->player->posY + data->player->dirX, data->player->posX - data->player->dirY) == 0)
		{
			data->player->posY += data->player->dirX;
			data->player->posX -= data->player->dirY;
		}
		delete_images(data);
	}
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
	{
		data->angle -= 0.2;
		if (data->angle < 0)
			data->angle += (2 * PI);
		data->player->dirX = cos(data->angle);
		data->player->dirY = sin(data->angle);
		delete_images(data);
	}
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
	{
		data->angle += 0.2;
		if (data->angle > (2 * PI))
			data->angle -= (2 * PI);
		data->player->dirX = cos(data->angle);
		data->player->dirY = sin(data->angle);
		delete_images(data);
	}
	// if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	// {
	// 	mlx_close_window(data->mlx);
	// 	exit(0);
	// }
}
