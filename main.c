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
#include <stdio.h>

int main (int argc, char **argv) {
	if (argc != 2)
	{
		printf("wrong amount of args!\n");
		return (1);
	}
	t_parse_data *cub_data;
	cub_data = get_data(argv[1]);
	print_paths(cub_data);
	print_colors(cub_data);
	print_map(cub_data);
}