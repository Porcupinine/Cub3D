#include "../../includes/cub3d.h"
#include "../../includes/parsing.h"

double	fm(double a)
{
	if (a < 0)
		return (-a);
	return (a);
}

void	draw_vertical(t_data *data, int x, int y_start, int y_end, int color)
{
	int	y;

	y = y_start;
	while (y <= y_end)
	{
		mlx_put_pixel(data->img, x, y, color);
		y++;
	}
}

void	find_orientation(t_data *data, int x, double camera)
{
	double	x1;
	double	y1;

	x1 = data->player->dirX + data->ray->planeX * camera;
	y1 = data->player->dirY + data->ray->planeY * camera;
	if (x1 < 0)
		data->player->orientation = 0;
	else
		data->player->orientation = 1;
	if (y1 < 0)
		data->player->orientation += 1;
	else
		data->player->orientation += 3;
}
