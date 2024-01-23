#include "cub3d.h"

double fm(double a)
{
	if (a < 0)
	{
		return (-(a));
	}
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
	double ray = data->angle - RA;
	int x = 0;
	while(x < WIDTH)
	{
		if (ray < 0)
			ray += (2 * PI);
		if (ray > (2 * PI))
			ray -= (2 * PI);
		printf("RAY RA %f %f\n", ray, ray * 180 / PI);
		int mapX = (int)data->posX;
		int mapY = (int)data->posY;
		double sideDistX;
		double sideDistY;
		double startX;
		double startY;
		int stepX;
		int stepY;

		double X_angle;
		double Y_angle;
		if (ray > 1.57 && ray < 4.72)
		{
			X_angle = tan(fm(ray - PI));
			startX = (data->posX - mapX) / X_angle;
			stepX = -1;
		}
		else
		{
			X_angle = tan(fm(ray - 2 * PI));
			startX = ((mapX + 1) - data->posX ) / X_angle;
			stepX = 1;
		}
		if (ray > 3.14)
		{
			Y_angle = sin(fm(ray - 3 * PI / 4));
			startY = (data->posY - mapY) / Y_angle;
			stepY = -1;
		}
		else
		{
			Y_angle = sin(fm(ray - PI / 2));
			startY = ((mapY + 1) - data->posY) / Y_angle;
			stepY = 1;
		}
		double deltaX = 1 / X_angle;
		double deltaY = 1 / Y_angle;
		int hit = 0;
		while(hit == 0)
		{
			if (startX < startY)
			{
				startX += deltaX;
				mapX +=stepX;
			}
			else
			{
				startY += deltaY;
				mapY +=stepY;
			}
			if (data->matrix[mapY][mapX] == 1)
				hit = 1;
			printf("Map X %d map Y %d\n", mapX, mapY);
			//hit++;
		}
		double dist = (startX < startY) ? startX : startY;
		printf("Dist %f\n",dist);
		int lineHeight = (int)(HEIGHT / dist);

		int drawStart = -lineHeight / 2 + HEIGHT / 2;
		if(drawStart < 0) drawStart = 0;
		int drawEnd = lineHeight / 2 + HEIGHT / 2;
		if(drawEnd >= HEIGHT) drawEnd = HEIGHT - 1;

		drawVerticalLine(data, x, drawStart, drawEnd, COLOR_BLUE);
		mlx_key_hook(data->mlx, (void *)&let_s_move, data);
		ray += 60.00/(double)WIDTH* PI / 180;
		x++;

	}
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
	data.img2 = mlx_new_image(data.mlx, WIDTH, HEIGHT); //for minimap
	if (!data.img2 || (mlx_image_to_window(data.mlx, data.img2, 0, 0) < 0))
		return (-1);
	testing(&data);
	minimap_background(&data);
	mlx_key_hook(data.mlx, (void *)&let_s_move, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (EXIT_SUCCESS);
}

// rayangle = data->angle * 180/ PI - 60;