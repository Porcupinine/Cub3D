/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 21:26:47 by laura             #+#    #+#             */
/*   Updated: 2024/02/19 13:10:12 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"
#include "../../includes/utils.h"
#include "../../lib42/include/libft.h"

static int	check_extension(char *str)
{
	char	*ext;

	ext = ft_strrchr(str, '.');
	if (ext == 0)
		return (1);
	if (ft_memcmp(ext, ".cub", 5))
		return (1);
	return (0);
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

static void	parse_data(t_data *cub_data)
{
	int	count;

	count = 0;
	while (count <= cub_data->map_data->data_size)
	{
		if (first_map_line(cub_data->map_data->game_data[count]) == 1 && \
		test_isspace(cub_data->map_data->game_data[count]) != 1)
		{
			get_map(cub_data);
			break ;
		}
		else if (check_textures(cub_data->map_data->game_data[count]))
			get_textures(cub_data->map_data->game_data[count], \
			cub_data);
		else if (check_floor_celing(cub_data->map_data->game_data[count]))
			get_fc(cub_data->map_data->game_data[count], cub_data);
		else if (test_isspace(cub_data->map_data->game_data[count]) != 1)
			clean_up(cub_data, "Invalid data! Trash line \n");
		count++;
	}
}

void	get_data(t_data *cub_data, char *file)
{
	cub_data->map_data = ft_calloc(1, sizeof(t_map_data));
	if (cub_data->map_data == NULL)
		clean_up(cub_data, "Malloc fail\n");
	if (check_extension(file) == 1)
		clean_up(cub_data, "Error with extension\n");
	copy_data(cub_data, file);
	parse_data(cub_data);
}
