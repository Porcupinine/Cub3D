#include "includes/cub3d.h"
#include "includes/parsing.h"
#include "lib42/include/libft.h"



void	draw_wall(t_data *data, mlx_t *mlx, int x, int y)
{
	// mlx_texture_t	*texture_wall;
	// mlx_image_t		*img_wall;

	// texture_wall = mlx_load_png("wood.png");
	// if (!texture_wall)
	// 	ft_error("ERR");
	// data->map->img_wall = mlx_texture_to_image(mlx, data->map->wall_png);
	// mlx_resize_image(data->map->img_wall, data->scale_map, data->scale_map);
	// if (!data->map->img_wall)
	// 	ft_error("ERR");
	// data->map->img_wall->instances[0].x = x * data->scale_map;
	// data->map->img_wall->instances[0].y = y * data->scale_map;
	if (mlx_image_to_window(mlx, data->map->img_wall, x * data->scale_map, y * data->scale_map) < 0)
		ft_error("ERR");

}
void	draw_floor(t_data *data, mlx_t *mlx, int x, int y)
{
	// mlx_texture_t	*texture_wall;
	// mlx_image_t		*img_wall;

	// texture_wall = mlx_load_png("wood.png");
	// if (!texture_wall)
	// 	ft_error("ERR");
	// data->map->img_floor = mlx_texture_to_image(mlx, data->map->floor_png);
	// mlx_resize_image(data->map->img_floor, data->scale_map, data->scale_map);
	// if (!data->map->img_floor)
	// 	ft_error("ERR");
	// data->map->img_floor->instances[0].x = x * data->scale_map;
	// data->map->img_floor->instances[0].y = y * data->scale_map;
	// mlx_delete_image(data->mlx, data->map->img_wall);
	if (mlx_image_to_window(mlx, data->map->img_floor, x * data->scale_map, y * data->scale_map) < 0)
		ft_error("ERR");

}


void draw_direction(t_data *data)
{
	double x = data->player->posX + data->scale_map / 2;
	double y = data->player->posY + data->scale_map / 2;
	
    int n = 50;//(fm(data->player->dirX) + fm(data->player->dirY)) * 50;
    double error = fm(data->player->dirX) - fm(data->player->dirY);
	// double x1 = data->player->dirX + data->ray->planeX * camera;
	// double y1 = data->player->dirY + data->ray->planeY * camera;
	// while(x < 10)
	// {
	// 	double camera = 2 * x / 10 - 1;
	// 	findOrientation(data, x, camera);
	// 	if (data->player->orientation == 1)
	// 	{
	// 		x = data->player->posX + data->scale_map / 2;
	// 		y = data->player->posY + data->scale_map / 2;
	// 	}
		while (n > 0)
		{
			if (((int)(data->player->posX * data->scale_map + x)) < 0 || ((int)(data->player->posX * data->scale_map + x)) > data->map_data->map_x * data->scale_map
				|| ((int)(data->player->posY * data->scale_map + y)) < 0 || ((int)(data->player->posY * data->scale_map + y)) > data->map_data->map_y * data->scale_map)
				break;
			mlx_put_pixel(data->img, data->player->posX * data->scale_map + x, data->player->posY * data->scale_map + y, COLOR_RED);
			if (error > 0)
			{
				x += data->player->dirX;
				error -= fm(data->player->dirY);
			}
			else
			{
				y += data->player->dirY;
				error += fm(data->player->dirX);
			}
			n--;
		}
    // }
}


void draw_player(t_data *data)
{
	// mlx_texture_t	*player_pic;
	// mlx_image_t		*img_wall;

	// player_pic = mlx_load_png("play.png");
	// if (!player_pic)
	// 	ft_error("ERR");
	// data->map->img_player = mlx_texture_to_image(data->mlx, data->map->player_png);
	// if (!data->map->img_player)
	// 	ft_error("Minimap images fail");
	// mlx_resize_image(data->map->img_player, data->scale_map, data->scale_map);
	// if (mlx_image_to_window(data->mlx, data->map->img_player, 6 * data->scale_map, 3 * data->scale_map) < 0)
	// 	ft_error("Minimap images fail");
	mlx_texture_to_image(data->mlx, data->map->player_png);
	//draw_direction(data);

}

void draw_map(t_data *data)
{
	//mlx_image_t *comb = mlx_new_image(data->mlx, 100, 100);
	
	int x = 0;
	int y = 0;

	while (y < data->map_data->map_y)
	{
		while (x < data->map_data->map_x)
		{
			
			if (data->map_data->map[y][x] == '1')
			{		
				draw_wall(data, data->mlx, x, y);
			}
			else
				draw_floor(data, data->mlx, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}

void player_pos_map(t_data *data)
{
    int y = 7;
    int x = 13;
	int draw_x = 0;
	int draw_y = 0;
    while (y > 0)
    {
        draw_y = (int)(data->player->posY) + y - 3;
		printf("draw_y %d data->player->posY %f y  %d \n",draw_y, data->player->posY, y);
        if (draw_y < 0 || draw_y >= data->map_data->map_y)
            draw_floor(data, data->mlx, x, y);
        else
        {
            x = 13;
            while (x > 0)
            {
                draw_x = (int)(data->player->posX) + x - 6;
				printf("DRAW Y x %d %d \n", draw_y, draw_x);
                if (draw_x < 0 || draw_x >= data->map_data->map_x)
                    draw_floor(data, data->mlx, x, y);
                else if (data->map_data->map[draw_y][draw_x] == '1')
                    draw_wall(data, data->mlx, x, y);
                else
                    draw_floor(data, data->mlx, x, y);
                
                x--;
            }
        }
        y--;
    }
	draw_player(data);

}

void create_minimap(t_data *data) //Need to make decisions about scale
{
	int x;
	int y;

	x = 0;
	y = 0;
	// while (y < (data->map_data->map_y * data->scale_map))
	// {
	// 	while (x < data->map_data->map_x * data->scale_map) //(x < ((data->width -1)* data->scale_map))
	// 	{
			
	// 		x++;
	// 	}
	// 	x = 0;
	// 	y++;
	// }
	//draw_map(data);
	player_pos_map(data);
	// draw_direction(data);
	//draw_player(data);
	//mlx_key_hook(data->mlx, (void *)&let_s_move, data);
}

