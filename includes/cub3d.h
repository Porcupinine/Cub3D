/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:41:22 by lpraca-l          #+#    #+#             */
/*   Updated: 2024/02/19 15:44:59 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <unistd.h>
# include <stdlib.h>
# include <memory.h>
# include <fcntl.h>
# include <math.h>
# include <errno.h>
# include <stdio.h>
# include "structs.h"
# define WIDTH 1200
# define HEIGHT 1200
# define PI 3.1415

/*Hooks*/
void	let_s_move(mlx_key_data_t keydata, t_data *data);
void	draw_env(t_data *data);

/*Minimap*/
void	draw_map(t_data *data, int y, int x);
void	draw_square(t_data *data, int draw_x, int draw_y, int color);
void	draw_player(t_data *data);

/*Images*/

void	init_map_images(t_data *data);
void	init_image(t_data *data);

/*Raycasting*/
double	fm(double a);
void	find_ray_direction(t_data *data, int x);
double	norm_a(double *angle);
void	raycasting(t_data *data);
void	init_raycast(t_data *data);
double	find_hit(t_data *data);
void	find_intersection(t_data *data, double x1, double y1);

/*Hooks*/
void	rotate_left(t_data *data, double angle);
void	rotate_right(t_data *data, double angle);
void	update_images(t_data *data);
void	move_forward(t_data *data);
void	move_back(t_data *data);
void	move_right(t_data *data);
void	move_left(t_data *data);
int		wall_check(t_data *data, double y_end, double x_end);
void	update_images(t_data *data);
void	mousing(mouse_key_t button, action_t action, \
	modifier_key_t mods, t_data *data);
void	cursoring(double xpos, double ypos, t_data *data);

#endif