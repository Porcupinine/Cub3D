/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/15 15:50:50 by laura         #+#    #+#                 */
/*   Updated: 2024/02/15 15:50:50 by laura         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/structs.h"
#include <stdlib.h>

static void	free_map(t_map_data *map_data)
{
	int	x;

	x = 0;
	while(x < map_data->map_y)
	{
		free(map_data->map[x]);
		x++;
	}
	free(map_data->map);
}

void	free_cub(t_data *cub_data)
{
	free(cub_data->walls);
	free(cub_data->player);
	free_map(cub_data->map_data);
	free(cub_data->map_data);
	free(cub_data);

}