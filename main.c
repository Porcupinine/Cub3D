/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:05:45 by laura             #+#    #+#             */
/*   Updated: 2024/01/29 16:47:01 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/utils.h"
#include "includes/checks.h"
#include "includes/parsing.h"
#include "includes/cub3d.h"
#include "lib42/include/libft.h"
#include <stdio.h>

void drawVerticalLine(t_data *cub_data, int x, int y_start, int y_end, int color)
{
	int y;

	y = y_start;
	while (y <= y_end)
	{
		mlx_put_pixel(cub_data->img, x, y, 0xFF0000FF);
		y++;
	}
}

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
				mlx_put_pixel(data->img, x, y, 0xbfbd2c);
			else
				mlx_put_pixel(data->img, x, y, 0xeda705);
			x++;
		}
		y++;
	}
}

void testing(t_data *data)
{
	int x = 0;
	double delta_rays = PI / WIDTH;
	double halfFOV = PI / 2;
	double dirlen = sqrt(data->player->dirX * data->player->dirX  + data->player->dirY  * data->player->dirY);

	while (x < WIDTH)
	{
		int mapX = (int)data->player->posX;
		int mapY = (int)data->player->posY;
		
		double camera = 2 * x / (double)WIDTH - 1;
		double cur_angle = data->angle - halfFOV + delta_rays * x;
		// if (cur_angle < 0)
		// 	cur_angle += (2 * PI);
		// if (cur_angle > (2 * PI))
		// 	cur_angle -= (2 * PI);
		double x1;
		double y1;
		x1 = data->player->dirX + cos(cur_angle);
		y1 = data->player->dirY + sin(cur_angle);
		printf("angle %f x1 %f y1 %f \n",data->angle, x1, y1);
		double deltaX = sqrt(1 + (y1 * y1) / (x1 * x1));
		double deltaY = sqrt(1 + (x1 * x1)/ (y1 * y1));
		int stepX;
		int stepY;
		double sideX;
		double sideY;

		if (x1 < data->player->posX)
		{
			stepX = -1;
			sideX = (data->player->posX - mapX) * deltaX;
		}
		else
		{
			stepX = 1;
			sideX = (mapX + 1.00 - data->player->posX) * deltaX;			
		}
		if (y1 < data->player->posY)
		{
			stepY = -1;
			sideY = (data->player->posY - mapY) * deltaY;
		}
		else
		{
			stepY = 1;
			sideY = (mapX + 1.00 - data->player->posY) * deltaY;			
		}
		int hit = 0;
		double dist;
		int side;
		while(hit == 0)
		{
			if (sideX < sideY)
			{
				sideX += deltaX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideY += deltaY;
				mapY += stepY;
				side = 1;
			}
			if (data->map_data->map[mapY][mapX] == '1')
				hit = 1;
			printf("MAP %c ", data->map_data->map[mapY][mapX]);	
		}
		if (side == 0)
			dist = sideX - deltaX;
		else
			dist = sideY - deltaY;
		int lineHeight = (int)(HEIGHT / dist);
		printf("\ndist %f\n", dist);
		int drawStart = HEIGHT / 2 - lineHeight / 2 ;
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = HEIGHT / 2 + lineHeight / 2;
		if (drawEnd >= HEIGHT)
			drawEnd = HEIGHT - 1;

		drawVerticalLine(data, x, drawStart, drawEnd, 0xFF0000FF);
		// printf("NEW ray %f\n\n", dist);
		x++;
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("wrong amount of args!\n");
		return (1);
	}
	t_data *cub_data;
	cub_data = ft_calloc(1, sizeof(t_data));
	if (cub_data == NULL)
		ft_error("Malloc fail\n");
	cub_data->map_data = get_data(argv[1]);
	// print_colors(cub_data->map_data);
	print_map(cub_data->map_data);
	check_map(cub_data);
	// printf("START POSITION: %f %f DIR: %c\n", cub_data->player->posX, cub_data->player->posY, cub_data->map_data->map[(int)cub_data->player->posY][(int)cub_data->player->posX]);
	//  add_images(cub_data);
	cub_data->mlx = mlx_init(WIDTH, HEIGHT, "CUB", NULL);
	if (!cub_data->mlx)
		exit(1);
	cub_data->img = mlx_new_image(cub_data->mlx, WIDTH, HEIGHT);
	//memset(cub_data->img->pixels, 255, cub_data->img->width * cub_data->img->height * sizeof(int32_t));
	if (mlx_image_to_window(cub_data->mlx, cub_data->img, 0, 0) < 0)
		exit(1);
	draw_env(cub_data);
	testing(cub_data);
	minimap_background(cub_data);
	mlx_key_hook(cub_data->mlx, (void *)&let_s_move, cub_data);
	mlx_loop(cub_data->mlx);
	mlx_terminate(cub_data->mlx);
	return (0);
}
