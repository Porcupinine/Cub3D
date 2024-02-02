//#include "../../includes/utils.h"
//#include "../../includes/checks.h"
//#include "../../includes/parsing.h"
//#include "../../includes/cub3d.h"
//#include "../../lib42/include/libft.h"
//#include <stdio.h>
//
//void	drawVerticalLine(t_data *cub_data, int x, int y_start, int y_end, int color)
//{
//	int	y;
//
//	y = y_start;
//	while (y <= y_end)
//	{
//		mlx_put_pixel(cub_data->img, x, y, 0xFF0000FF);
//		y++;
//	}
//}
//
//void	findWallHeight(t_data *data, double dist, int x)
//{
//	int	lineHeight;
//	int	drawStart;
//	int	drawEnd;
//
//	if ((int)dist != 0)
//		lineHeight = (int)(HEIGHT / dist);
//	else
//		lineHeight = HEIGHT;
//	printf("\ndist %f\n", dist);
//	drawStart = HEIGHT / 2 - lineHeight / 2;
//	if (drawStart < 0)
//		drawStart = 0;
//	drawEnd = HEIGHT / 2 + lineHeight / 2;
//	if (drawEnd >= HEIGHT)
//		drawEnd = HEIGHT - 1;
//	drawVerticalLine(data, x, drawStart, drawEnd, 0xFF0000FF);
//}