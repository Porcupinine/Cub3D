#include "../../includes/cub3d.h"
#include "../../includes/parsing.h"
#include "../../lib42/include/libft.h"


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

void	rotate_left(t_data *data, double angle)
{
	double oldDirX;
	double oldPlaneX;

	oldDirX = data->player->dirX;
	data->player->dirX = data->player->dirX * cos(angle) + data->player->dirY * sin(angle);
	data->player->dirY = -oldDirX * sin(angle) + data->player->dirY * cos(angle);
	oldPlaneX = data->ray->planeX;
	data->ray->planeX = data->ray->planeX * cos(angle) + data->ray->planeY * sin(angle);
	data->ray->planeY = -oldPlaneX * sin(angle) + data->ray->planeY * cos(angle);
	update_images(data);
}

void	rotate_right(t_data *data, double angle)
{
	double oldDirX;
	double oldPlaneX;

	oldDirX = data->player->dirX;
	data->player->dirX = data->player->dirX * cos(angle) - data->player->dirY * sin(angle);
	data->player->dirY = oldDirX * sin(angle) + data->player->dirY * cos(angle);
	oldPlaneX = data->ray->planeX;
	data->ray->planeX = data->ray->planeX * cos(angle) - data->ray->planeY * sin(angle);
	data->ray->planeY = oldPlaneX * sin(angle) + data->ray->planeY * cos(angle);
	update_images(data);
}