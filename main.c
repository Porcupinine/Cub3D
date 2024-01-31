/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:05:45 by laura             #+#    #+#             */
/*   Updated: 2024/01/30 14:12:42 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/utils.h"
#include "includes/checks.h"
#include "includes/parsing.h"
#include "includes/cub3d.h"
#include "lib42/include/libft.h"
#include <stdio.h>

void draw_env(t_data *data)
{
	int x;
	int y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < HEIGHT / 2)
				mlx_put_pixel(data->img, x, y, data->map_data->celling);
			else
				mlx_put_pixel(data->img, x, y, data->map_data->floor);
			x++;
		}
		y++;
	}
}

void testing(t_data *data)
{
	int x = 0;
	double dist;
	double delta_rays = PI / WIDTH;
	double halfFOV = PI / 2;
	printf("Angle %f\n", data->angle);
	data->player->mapX = (int)data->player->posX;
	data->player->mapY = (int)data->player->posY;
	initRaycast(data);
	while (x < WIDTH)
	{
		// findRayDirection(data);
		double camera = 2 * x / (double)WIDTH - 1;
		double x1;
		double y1;
		x1 = data->player->dirX + data->ray->planeX * camera;
		y1 = data->player->dirY + data->ray->planeY * camera;

		//printf("x1 %f, y1 %f plane X %f plane Y %F\n", x1, y1, data->ray->planeX, data->ray->planeY);
		//mlx_put_pixel(data->img, x1 * 10, y1 * 10, 0xFF0000FF);
		findIntersection(data, x1, y1);
		dist = findHit(data);
		double ra = atan2(y1, x1);
		if (ra < 0)
			ra += 2 * PI;
		if (ra > 2 * PI)
			ra -= 2 * PI;
		dist = fm(dist * cos(ra));
		//printf("ANGLE %f\n", ra);
		findWallHeight(data, dist, x);
		x++;
	}
	printf("\n\n");
}

int main(int argc, char **argv)
{
	t_data *cub_data;
	
	if (argc != 2)
	{
		printf("wrong amount of args!\n");
		return (1);
	}
	cub_data = ft_calloc(1, sizeof(t_data));
	if (cub_data == NULL)
		ft_error("Malloc fail\n");
	cub_data->map_data = get_data(argv[1]);
	print_map(cub_data->map_data);
	check_map(cub_data);
	check_values(cub_data->map_data);
	cub_data->mlx = mlx_init(WIDTH, HEIGHT, "CUB", NULL);
	if (!cub_data->mlx)
		ft_error("MLX initialization fail\n");
	cub_data->img = mlx_new_image(cub_data->mlx, WIDTH, HEIGHT);
	if (mlx_image_to_window(cub_data->mlx, cub_data->img, 0, 0) < 0)
		ft_error("Drawing image fail\n");
	draw_env(cub_data);
	initRaycast(cub_data);
	testing(cub_data);
	//minimap_background(cub_data);

	mlx_key_hook(cub_data->mlx, (void *)&let_s_move, cub_data);
	mlx_loop(cub_data->mlx);
	mlx_terminate(cub_data->mlx);
	return (0);
}
