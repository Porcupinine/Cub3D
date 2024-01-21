#include "cub3d.h"

void	find_direction(t_cub *data, int y, int x)
{
	if (data->matrix[y][x] == 30 || data->matrix[y][x] == 35)
		data->dirX = 0;
	if (data->matrix[y][x] == 21 || data->matrix[y][x] == 39)
		data->dirY = 0;
	if (data->matrix[y][x] == 21)
		data->dirX = 1;
	if (data->matrix[y][x] == 39)
		data->dirX = -1;
	if (data->matrix[y][x] == 30)
		data->dirY = -1;
	if (data->matrix[y][x] == 35)
		data->dirY = 1;
	data->plane_X = 0;
	data->plane_Y = 0.66; //angle FOV
	printf("POS %f %f and dir %f %f for %d\n", data->posX, data->posX, data->dirX, data->dirY, data->matrix[y][x]);
}

void	find_positions(t_cub *data)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < data->height)
	{
		while (x < data->width)
		{
			if (data->matrix[y][x] != 0 && data->matrix[y][x] != 1)
			{
				data->posX = x;
				data->posY = y;
				find_direction(data, y, x);
			}
			x++;
		}
		x = 0;
		y++;
	}
}
