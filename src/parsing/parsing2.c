/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing2.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/15 21:26:47 by laura         #+#    #+#                 */
/*   Updated: 2024/02/15 21:26:47 by laura         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"
#include "../../includes/utils.h"
#include "../../lib42/include/libft.h"
#include "../../lib42/include/get_next_line.h"
#include <fcntl.h>

static void	check_extension(char *str)
{
	char	*ext;

	ext = ft_strrchr(str, '.');
	if (ext == 0)
		ft_error("Error\nNo extension\n");
	if (ft_memcmp(ext, ".cub", 5))
		ft_error("Error\nWrong extension\n");
}

static int	check_textures(const char *line)
{
	return (ft_strnstr(line, "NO ", ft_strlen(line)) != 0 || \
			ft_strnstr(line, "SO ", ft_strlen(line)) != 0 || \
			ft_strnstr(line, "WE ", ft_strlen(line)) != 0 || \
			ft_strnstr(line, "EA ", ft_strlen(line)) != 0);
}

static int	check_floor_celing(const char *line)
{
	return (ft_strnstr(line, "F ", ft_strlen(line)) != 0 || \
			ft_strnstr(line, "C ", ft_strlen(line)) != 0);
}

static void	parse_data(t_map_data *map_data)
{
	int	count;

	count = 0;
	while (count <= map_data->data_size)
	{
		if (first_map_line(map_data->game_data[count]) == 1 && \
		test_isspace(map_data->game_data[count]) != 1)
		{
			get_map2(map_data);
			break ;
		}
		else if (check_textures(map_data->game_data[count]))
		{
			get_textures(map_data->game_data[count], map_data);
		}
		else if (check_floor_celing(map_data->game_data[count]))
		{
			get_fc(map_data->game_data[count], map_data);
		}
		else if (test_isspace(map_data->game_data[count]) != 1)
			ft_error("Invalid data! Trash line \n");
	}
}


void	get_data2(t_data *cub_data, char *file)
{
	cub_data->map_data = ft_calloc(1, sizeof(t_map_data));
	if (cub_data->map_data == NULL)
		ft_error("Malloc fail\n");
	check_extension(file);
	copy_data(cub_data->map_data, file);
	print_data(cub_data->map_data);
	parse_data(cub_data->map_data);
}