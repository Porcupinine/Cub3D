/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_data.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/19 11:09:53 by laura         #+#    #+#                 */
/*   Updated: 2024/01/26 11:47:18 by laura         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib42/include/libft.h"
#include "../../includes/parsing.h"
#include "../../includes/utils.h"
#include <stdio.h>

void	print_paths(t_map_data *cub_data)
{
	printf("NO: %s\nSO: %s\nWE: %s\nEA: %s\nF: %d\nC: %d\n", \
	cub_data->no_path, cub_data->ea_path, cub_data->we_path, \
	cub_data->ea_path, cub_data->floor, cub_data->celling);
}

void	print_colors(t_map_data *cub_data)
{
	printf("F: %d.%d,%d\nC: %d,%d,%d\n", get_r(cub_data->floor), \
	get_g(cub_data->floor), get_b(cub_data->floor), get_r(cub_data->celling), \
	get_g(cub_data->celling), get_b(cub_data->celling));
}

void	print_map(t_map_data *cub_data)
{
	int	y;

	y = 0;
	while (cub_data->map[y] != NULL)
	{
		printf("%s", cub_data->map[y]);
		y++;
	}
	printf("\n\n");
}
