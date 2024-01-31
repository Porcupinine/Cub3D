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
		{
			dist = data->ray->sideX - data->ray->deltaX;
		}
	else
		{
			dist = data->ray->sideY - data->ray->deltaY;
		}
	return (dist);
}


void findIntersection(t_data *data, double x1, double y1)
{
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