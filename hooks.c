#include "includes/cub3d.h"
#include "includes/parsing.h"
#include <stdio.h>

void delete_images(t_data *data)
{
	mlx_delete_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(data->mlx, data->img, 0, 0);
	draw_env(data);
	// mlx_delete_image(data->mlx, data->img_player);
	// minimap_background(data);
	raycasting(data);
}

int wall_check(t_data *data, double y_end, double x_end)
{
	int x;
	int y;
	x = (int)x_end;
	y = (int)y_end;
	printf("WALL CHECK W POS: %d, %d, matrix %c\n", x, y, data->map_data->map[y][x]);
	if (data->map_data->map[y][x] == '1')
	{
		// add calculation to be closer to wall
		return (-1);
	}
	return (0);
}

void let_s_move(mlx_key_data_t keydata, t_data *data)
{
	double angle = 0.2;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
	{
		printf("PRESSED W POS: %f %f DIR: %f %f\n", data->player->posX, data->player->posY, data->player->dirX, data->player->dirY);
		if (wall_check(data, data->player->posY + data->player->dirY * 0.8, data->player->posX + data->player->dirX * 0.8) == 0)
		{
			data->player->posY += data->player->dirY * 0.8;
			data->player->posX += data->player->dirX * 0.8;
			delete_images(data);
		}
	}
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
	{
		if (wall_check(data, data->player->posY - data->player->dirY * 0.8, data->player->posX - data->player->dirX * 0.8) == 0)
		{
			data->player->posY -= data->player->dirY * 0.8;
			data->player->posX -= data->player->dirX * 0.8;
			printf("PRESSED S POS: %f %f DIR: %f %f\n", data->player->posX, data->player->posY, data->player->dirX, data->player->dirY);
			delete_images(data);
		}
	}
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
	{
		if (wall_check(data, data->player->posY + data->player->dirX * 0.8, data->player->posX - data->player->dirY * 0.8) == 0)
		{
			data->player->posY += data->player->dirX * 0.8;
			data->player->posX -= data->player->dirY * 0.8;
			delete_images(data);
		}
	}
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
	{
		if (wall_check(data, data->player->posY - data->player->dirX * 0.8, data->player->posX + data->player->dirY * 0.8) == 0)
		{
			data->player->posY -= data->player->dirX * 0.8;
			data->player->posX += data->player->dirY * 0.8;
			printf("PRESSED D POS: %f %f DIR: %f %f\n", data->player->posX, data->player->posY, data->player->dirX, data->player->dirY);

			delete_images(data);
		}
	}
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
	{
		double oldDirX;
		double oldPlaneX;
	
		oldDirX = data->player->dirX;
		data->player->dirX = data->player->dirX * cos(angle) + data->player->dirY * sin(angle);
		data->player->dirY = -oldDirX * sin(angle) + data->player->dirY * cos(angle);
		oldPlaneX = data->ray->planeX;
		data->ray->planeX = data->ray->planeX * cos(angle) + data->ray->planeY * sin(angle);
		data->ray->planeY = -oldPlaneX * sin(angle) + data->ray->planeY * cos(angle);
		delete_images(data);
	}
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
	{
		double oldDirX = data->player->dirX;
		data->player->dirX = data->player->dirX * cos(angle) - data->player->dirY * sin(angle);
		data->player->dirY = oldDirX * sin(angle) + data->player->dirY * cos(angle);
		double oldPlaneX = data->ray->planeX;
		data->ray->planeX = data->ray->planeX * cos(angle) - data->ray->planeY * sin(angle);
		data->ray->planeY = oldPlaneX * sin(angle) + data->ray->planeY * cos(angle);
		delete_images(data);
	}
}
