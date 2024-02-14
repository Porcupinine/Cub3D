/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:05:45 by laura             #+#    #+#             */
/*   Updated: 2024/02/02 10:56:50 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/utils.h"
#include "includes/graphics.h"
#include "includes/checks.h"
#include "includes/parsing.h"
#include "includes/cub3d.h"
#include "lib42/include/libft.h"
#include <stdio.h>

void	init_map_images(t_data *data)
{
	data->map = malloc(sizeof(t_minimap));
	if (!data->map)
		ft_error("Malloc fail\n");
	data->map->wall_png = mlx_load_png("wood.png");
	data->map->player_png = mlx_load_png("play.png");
	if (!data->map->wall_png || !data->map->player_png)
		ft_error("Minimap images fail\n");
}

void	findRayDirection(t_data *data, int x)
{
	double	camera;
	double	x1;
	double	y1;

	camera = 2 * x / (double)WIDTH - 1;
	data->ray->x1 = data->player->dirX + data->ray->planeX * camera;
	data->ray->y1 = data->player->dirY + data->ray->planeY * camera;
//	printf("c dy dx: %f %f %f\n", camera, data->player->dirY, data->player->dirX);
	data->angle = atan2(data->player->dirY, data->player->dirX);
}

double	norm_a(double *angle)
{
	if (*angle < 0)
		*angle += (2.0 * PI);
	if (*angle > (2.0 * PI))
		*angle -= (2.0 * PI);
	return (*angle);
}

void	raycasting(t_data *data)
{
	int		x;
	double	dist;
	//double	delta_rays = PI / WIDTH;
	// double	halfFOV = PI / 2;

	x = 0;
	data->player->mapX = (int)data->player->posX;
	data->player->mapY = (int)data->player->posY;
//	printf("POSITION: %d %d\n", data->player->mapX, data->player->mapY);
	while (x < WIDTH)
	{
		findRayDirection(data, x);
		double cur_angle = data->angle - (PI / 2) + (PI / WIDTH) * x;
		// mlx_put_pixel(data->img, x1 * 10, y1 * 10, 0xFF0000FF);
		findIntersection(data, data->ray->x1, data->ray->y1);
		dist = findHit(data);
		data->test_dist = dist;
//		printf("dist 1: %f\n", dist);
		double ra = atan2(data->ray->y1, data->ray->x1);
		double angle = data->angle;
		double cos_1= cos(norm_a(&ra) - angle);
		dist = fm(dist * cos_1);
//		printf("dist 2: %f\n", dist);
		// findOrientation(data);
		findWallHeight(data, dist, x);
		printf("x: %d\n", x);
		x++;
	}
}

void	initRaycast(t_data *data)
{
	double dirlen;

	data->ray = malloc(sizeof(t_ray));
	data->ray->sideX = 0.00;
	data->ray->sideY = 0.00;
	data->ray->stepX = 0;
	data->ray->stepY = 0;
	dirlen = sqrt(data->player->dirX * data->player->dirX + data->player->dirY * data->player->dirY);
	data->ray->planeX = data->player->dirY / dirlen * -0.66;
	data->ray->planeY = -data->player->dirX / dirlen * -0.66;
	data->ray->x1 = 0.00;
	data->ray->y1 = 0.00;
}

void	init_image(t_data *data)
{
	data->mlx = mlx_init(WIDTH, HEIGHT, "CUB", NULL);
	if (!data->mlx)
		ft_error("MLX initialization fail\n");
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (mlx_image_to_window(data->mlx, data->img, 0, 0) < 0)
		ft_error("Drawing image fail\n");
	initRaycast(data);
}


void	game_loop(t_data *data)
{
	//init_map_images(data);
	draw_env(data);
	raycasting(data);
	//create_minimap(data);
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
	get_data(cub_data, argv[1]);
	check_map(cub_data);
	check_values(cub_data);
	init_image(cub_data);
	game_loop(cub_data);
	free(cub_data->ray);
	mlx_terminate(cub_data->mlx);
	print_map(cub_data->map_data);
	return (0);
}