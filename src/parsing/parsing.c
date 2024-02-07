/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:48:52 by laura             #+#    #+#             */
/*   Updated: 2024/02/06 15:05:36 by akrepkov         ###   ########.fr       */
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

static void	parse_data(int fd, char *file, t_map_data *cub_data)
{
	char	*line;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (first_map_line(line) == 1 && test_isspace(line) != 1)
		{
			close(fd);
			get_map(file, cub_data);
			break ;
		}
		else if (check_textures(line))
		{
			get_textures(line, cub_data);
		}
		else if (check_floor_celing(line))
		{
			get_fc(line, cub_data);
		}
		else if (test_isspace(line) != 1)
			ft_error("Invalid data! Trash line \n");
		line = get_next_line(fd);
	}
	free(line);
}

void	get_data(t_data *cub_data, char *file)
{
	int		fd;

	cub_data->map_data = ft_calloc(1, sizeof(t_map_data));
	if (cub_data->map_data == NULL)
		ft_error("Malloc fail\n");
	check_extension(file);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error("Fail to read file\n");
	parse_data(fd, file, cub_data->map_data);
}
