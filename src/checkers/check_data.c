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

void check_values(t_map_data *map_data)
{
	if(map_data->no_path == NULL || map_data->so_path == NULL || \
	map_data->we_path == NULL || map_data->ea_path == NULL)
	ft_error("Invalid map. Missing information\n");
}