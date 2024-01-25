// void draw_direction(t_cub *data) //check for us
// {

//     double x_end = data->posX + data->dirX;
//     double y_end = data->posY + data->dirY;
//     double dx = fabs(x_end - data->posX);
//     double dy = fabs(y_end - data->posY);
// 	double x = data->posX;
// 	double y = data->posY;
//     int n = 30;
//     double x_inc = (x_end > data->posX) ? 1 : -1;
//     double y_inc = (y_end > data->posY) ? 1 : -1;
//     double error = dx - dy;
//     dx *= 2;
//     dy *= 2;

//     for (; n > 0; --n)
//     {
//         mlx_put_pixel(data->img2, (int)data->posX * data->scale_map + x, (int)data->posY * data->scale_map + y, COLOR_RED);
//         if (error > 0)
//         {
//             x += x_inc;
//             error -= dy;
//         }
//         else
//         {
//             y += y_inc;
//             error += dx;
//         }
//     }
// }

//just colored wall

// void draw_map_colored(t_cub *data)
// {
// 	int x = 0;
// 	int y = 0;
// 	int count_x = 0;
// 	int count_y = 0;

// 	while (y < data->height)
// 	{
// 		while (x < data->width)
// 		{
// 			if (data->matrix[y][x] == 30)
// 			{
// 				int count_x = 0;
// 				int count_y = 0;
// 				while (count_y < data->scale_map)
// 				{
// 					while (count_x < data->scale_map)
// 					{
// 						mlx_put_pixel(data->img2, x * data->scale_map + count_x, y * data->scale_map + count_y, COLOR_BLUE); // Fix: Corrected placement
// 						count_x++;
// 					}
// 					count_x = 0;
// 					count_y++;
// 				}
// 			}
// 			x++;
// 		}
// 		x = 0;
// 		y++;
// 	}
// }

// To rotate a vector, multiply it with the rotation matrix

// [ cos(a) -sin(a) ]
// [ sin(a)  cos(a) ]
// data->x2h = (data->x2h - data->y2h) * cos(data->a);
// data->y2h = (c_x2 + data->y2h) * data->b ;
// *x1 = (*x1 - *y1) * cos(data->a);
// *y1 = (c_x1 + *y1) * data->b;

	// if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
	// {
	// 	double oldDirX = data->dirX;
	// 	data->dirX = data->dirX * cos(-rotSpeed) - data->dirY * sin(-rotSpeed);
	// 	data->dirY = oldDirX * sin(-rotSpeed) + data->dirY * cos(-rotSpeed);
	// 	double oldPlaneX = data->plane_X;
	// 	data->plane_X = data->plane_X * cos(-rotSpeed) - data->plane_Y * sin(-rotSpeed);
	// 	data->plane_Y = oldPlaneX * sin(-rotSpeed) + data->plane_Y * cos(-rotSpeed);
	// 	mlx_delete_image(data->mlx, data->img);
	// 	// data->mlx = mlx_init(WIDTH, HEIGHT, "CUB3D", true);
	// 	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	// 	mlx_image_to_window(data->mlx, data->img, 0, 0);
	// 	printf("left POS: %f %f DIR: %f %f PLANE %f %f\n", data->posX, data->posY, data->dirX, data->dirY, data->plane_X, data->plane_Y);
	// 	testing(data);
	// }
	// // rotate to the left
	// if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
	// {
	// 	// both camera direction and camera plane must be rotated
	// 	double oldDirX = data->dirX;
	// 	data->dirX = data->dirX * cos(rotSpeed) - data->dirY * sin(rotSpeed);
	// 	data->dirY = oldDirX * sin(rotSpeed) + data->dirY * cos(rotSpeed);
	// 	double oldPlaneX = data->plane_X;
	// 	data->plane_X = data->plane_X * cos(rotSpeed) - data->plane_Y * sin(rotSpeed);
	// 	data->plane_Y = oldPlaneX * sin(rotSpeed) + data->plane_Y * cos(rotSpeed);
	// 	mlx_delete_image(data->mlx, data->img);
	// 	// data->mlx = mlx_init(WIDTH, HEIGHT, "CUB3D", true);
	// 	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	// 	mlx_image_to_window(data->mlx, data->img, 0, 0);
	// 	printf("right POS: %f %f DIR: %f %f\n", data->posX, data->posY, data->dirX, data->dirY);
	// 	testing(data);
	// }



