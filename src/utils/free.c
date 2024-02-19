/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:50:50 by laura             #+#    #+#             */
/*   Updated: 2024/02/19 13:11:24 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/structs.h"
#include <stdlib.h>

static void	free_map(t_map_data *map_data)
{
	int	x;

	x = 0;
	while (x < map_data->map_y)
	{
		free(map_data->map[x]);
		x++;
	}
	free(map_data->map);
}

void	free_game_data(t_map_data *map_data)
{
	int	x;

	x = 0;
	while (x < map_data->data_size)
	{
		free(map_data->game_data[x]);
		x++;
	}
	free(map_data->game_data);
}

void	free_if_not_null(void *mem)
{
	if (mem != NULL)
		free(mem);
}

void	free_cub(t_data *cub_data)
{
	free_game_data(cub_data->map_data);
	free_if_not_null(cub_data->map_data->so_path);
	free_if_not_null(cub_data->map_data->ea_path);
	free_if_not_null(cub_data->map_data->we_path);
	free_if_not_null(cub_data->map_data->no_path);
	free_if_not_null(cub_data->map_data->map);
	free_if_not_null(cub_data->walls);
	free_if_not_null(cub_data->player);
	free_if_not_null(cub_data->map_data);
	free_if_not_null(cub_data->map);
	free_if_not_null(cub_data->ray);
	free(cub_data);
}

void	free_split(char **array)
{
	int	x;

	x = 0;
	while (array[x] != NULL)
	{
		free(array[x]);
		x++;
	}
	free(array);
}
