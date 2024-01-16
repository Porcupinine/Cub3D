/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:54:45 by akrepkov          #+#    #+#             */
/*   Updated: 2023/06/02 19:00:28 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/libft/libft.h"
#include "fdf.h"

void	fix_the_hamster_1(t_fdf *data, int *x1, int *y1)
{
	int		c_x1;
	int		c_x2;
	float	height_z;

	data->z_1 = data->matrix[*y1][*x1];
	data->z2 = data->matrix[data->y2h][data->x2h];
	height_z = data->z2 * data->zoom_z;
	c_x1 = *x1;
	c_x2 = data->x2h;
	data->x2h = (data->x2h - data->y2h) * data->zoom * cos(data->a);
	data->y2h = (c_x2 + data->y2h) * data->zoom * data->b - height_z;
	*x1 = (*x1 - *y1) * data->zoom * cos(data->a);
	*y1 = (c_x1 + *y1) * data->zoom * data->b - data->z_1 * data->zoom_z;
}

void	calculations(t_fdf *data, int *x1, int *y1, float *err)
{
	data->dx = fm(data->x2v - *x1);
	data->dy = fm(data->y2v - *y1);
	if (*x1 < data->x2v)
		data->sx = 1;
	else
		data->sx = -1;
	if (*y1 < data->y2v)
		data->sy = 1;
	else
		data->sy = -1;
	*err = data->dx - data->dy;
}

void	calculations_1(t_fdf *data, int *x1, int *y1, float *err)
{
	data->dx = fm(data->x2h - *x1);
	data->dy = fm(data->y2h - *y1);
	if (*x1 < data->x2h)
		data->sx = 1;
	else
		data->sx = -1;
	if (*y1 < data->y2h)
		data->sy = 1;
	else
		data->sy = -1;
	*err = data->dx - data->dy;
}

void	bresenhamster_1(t_fdf *data, int x1, int y1, int color)
{
	float	err;

	fix_the_hamster_1(data, &x1, &y1);
	calculations_1(data, &x1, &y1, &err);
	while (x1 != data->x2h || y1 != data->y2h)
	{
		if ((y1 + data->p_y) < 0 || (y1 + data->p_y) > HEIGHT
			|| (x1 + data->p_x) < 0 || (x1 + data->p_x) > WIDTH)
			break ;
		if ((data->z_1 != 0 || data->z2 != 0) && color != 0x000000)
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

void	check_the_z(t_fdf *data, int res)
{
	if (res > data->z_max)
		data->z_max = res;
	if (res < data->z_min)
		data->z_min = res;
	data->dif = data->z_max - data-> z_min + data->height;
}
