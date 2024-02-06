/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_data.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lpraca-l <lpraca-l@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/29 14:57:43 by lpraca-l      #+#    #+#                 */
/*   Updated: 2024/01/29 14:57:43 by lpraca-l      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"
#include "../../lib42/include/libft.h"
#include "../../includes/graphics.h"

void check_values(t_data *cub_data)
{
	if(cub_data->map_data->no_path == NULL || cub_data->map_data->so_path == NULL || \
	cub_data->map_data->we_path == NULL || cub_data->map_data->ea_path == NULL)
		ft_error("Invalid map. Missing information\n");
	load_textures(cub_data);
}