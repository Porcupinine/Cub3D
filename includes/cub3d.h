
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
#define COLOR_AMMO 0xeda705
#define COLOR_BLUE 0xbfbd2c
#define COLOR_RED 0xFF0000FF

/*Hooks*/
void	let_s_move(mlx_key_data_t keydata, t_data *data);
void	draw_env(t_data *data);

/*Graphics*/
void	findWallHeight(t_data *data, double dist, int x);
void	drawVerticalLine(t_data *cub_data, int x, int y_start, int y_end, int color);
void	drawDarkLine(t_data *cub_data, int x, int y_start, int y_end, double dark);

/*Minimap*/
void	create_minimap(t_data *data);
void	player_pos_map(t_data *data);

/*Images*/

void	init_map_images(t_data *data);
void	init_image(t_data *data);

/*Raycasting*/
double	fm(double a);
void	draw_vertical(t_data *data, int x, int y_start, int y_end, int color);
void	findOrientation(t_data *data, int x, double camera);
void	findRayDirection(t_data *data, int x);
double	norm_a(double *angle);
void	raycasting(t_data *data);
void	initRaycast(t_data *data);
double	findHit(t_data *data);
void	findIntersection(t_data *data, double x1, double y1);

#endif