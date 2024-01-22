/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/18 13:48:52 by laura         #+#    #+#                 */
/*   Updated: 2024/01/18 13:48:52 by laura         ########   odam.nl         */
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

int parse_data(int fd, char *file, t_parse_data *cub_data)
{
	char *line;

	while ((line = get_next_line(fd)))
	{
		if(first_map_line(line) == 1 && test_isspace(line) != 1)
		{
			close(fd);
			get_map(file, cub_data);
			break;
		}
		else if (ft_strnstr(line, "NO ", ft_strlen(line)) != 0 ||
		ft_strnstr(line, "SO ", ft_strlen(line)) != 0 ||
		ft_strnstr(line, "WE ", ft_strlen(line)) != 0 ||
		ft_strnstr(line, "EA ", ft_strlen(line)) != 0)
			if (get_textures(line, cub_data) == 1)
				return (1);
		else if (ft_strnstr(line, "F ", ft_strlen(line)) != 0 ||
		ft_strnstr(line, "C ", ft_strlen(line)) != 0)
			if(get_fc(line, cub_data) == 1)
				return (1);
		else if (test_isspace(line) == 1)
			;
	}
	return (0);
}

t_parse_data *get_data(char *file)
{
	int fd;
	void *cub_data;

	fd = 0;
	cub_data = ft_calloc(1, sizeof(t_parse_data));
	if (cub_data == NULL)
		ft_error("Malloc fail\n");
	check_extension(file);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error("Fail to read file\n");
	parse_data(fd, file, cub_data);
	return (cub_data);
}