#include "../../includes/cub3d.h"
#include "../../includes/parsing.h"
#include "../../lib42/include/libft.h"

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