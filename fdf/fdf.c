/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:58:51 by akrepkov          #+#    #+#             */
/*   Updated: 2023/06/02 19:24:24 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs/MLX42/include/MLX42/MLX42.h"
#include "libs/libft/libft.h"
#include "src/fdf.h"
#include <stdio.h>
#include <math.h>

void	fix_the_hamster(t_fdf *data, int *x1, int *y1)
{
	int		c_x1;
	int		c_x2;
	float	height_z;

	data->z_1 = data->matrix[*y1][*x1];
	data->z3 = data->matrix[data->y2v][data->x2v];
	height_z = data->z3 * data->zoom_z;
	c_x1 = *x1;
	c_x2 = data->x2v;
	data->x2v = (data->x2v - data->y2v) * data->zoom * cos(data->a);
	data->y2v = (c_x2 + data->y2v) * data->zoom * data->b - height_z;
	*x1 = (*x1 - *y1) * data->zoom * cos(data->a);
	*y1 = (c_x1 + *y1) * data->zoom * data->b - data->z_1 * data->zoom_z;
}

void	bresenhamster(t_fdf *data, int x1, int y1, int color)
{
	float	err;

	fix_the_hamster(data, &x1, &y1);
	calculations(data, &x1, &y1, &err);
	while (x1 != data->x2v || y1 != data->y2v)
	{
		if ((y1 + data->p_y) < 0 || (y1 + data->p_y) > HEIGHT
			|| (x1 + data->p_x) < 0 || (x1 + data->p_x) > WIDTH)
			break ;
		if ((data->z_1 != 0 || data->z3 != 0) && color != 0x000000)
			mlx_put_pixel(data->img, x1 + data->p_x, y1 + data->p_y, BLACK);
		else
			mlx_put_pixel(data->img, x1 + data->p_x, y1 + data->p_y, color);
		data->e2 = (2 * err);
		if (data->e2 > -data->dy)
		{
			err -= data->dy;
			x1 += data->sx;
		}
		if (data->e2 < data->dx)
		{
			err += data->dx;
			y1 += data->sy;
		}
	}
}

void	drawing_line(t_fdf *data, int color)
{
	data->x = 0;
	data->y = 0;
	while (data->y < data->height)
	{
		while (data->x < data->width)
		{
			if (data->x < data->width - 1)
			{
				data->x2h = data->x + 1;
				data->y2h = data->y;
				bresenhamster_1(data, data->x, data->y, color);
			}
			if (data->y < data->height - 1)
			{
				data->x2v = data->x;
				data->y2v = data->y + 1;
				bresenhamster(data, data->x, data->y, color);
			}
			data->x++;
		}
		data->x = 0;
		data->y++;
	}
}

void	set_param(t_fdf *data)
{
	data->z_max = 0;
	data->z_min = 0;
	data->zoom = 100;
	while (data->zoom * data->dif >= (HEIGHT / 2))
		data->zoom /= 2;
	if (data->zoom * data->width >= WIDTH)
		data->zoom /= 2;
	data->a = M_PI / 6;
	data->b = sin(M_PI / 6);
	data->zoom_z = data->zoom / 4;
	data->p_x = (float)WIDTH / 2;
	data->p_y = (float)HEIGHT / 2;
}

int32_t	main(int argc, char **argv)
{
	t_fdf	data;

	if (argc != 2)
		return (0);
	data.width = 0;
	if (read_map(argv[1], &data) != 0)
		exit (0);
	set_param(&data);
	data.mlx = mlx_init(WIDTH, HEIGHT, "FDF", NULL);
	if (!data.mlx)
		return (0);
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	if (!data.img)
		exit (0);
	if (mlx_image_to_window(data.mlx, data.img, 0, 0) < 0)
		exit (0);
	mlx_key_hook(data.mlx, (void *)&my_hook, &data);
	drawing_line(&data, 0xFFFFFF);
	mlx_loop(data.mlx);
	mlx_close_window(data.mlx);
	return (0);
}
