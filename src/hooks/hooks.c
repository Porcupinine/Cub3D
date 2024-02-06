#include "../../includes/cub3d.h"
#include "../../includes/parsing.h"
#include "../../includes/graphics.h"
#include <stdio.h>

void update_images(t_data *data)
{
	draw_env(data);
	raycasting(data);
	if (data->scale_map > 2 && data->scale_map < 100)
		draw_map(data);
}

int wall_check(t_data *data, double y_end, double x_end)
{
	if (data->map_data->map[(int)y_end][(int)x_end] == '1')
		return (-1);
	return (0);
}

void let_s_move(mlx_key_data_t keydata, t_data *data)
{
	double angle = 0.2;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
	{
		if (wall_check(data, data->player->posY + data->player->dirY * 0.8, data->player->posX + data->player->dirX * 0.8) == 0)
		{
			data->player->posY += data->player->dirY * 0.8;
			data->player->posX += data->player->dirX * 0.8;
			update_images(data);
		}
	}
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
	{
		if (wall_check(data, data->player->posY - data->player->dirY * 0.8, data->player->posX - data->player->dirX * 0.8) == 0)
		{
			data->player->posY -= data->player->dirY * 0.8;
			data->player->posX -= data->player->dirX * 0.8;
			printf("PRESSED S POS: %f %f DIR: %f %f\n", data->player->posX, data->player->posY, data->player->dirX, data->player->dirY);
			update_images(data);
		}
	}
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
	{
		if (wall_check(data, data->player->posY + data->player->dirX * 0.8, data->player->posX - data->player->dirY * 0.8) == 0)
		{
			data->player->posY += data->player->dirX * 0.8;
			data->player->posX -= data->player->dirY * 0.8;
			update_images(data);
		}
	}
	if (keydata.key == MLX_KEY_A  && keydata.action == MLX_PRESS)
	{
		if (wall_check(data, data->player->posY - data->player->dirX * 0.8, data->player->posX + data->player->dirY * 0.8) == 0)
		{
			data->player->posY -= data->player->dirX * 0.8;
			data->player->posX += data->player->dirY * 0.8;
			printf("PRESSED D POS: %f %f DIR: %f %f\n", data->player->posX, data->player->posY, data->player->dirX, data->player->dirY);

			update_images(data);
		}
	}
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		rotate_left(data, angle);
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		rotate_right(data, angle);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit(EXIT_SUCCESS);
}
