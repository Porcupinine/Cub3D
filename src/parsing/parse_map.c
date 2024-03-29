/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 21:37:48 by laura             #+#    #+#             */
/*   Updated: 2024/02/19 13:09:07 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"
#include "../../includes/utils.h"
#include "../../lib42/include/libft.h"
#include "../../lib42/include/get_next_line.h"
#include <fcntl.h>

static void	map_x_size(t_map_data *cub_data)
{
	int	y;
	int	len;

	y = 0;
	len = 0;
	while (cub_data->map_y > y)
	{
		if ((int)ft_strlen(cub_data->map[y]) > len)
			len = (int)ft_strlen(cub_data->map[y]);
		y++;
	}
	cub_data->map_x = len;
}

static void	map_y_size(t_map_data *map_data)
{
	int		count;
	int		y_size;

	count = 0;
	y_size = 0;
	while (count <= map_data->data_size)
	{
		if (first_map_line(map_data->game_data[count]) == 1 && \
		test_isspace(map_data->game_data[count]) != 1)
		{
			while (count < map_data->data_size)
			{
				y_size++;
				count++;
			}
		}
		count++;
	}
	map_data->map_y = y_size;
}

static void	copy_map(t_map_data *map_data)
{
	int	count;
	int	count_copy;

	count_copy = 0;
	count = map_data->data_size - map_data->map_y;
	while (count <= map_data->data_size)
	{
		if (first_map_line(map_data->game_data[count]) == 1 && \
		test_isspace(map_data->game_data[count]) != 1)
		{
			while (count < map_data->data_size)
			{
				map_data->map[count_copy] = map_data->game_data[count];
				count++;
				count_copy++;
			}
		}
		count++;
	}
}

void	get_map(t_data *cub_data)
{
	map_y_size(cub_data->map_data);
	cub_data->map_data->map = malloc(cub_data->map_data->map_y * \
		sizeof(char *));
	if (cub_data->map_data->map == NULL)
		clean_up(cub_data, "Malloc fail\n");
	copy_map(cub_data->map_data);
	map_x_size(cub_data->map_data);
}
