
#ifndef CUB3D_H
#define CUB3D_H
#include <unistd.h>
#include <stdlib.h>
#include <memory.h>
#include <fcntl.h>
#include <math.h>
#include <errno.h>
#include <stdio.h>
#include "structs.h"
#define BUFFER_SIZE 1
#define WIDTH 1200
#define HEIGHT 1200
#define PI 3.1415
#define COLOR_AMMO 0xeda705 //git rid of them
#define COLOR_BLUE 0xbfbd2c
#define COLOR_RED 0xFF0000FF

/*Hooks*/
void	let_s_move(mlx_key_data_t keydata, t_data *data);
void	draw_env(t_data *data);


/*drawing3d*/
void	findWallHeight(t_data *data, double dist, int x);
int	find_texture_x(t_data *cub_data, double dist);
//void	drawVerticalLine(t_data *cub_data, int x, int y_start, int y_end, int color);


/*Minimap*/
void	draw_map(t_data *data);
void	draw_square(t_data *data, int draw_x, int draw_y, int color);
void	draw_player(t_data *data);

/*Images*/

void	init_map_images(t_data *data);
void	init_image(t_data *data);

/*Raycasting*/
double	fm(double a);
void	draw_vertical(t_data *data, int x, int y_start, int y_end, int color);
void	find_orientation(t_data *data, int x, double camera);
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
void	mousing(mouse_key_t button, action_t action, modifier_key_t mods, t_data *data);
void	cursoring(double xpos, double ypos, t_data *data);


/*Test*/
void	add_textures(t_data *data, int x, int line_height, int start, int end, double dark);

#endif