// void testing(t_cub *data)
// {
// 	// double planeX = 0, planeY = 0.66; // the 2d raycaster version of camera plane
// 	//printf("pos x %f pos y %f, dir x, y %f %f\n", data->posX, data->posY, data->dirX, data->dirY);
// 	// double rayAngleX = data->angle - RA; //?
// 	// if (rayAngleX < 0)
// 	// 	rayAngleX += (2 * PI);
// 	// double rayAngleY = data->angle + RA; //?
// 	// if (rayAngleY > 2 * PI)
// 	// 	rayAngleY -= (2 * PI);
// 	// printf("RAY angles %f %f\n", rayAngleX, rayAngleY);
// 	double ray = data->angle - RA;
// 	int x = 0;
// 	while(x < WIDTH)
// 	{
// 		if (ray < 0)
// 			ray += (2 * PI);
// 		if (ray > (2 * PI))
// 			ray -= (2 * PI);
// 		printf("RAY RA %f %f\n", ray, ray * 180 / PI);
// 		int mapX = (int)data->posX;
// 		int mapY = (int)data->posY;
// 		//  length of ray from current position to next x or y-side
// 		double sideDistX;
// 		double sideDistY;
// 		// double deltaDistX;
// 		// double deltaDistY;
// 		// double startX = (data->posX - mapX) / tan(ray);
// 		// double startY = (data->posY - mapY) / sin(ray);

// 		//double current_degree = data->angle * 180 / PI;
// 		double startX;
// 		double startY;
// 		int stepX;
// 		int stepY;

// 		double X_angle;
// 		double Y_angle;
// 		if (ray > 1.57 && ray < 4.72)
// 		{
// 			X_angle = tan(fm(ray - PI));
// 			startX = (data->posX - mapX) / X_angle;
// 			stepX = -1;
// 		}
// 		else
// 		{
// 			X_angle = tan(fm(ray - 2 * PI));
// 			startX = ((mapX + 1) - data->posX ) / X_angle;
// 			stepX = 1;
// 		}
// 		if (ray > 3.14)
// 		{
// 			Y_angle = sin(fm(ray - 3 * PI / 4));
// 			startY = (data->posY - mapY) / Y_angle;
// 			stepY = -1;
// 		}
// 		else
// 		{
// 			Y_angle = sin(fm(ray - PI / 2));
// 			startY = ((mapY + 1) - data->posY) / Y_angle;
// 			stepY = 1;
// 		}
// 		printf("START %f %f \n", startX, startY);
// 		double deltaX = 1 / X_angle;
// 		double deltaY = 1 / Y_angle;
// 		printf("ANGLES:  %f  %f\n",X_angle, Y_angle);
// 		int hit = 0;
// 		while(hit == 0)
// 		{
// 			if (startX < startY)
// 			{
// 				startX += deltaX;
// 				mapX +=stepX;
// 			}
// 			else
// 			{
// 				startY += deltaY;
// 				mapY +=stepY;
// 			}
// 			if (data->matrix[mapY][mapX] == 1)
// 				hit = 1;
// 			printf("Map X %d map Y %d\n", mapX, mapY);
// 			//hit++;
// 		}
// 		double dist = (startX < startY) ? startX : startY;
// 		printf("Dist %f\n",dist);
// 		int lineHeight = (int)(HEIGHT / dist);

// 		int drawStart = -lineHeight / 2 + HEIGHT / 2;
// 		if(drawStart < 0) drawStart = 0;
// 		int drawEnd = lineHeight / 2 + HEIGHT / 2;
// 		if(drawEnd >= HEIGHT) drawEnd = HEIGHT - 1;

// 		drawVerticalLine(data, x, drawStart, drawEnd, COLOR_BLUE);
// 		mlx_key_hook(data->mlx, (void *)&let_s_move, data);
// 		ray += 60.00/(double)WIDTH* PI / 180;
// 		x++;

// 	}