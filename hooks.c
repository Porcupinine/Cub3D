#include "cub3d.h"

void let_s_move(mlx_key_data_t keydata, t_cub *data)
{
	double rotSpeed = 3.14 / 18;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
	{

		data->posY -= 1;
		printf("PRESSED W POS: %f %f DIR: %f %f\n", data->posX, data->posY, data->dirX, data->dirY);
		mlx_delete_image(data->mlx, data->img);
		mlx_delete_image(data->mlx, data->img2); //add everywhere
		data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
		mlx_image_to_window(data->mlx, data->img, 0, 0);
		testing(data);
		minimap_background(data);
	}
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
	{
		data->posY += 1;
		printf("PRESSED W POS: %f %f DIR: %f %f\n", data->posX, data->posY, data->dirX, data->dirY);
		mlx_delete_image(data->mlx, data->img);
		data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
		mlx_image_to_window(data->mlx, data->img, 0, 0);
		testing(data);
		minimap_background(data);
	}
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
	{
		data->posX -= 1;
		printf("PRESSED W POS: %f %f DIR: %f %f\n", data->posX, data->posY, data->dirX, data->dirY);
		mlx_delete_image(data->mlx, data->img);
		data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
		mlx_image_to_window(data->mlx, data->img, 0, 0);
		testing(data);
		minimap_background(data);
	}
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
	{
		data->posX += 1;
		printf("PRESSED W POS: %f %f DIR: %f %f\n", data->posX, data->posY, data->dirX, data->dirY);
		mlx_delete_image(data->mlx, data->img);
		data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
		mlx_image_to_window(data->mlx, data->img, 0, 0);
		testing(data);
		minimap_background(data);
	}
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
	{
		double oldDirX = data->dirX;
		data->dirX = data->dirX * cos(-rotSpeed) - data->dirY * sin(-rotSpeed);
		data->dirY = oldDirX * sin(-rotSpeed) + data->dirY * cos(-rotSpeed);
		double oldPlaneX = data->plane_X;
		data->plane_X = data->plane_X * cos(-rotSpeed) - data->plane_Y * sin(-rotSpeed);
		data->plane_Y = oldPlaneX * sin(-rotSpeed) + data->plane_Y * cos(-rotSpeed);
		mlx_delete_image(data->mlx, data->img);
		data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
		mlx_image_to_window(data->mlx, data->img, 0, 0);
		printf("left POS: %f %f DIR: %f %f PLANE %f %f\n", data->posX, data->posY, data->dirX, data->dirY, data->plane_X, data->plane_Y);
		testing(data);
	}
	// rotate to the left
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
	{
		// both camera direction and camera plane must be rotated
		double oldDirX = data->dirX;
		data->dirX = data->dirX * cos(rotSpeed) - data->dirY * sin(rotSpeed);
		data->dirY = oldDirX * sin(rotSpeed) + data->dirY * cos(rotSpeed);
		double oldPlaneX = data->plane_X;
		data->plane_X = data->plane_X * cos(rotSpeed) - data->plane_Y * sin(rotSpeed);
		data->plane_Y = oldPlaneX * sin(rotSpeed) + data->plane_Y * cos(rotSpeed);
		mlx_delete_image(data->mlx, data->img);
		// data->mlx = mlx_init(WIDTH, HEIGHT, "CUB3D", true);
		data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
		mlx_image_to_window(data->mlx, data->img, 0, 0);
		printf("right POS: %f %f DIR: %f %f\n", data->posX, data->posY, data->dirX, data->dirY);
		testing(data);
	}
}
// To rotate a vector, multiply it with the rotation matrix

// [ cos(a) -sin(a) ]
// [ sin(a)  cos(a) ]
// data->x2h = (data->x2h - data->y2h) * cos(data->a);
// data->y2h = (c_x2 + data->y2h) * data->b ;
// *x1 = (*x1 - *y1) * cos(data->a);
// *y1 = (c_x1 + *y1) * data->b;

	// if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
	// {
	// 	double oldDirX = data->dirX;
	// 	data->dirX = data->dirX * cos(-rotSpeed) - data->dirY * sin(-rotSpeed);
	// 	data->dirY = oldDirX * sin(-rotSpeed) + data->dirY * cos(-rotSpeed);
	// 	double oldPlaneX = data->plane_X;
	// 	data->plane_X = data->plane_X * cos(-rotSpeed) - data->plane_Y * sin(-rotSpeed);
	// 	data->plane_Y = oldPlaneX * sin(-rotSpeed) + data->plane_Y * cos(-rotSpeed);
	// 	mlx_delete_image(data->mlx, data->img);
	// 	// data->mlx = mlx_init(WIDTH, HEIGHT, "CUB3D", true);
	// 	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	// 	mlx_image_to_window(data->mlx, data->img, 0, 0);
	// 	printf("left POS: %f %f DIR: %f %f PLANE %f %f\n", data->posX, data->posY, data->dirX, data->dirY, data->plane_X, data->plane_Y);
	// 	testing(data);
	// }
	// // rotate to the left
	// if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
	// {
	// 	// both camera direction and camera plane must be rotated
	// 	double oldDirX = data->dirX;
	// 	data->dirX = data->dirX * cos(rotSpeed) - data->dirY * sin(rotSpeed);
	// 	data->dirY = oldDirX * sin(rotSpeed) + data->dirY * cos(rotSpeed);
	// 	double oldPlaneX = data->plane_X;
	// 	data->plane_X = data->plane_X * cos(rotSpeed) - data->plane_Y * sin(rotSpeed);
	// 	data->plane_Y = oldPlaneX * sin(rotSpeed) + data->plane_Y * cos(rotSpeed);
	// 	mlx_delete_image(data->mlx, data->img);
	// 	// data->mlx = mlx_init(WIDTH, HEIGHT, "CUB3D", true);
	// 	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	// 	mlx_image_to_window(data->mlx, data->img, 0, 0);
	// 	printf("right POS: %f %f DIR: %f %f\n", data->posX, data->posY, data->dirX, data->dirY);
	// 	testing(data);
	// }