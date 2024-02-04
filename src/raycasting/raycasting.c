#include "../../includes/cub3d.h"
#include "../../includes/parsing.h"

void	findRayDirection(t_data *data, int x)
{
	double	camera;
	double	x1;
	double	y1;

	camera = 2 * x / (double)WIDTH - 1;
	data->ray->x1 = data->player->dirX + data->ray->planeX * camera;
	data->ray->y1 = data->player->dirY + data->ray->planeY * camera;
	data->angle = atan2(data->player->dirY, data->player->dirX);
}

double	norm_a(double *angle)
{
	if (*angle < 0)
		*angle += (2 * PI);
	if (*angle > (2 * PI))
		*angle -= (2 * PI);
	return (*angle);
}

void	raycasting(t_data *data)
{
	int		x;
	double	dist;

	x = 0;
	data->player->mapX = (int)data->player->posX;
	data->player->mapY = (int)data->player->posY;
	while (x < WIDTH)
	{
		findRayDirection(data, x);
		double cur_angle = data->angle - (PI / 2) + (PI / WIDTH) * x;
		findIntersection(data, data->ray->x1, data->ray->y1);
		dist = findHit(data);
		double ra = atan2(data->ray->y1, data->ray->x1);
		dist = fm(dist * cos(norm_a(&ra) - data->angle));
		findWallHeight(data, dist, x);
		x++;
	}
}

void	initRaycast(t_data *data)
{
	double dirlen;

	data->ray = malloc(sizeof(t_ray));
	data->ray->sideX = 0.00;
	data->ray->sideY = 0.00;
	data->ray->stepX = 0;
	data->ray->stepY = 0;
	dirlen = sqrt(data->player->dirX * data->player->dirX + data->player->dirY * data->player->dirY);
	data->ray->planeX = data->player->dirY / dirlen * -0.66;
	data->ray->planeY = -data->player->dirX / dirlen * -0.66;
	data->ray->x1 = 0.00;
	data->ray->y1 = 0.00;
}
