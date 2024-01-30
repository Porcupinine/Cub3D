#include "../../includes/cub3d.h"
#include "../../includes/parsing.h"


double fm(double a)
{
	if (a < 0)
		return (-a);
	return (a);
}

void draw_vertical(t_data *data, int x, int y_start, int y_end, int color)
{
	int y;

	y = y_start;
	while (y <= y_end)
	{
		mlx_put_pixel(data->img, x, y, color);
		y++;
	}
}