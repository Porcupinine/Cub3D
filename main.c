/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/19 11:05:45 by laura         #+#    #+#                 */
/*   Updated: 2024/01/19 11:05:45 by laura         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/parsing.h"
#include "includes/utils.h"
#include "includes/checks.h"
#include "libft.h"
#include <stdio.h>

int main (int argc, char **argv) {
	if (argc != 2)
	{
		printf("wrong amount of args!\n");
		return (1);
	}
	t_data *cub_data;
	cub_data = ft_calloc(1, sizeof (t_data));
	if (cub_data == NULL)
		ft_error("Malloc fail\n");
	cub_data->map_data = get_data(argv[1]);
	print_paths(cub_data->map_data);
	print_colors(cub_data->map_data);
	print_map(cub_data->map_data);
	check_map(cub_data);
	return (0);
}