#include "cub3d.h"

int fm(int a)
{
	if (a < 0)
		return (-(a));
	return (a);
}

void drawVerticalLine(t_cub *data, int x, int y_start, int y_end, int color)
{
	int y;

	y = y_start;
	while (y <= y_end)
	{
		mlx_put_pixel(data->img, x, y, color);
		y++;
	}
}

void testing(t_cub *data)
{
	
	drawVerticalLine(data, 10, 0, 100, COLOR_BLUE);
	mlx_key_hook(data->mlx, (void *)&let_s_move, data);
}

int32_t main(void)
{
	t_cub data;

	read_map("./maps/easy.cub", &data);
	find_positions(&data);
	data.mlx = mlx_init(WIDTH, HEIGHT, "CUB", NULL);
	if (!data.mlx)
		exit(1);
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	if (!data.img)
		exit(1);
	if (mlx_image_to_window(data.mlx, data.img, 0, 0) < 0)
		exit(1);
	data.img2 = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	if (!data.img2 || (mlx_image_to_window(data.mlx, data.img2, 0, 0) < 0))
		return (-1);
	testing(&data);
	minimap_background(&data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (EXIT_SUCCESS);
}
