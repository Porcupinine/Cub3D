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

	oldDirX = data->player->dirx;
	data->player->dirx = data->player->dirx * cos(angle) + data->player->diry * sin(angle);
	data->player->diry = -oldDirX * sin(angle) + data->player->diry * cos(angle);
	oldPlaneX = data->ray->planex;
	data->ray->planex = data->ray->planex * cos(angle) + data->ray->planey * sin(angle);
	data->ray->planey = -oldPlaneX * sin(angle) + data->ray->planey * cos(angle);
	update_images(data);
}

void	rotate_right(t_data *data, double angle)
{
	double oldDirX;
	double oldPlaneX;

	oldDirX = data->player->dirx;
	data->player->dirx = data->player->dirx * cos(angle) - data->player->diry * sin(angle);
	data->player->diry = oldDirX * sin(angle) + data->player->diry * cos(angle);
	oldPlaneX = data->ray->planex;
	data->ray->planex = data->ray->planex * cos(angle) - data->ray->planey * sin(angle);
	data->ray->planey = oldPlaneX * sin(angle) + data->ray->planey * cos(angle);
	update_images(data);
}