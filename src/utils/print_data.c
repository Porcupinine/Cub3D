/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:09:53 by laura             #+#    #+#             */
/*   Updated: 2024/02/19 13:11:42 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib42/include/libft.h"
#include "../../includes/parsing.h"
#include "../../includes/utils.h"
#include <stdio.h>

void	print_paths(t_map_data *map_data)
{
	printf("NO: %s\nSO: %s\nWE: %s\nEA: %s\n", \
	map_data->no_path, map_data->ea_path, map_data->we_path, \
	map_data->ea_path);
}

void	print_colors(t_map_data *map_data)
{
	printf("F: %d.%d,%d\nC: %d,%d,%d\n", get_r(map_data->floor), \
	get_g(map_data->floor), get_b(map_data->floor), get_r(map_data->celling), \
	get_g(map_data->celling), get_b(map_data->celling));
}

void	print_map(t_map_data *map_data)
{
	int	y;

	y = 0;
	while (y < map_data->map_y)
	{
		printf("%s", map_data->map[y]);
		y++;
	}
	printf("\n\n");
}

void	print_data(t_map_data *map_data)
{
	int	count;

	count = 0;
	while (count <= map_data->data_size)
	{
		printf("%s", map_data->game_data[count]);
		count++;
	}
}
