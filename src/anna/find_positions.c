// #include "cub3d.h"

// void	find_direction(t_data *cub_data, int y, int x)
// {
// 	if (data->matrix[y][x] == 30 || data->matrix[y][x] == 35)
// 		data->dirX = 0;
// 	if (data->matrix[y][x] == 21 || data->matrix[y][x] == 39)
// 		data->dirY = 0;
// 	if (data->matrix[y][x] == 21)
// 		data->dirX = 1;
// 	if (data->matrix[y][x] == 39)
// 		data->dirX = -1;
// 	if (data->matrix[y][x] == 30)
// 		data->dirY = -1;
// 	if (data->matrix[y][x] == 35)
// 		data->dirY = 1;
// 	data->plane_X = 0;
// 	data->plane_Y = 0.66; //angle FOV
// 	data->angle = atan2(data->dirY, data->dirX);
// 	if (data->angle < 0)
// 		data->angle += (2 * PI);
// 	if (data->angle > (2 * PI))
// 		data->angle -= (2 * PI);
// 	printf("ANGLE %f and dir %f %f for %d\n", data->angle, data->dirX, data->dirY, data->matrix[y][x]);
// }

// void	find_positions(t_data *cub_data)
// {
// 	int x;
// 	int y;

// 	x = 0;
// 	y = 0;
// 	while (y < data->height)
// 	{
// 		while (x < data->width)
// 		{
// 			// printf("%d ", data->matrix[y][x]);
// 			// if (data->matrix[y][x] == 1) //we don't need it
// 			// {
// 			// 	mlx_put_pixel(data->img, x, y, COLOR_AMMO);
// 			// }
// 			if (data->matrix[y][x] != 0 && data->matrix[y][x] != 1)
// 			{
// 				data->posX = x;
// 				data->posY = y;
// 				find_direction(data, y, x);
// 			}
// 			x++;
// 		}
// 		x = 0;
// 		y++;
// 	}
// }
