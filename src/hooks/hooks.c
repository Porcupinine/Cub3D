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
void mousing(mouse_key_t button, action_t action, modifier_key_t mods, t_data *data)
{
	// int32_t x;
	// int32_t y;
	if (button == MLX_MOUSE_BUTTON_LEFT && action == MLX_PRESS)
	{
		printf("CLICK\n");

	}

}

void cursoring(double xpos, double ypos, t_data *data)
{
	double angle = (xpos - (double)WIDTH/ 2) /(double)WIDTH; 
	while (angle < 0)
		angle += (2 * PI);
	while (angle > (2 * PI))
		angle -= (2 * PI);
	printf("angle %f", angle);
	// double dirX = data->player->dirX * cos(angle);
	// printf(" real %fdirx %f", data->player->dirX, dirX);
	// data->player->dirX = dirX;
	if ((xpos - (double)WIDTH/ 2) < 0)
		rotate_left(data, angle/10);
	else
		rotate_right(data, angle/10);
}


void let_s_move(mlx_key_data_t keydata, t_data *data)
{
	double angle;
	
	angle = 0.2;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move_forward(data);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		move_back(data);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		move_right(data);
	if (keydata.key == MLX_KEY_A  && keydata.action == MLX_PRESS)
		move_left(data);
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		rotate_left(data, angle);
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		rotate_right(data, angle);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit(EXIT_SUCCESS);
}
