#include "includes/utils.h"
#include "includes/checks.h"
#include "includes/parsing.h"
#include "includes/cub3d.h"
#include "lib42/include/libft.h"
#include <stdio.h>


double findHit(t_data *data)
{
	int 	hit;
	double 	dist;
	int		side;
	int		mapX = data->player->mapX;
	int		mapY = data->player->mapY;
	hit = 0;
	while (hit == 0)
	{
		if (data->ray->sideX < data->ray->sideY)
		{
			data->ray->sideX += data->ray->deltaX;
			mapX += data->ray->stepX;
			side = 0;
		}
		else
		{
			data->ray->sideY += data->ray->deltaY;
			mapY += data->ray->stepY;
			side = 1;
		}
		if (data->map_data->map[mapY][mapX] == '1')
			hit = 1;
	}
	if (side == 0)
		dist = data->ray->sideX - data->ray->deltaX;
	else
		dist = data->ray->sideY - data->ray->deltaY;
	return (dist);
}

void initRaycast(t_data *data)
{
	double dirlen;

	data->ray = malloc(sizeof(t_ray)); // free
	data->ray->sideX = 0.00;
	data->ray->sideY = 0.00;
	data->ray->stepX = 0;
	data->ray->stepY = 0;
	dirlen = sqrt(data->player->dirX * data->player->dirX + data->player->dirY * data->player->dirY);
	data->ray->planeX = data->player->dirY / dirlen * 0.66;
	data->ray->planeY = -data->player->dirX / dirlen * 0.66;
}

void findIntersection(t_data *data, double x1, double y1)
{
	//initRaycast(data);
	if (x1 == 0)
		data->ray->deltaX = INFINITY;
	else
		data->ray->deltaX = sqrt(1 + (y1 * y1) / (x1 * x1));
	if (y1 == 0)
		data->ray->deltaY = INFINITY;
	else
		data->ray->deltaY = sqrt(1 + (x1 * x1) / (y1 * y1));
	if (x1 < 0)
	{
		data->ray->stepX = -1;
		data->ray->sideX = (data->player->posX - data->player->mapX) * data->ray->deltaX;
	}
	else
	{
		data->ray->stepX = 1;
		data->ray->sideX = (data->player->mapX + 1.00 - data->player->posX) * data->ray->deltaX;
	}
	if (y1 < 0)
	{
		data->ray->stepY = -1;
		data->ray->sideY = (data->player->posY - data->player->mapY) * data->ray->deltaY;
	}
	else
	{
		data->ray->stepY = 1;
		data->ray->sideY = (data->player->mapY + 1.00 - data->player->posY) * data->ray->deltaY;
	}
}