/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:05:45 by laura             #+#    #+#             */
/*   Updated: 2024/01/25 17:09:31 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/utils.h"
#include "includes/checks.h"
#include "includes/parsing.h"
#include "includes/cub3d.h"
#include "lib42/include/libft.h"
#include <stdio.h>

void testing(t_data *data)
{

}

int main (int argc, char **argv) 
{
	if (argc != 2)
	{
		printf("wrong amount of args!\n");
		return (1);
	}
	t_data *cub_data;
	cub_data = ft_calloc(1, sizeof (t_data));
	if (cub_data == NULL)
		ft_error("Malloc fail\n");
	cub_data->scale_map = 50; //temp
	cub_data->map_data->map_x = 50; //temp
	cub_data->map_data = get_data(argv[1]);
	// print_colors(cub_data->map_data);
	// print_map(cub_data->map_data);
	check_map(cub_data);
	cub_data->mlx = mlx_init(WIDTH, HEIGHT, "CUB", NULL);
	if (!cub_data->mlx)
		exit(1);
	cub_data->img = mlx_new_image(cub_data->mlx, WIDTH, HEIGHT);
	if (!cub_data->img)
		exit(1);
	if (mlx_image_to_window(cub_data->mlx, cub_data->img, 0, 0) < 0)
		exit(1);
	cub_data->img2 = mlx_new_image(cub_data->mlx, WIDTH, HEIGHT); //for minimap
	if (!cub_data->img2 || (mlx_image_to_window(cub_data->mlx, cub_data->img2, 0, 0) < 0))
		return (-1);
	testing(cub_data);
	minimap_background(cub_data);
	mlx_loop(cub_data->mlx);
	mlx_terminate(cub_data->mlx);
	return (0);
}
