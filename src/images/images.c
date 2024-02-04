#include "../../includes/cub3d.h"
#include "../../includes/parsing.h"
#include "../../lib42/include/libft.h"

void	init_map_images(t_data *data)
{
	data->map = malloc(sizeof(t_minimap));
	if (!data->map)
		ft_error("Malloc fail\n");
	data->map->wall_png = mlx_load_png("textures/delete/wood.png");
	data->map->player_png = mlx_load_png("textures/delete/fly.png");
	data->map->floor_png = mlx_load_png("textures/delete/floor.png");
	if (!data->map->wall_png || !data->map->player_png || !data->map->floor_png)
		ft_error("Downloading png fail\n");
	data->map->img_floor = mlx_texture_to_image(data->mlx, data->map->floor_png);
	data->map->img_wall = mlx_texture_to_image(data->mlx, data->map->wall_png);
	data->map->img_player = mlx_texture_to_image(data->mlx, data->map->player_png);
	if (!data->map->img_floor || !data->map->img_wall || !data->map->img_player)
		ft_error("Minimap images fail");
	mlx_resize_image(data->map->img_floor, data->scale_map, data->scale_map);
	mlx_resize_image(data->map->img_wall, data->scale_map, data->scale_map);
	mlx_resize_image(data->map->img_player, data->scale_map, data->scale_map);
	if (mlx_image_to_window(data->mlx, data->map->img_player, 6 * data->scale_map, 3 * data->scale_map) < 0)
		ft_error("Minimap images to window fail");
}

void	init_image(t_data *data)
{
	if (WIDTH < HEIGHT) // show minimap omly if data->scale_map > 5
		data->scale_map = WIDTH / 50;
	else
		data->scale_map = HEIGHT / 50;
	data->mlx = mlx_init(WIDTH, HEIGHT, "CUB", true);
	if (!data->mlx)
		ft_error("MLX initialization fail\n");
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (mlx_image_to_window(data->mlx, data->img, 0, 0) < 0)
		ft_error("Drawing image fail\n");
	initRaycast(data);
}