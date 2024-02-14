#include "../../includes/cub3d.h"
#include "../../includes/parsing.h"
#include "../../lib42/include/libft.h"
#include <stdio.h>

double	find_hit(t_data *data)
{
	int		hit;
	double	dist;
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

			data->side = 0;
		}
		else
		{
			data->ray->sideY += data->ray->deltaY;
			mapY += data->ray->stepY;
			data->side = 1;
		}
		if (data->map_data->map[mapY][mapX] == '1')
			hit = 1;
	}
	if (data->side == 0)
		dist = data->ray->sideX - data->ray->deltaX;
	else
		dist = data->ray->sideY - data->ray->deltaY;
	return (dist);
}

void	find_first_step(t_data *data, double x1, double y1)
{
	int	x;
	int	y;

	x = data->player->mapX;
	y = data->player->mapY;
	data->ray->stepX = 1;
	data->ray->stepY = 1;
	if (x1 < 0)
	{
		data->ray->stepX = -1;
		data->ray->sideX = (data->player->posX - x) * data->ray->deltaX;
	}
	else
		data->ray->sideX = (x + 1.00 - data->player->posX) * data->ray->deltaX;
	if (y1 < 0)
	{
		data->ray->stepY = -1;
		data->ray->sideY = (data->player->posY - y) * data->ray->deltaY;
	}
	else
		data->ray->sideY = (y + 1.00 - data->player->posY) * data->ray->deltaY;
}

void	find_intersection(t_data *data, double x1, double y1)
{
	if (x1 == 0)
		data->ray->deltaX = INFINITY;
	else
		data->ray->deltaX = fm(1 / x1);
	if (y1 == 0)
		data->ray->deltaY = INFINITY;
	else
		data->ray->deltaY = fm(1 / y1);
	find_first_step(data, x1, y1);
}
