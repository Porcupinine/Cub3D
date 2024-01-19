/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_data.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/19 11:09:53 by laura         #+#    #+#                 */
/*   Updated: 2024/01/19 11:09:53 by laura         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib42/include/libft.h"
#include "../../includes/parsing.h"
#include <stdio.h>

void print_paths(t_parse_data *cub_data)
{
	printf("NO: %s\nSO: %s\nWE: %s\nEA: %s\nF: %d\nC: %d\n", \
	cub_data->no_path, cub_data->ea_path, cub_data->we_path, \
	cub_data->ea_path, *cub_data->floor, *cub_data->celling);
}

void print_map(t_parse_data *cub_data)
{

}