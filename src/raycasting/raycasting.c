#include "../../includes/cub3d.h"
#include "../../includes/parsing.h"

void	find_ray_direction(t_data *data, int x)
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
	double	ra;

	x = 0;
	data->player->mapX = (int)data->player->posX;
	data->player->mapY = (int)data->player->posY;
	while (x < WIDTH)
	{

		find_ray_direction(data, x);
		find_intersection(data, data->ray->x1, data->ray->y1);
		dist = find_hit(data);
		ra = atan2(data->ray->y1, data->ray->x1);
		dist = fm(dist * cos(norm_a(&ra) - data->angle));
		data->wallX = data->player->posX + dist * data->ray->y1;
		findWallHeight(data, dist, x);
		//printf("data->wallX %f \n", data->wallX);
		x++;
	}
}

void	init_raycast(t_data *data)
{
	double	dirlen;

	data->ray = malloc(sizeof(t_ray));
	data->ray->sideX = 0.00;
	data->ray->sideY = 0.00;
	data->ray->stepX = 0;
	data->ray->stepY = 0;
	dirlen = sqrt(data->player->dirX * data->player->dirX \
		+ data->player->dirY * data->player->dirY);
	data->ray->planeX = data->player->dirY / dirlen * -0.66;
	data->ray->planeY = -data->player->dirX / dirlen * -0.66;
	data->ray->x1 = 0.00;
	data->ray->y1 = 0.00;
}
