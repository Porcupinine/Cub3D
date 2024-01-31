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

#include "../includes/utils.h"
#include "../includes/checks.h"
#include "../includes/parsing.h"
#include "../includes/cub3d.h"
#include "../lib42/include/libft.h"
#include <stdio.h>

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
	cub_data->map_data = get_data(argv[1]);
	check_map(cub_data);
	check_values(cub_data->map_data);
	print_paths(cub_data->map_data);
	print_colors(cub_data->map_data);
	print_map(cub_data->map_data);
	return (0);
}
