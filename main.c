/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:05:45 by laura             #+#    #+#             */
/*   Updated: 2024/01/31 13:50:50 by akrepkov         ###   ########.fr       */
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

void findRayDirection(t_data *data, int x)
{
	double camera = 2 * x / (double)WIDTH - 1;
	double x1;
	double y1;
	data->ray->x1 = data->player->dirX + data->ray->planeX * camera;
	data->ray->y1 = data->player->dirY + data->ray->planeY * camera;
	data->angle = atan2(data->player->dirY, data->player->dirX);
	printf("x1 %f, y1 %f plane X %f plane Y %F\n", x1, y1, data->ray->planeX, data->ray->planeY);
}

double	norm_a(double *angle)
{
	if (*angle < 0)
		*angle += (2 * PI);
	if (*angle > (2 * PI))
		*angle -= (2 * PI);
	return (*angle);
}

void raycasting(t_data *data)
{
	int x = 0;
	double dist;
	double delta_rays = PI / WIDTH;
	double halfFOV = PI / 2;
	data->player->mapX = (int)data->player->posX;
	data->player->mapY = (int)data->player->posY;
	while (x < WIDTH)
	{
		findRayDirection(data, x);
		double cur_angle = data->angle - halfFOV + delta_rays * x;
		// mlx_put_pixel(data->img, x1 * 10, y1 * 10, 0xFF0000FF);
		findIntersection(data, data->ray->x1, data->ray->y1);
		dist = findHit(data);
		double ra = atan2(data->ray->y1, data->ray->x1);
		dist = fm(dist * cos(norm_a(&ra) - data->angle));
		printf("ANGLE %f\n", ra);
		findWallHeight(data, dist, x);
		x++;
	}
	printf("\n\n");
}

void initRaycast(t_data *data)
{
	double dirlen;

	data->ray = malloc(sizeof(t_ray)); // free
	data->ray->sideX = 0.00;
	data->ray->sideY = 0.00;
	data->ray->stepX = 0;
	data->ray->stepY = 0;
	dirlen = sqrt(data->player->dirX * data->player->dirX + data->player->dirY * data->player->dirY);
	data->ray->planeX = data->player->dirY / dirlen * 0.66;
	data->ray->planeY = -data->player->dirX / dirlen * 0.66;
	data->ray->x1 = 0.00;
	data->ray->y1 = 0.00;
}

void init_image(t_data *data)
{
	data->mlx = mlx_init(WIDTH, HEIGHT, "CUB", NULL);
	if (!data->mlx)
		ft_error("MLX initialization fail\n");
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (mlx_image_to_window(data->mlx, data->img, 0, 0) < 0)
		ft_error("Drawing image fail\n");
	initRaycast(data);
}

void game_loop(t_data *data)
{
	draw_env(data);
	raycasting(data);
	//minimap_background(data);
	mlx_key_hook(data->mlx, (void *)&let_s_move, data);
	mlx_loop(data->mlx);
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
<<<<<<< HEAD
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
=======
	init_image(cub_data);
	game_loop(cub_data);
	free(cub_data->ray);
>>>>>>> anna
	mlx_terminate(cub_data->mlx);
	return (0);
}
