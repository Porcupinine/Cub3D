/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:50:46 by laura             #+#    #+#             */
/*   Updated: 2024/01/25 16:46:55 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"
#include "../../includes/utils.h"
#include "../../lib42/include/libft.h"
#include "../../lib42/include/get_next_line.h"
#include <fcntl.h>

static void map_x_size(t_map_data *cub_data) 
{
    int y;
    int len;

    y = 0;
    len = 0;
    while(cub_data->map_y > y) {
       if ((int)ft_strlen(cub_data->map[y]) > len)
          len = (int)ft_strlen(cub_data->map[y]);
       y++;
    }
    cub_data->map_x = len;
}

static int	map_y_size(char *file)
{
	int		count;
	char	*line;
	int		fd;

	count = 0;
	fd = open(file, O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		if (first_map_line(line) == 1 && test_isspace(line) != 1)
		{
			count++;
			free(line);
			break;
		}
		free(line);
	}
	while ((line = get_next_line(fd)))
	{
		count++;
		free(line);
	}
	close(fd);
	return (count);
}

static void copy_map(char *file, t_map_data *cub_data)
{
	int		count;
	char	*line;
	int		fd;

	count = 0;
	fd = open(file, O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		if (first_map_line(line) == 1 && test_isspace(line) != 1)
		{
			cub_data->map[count] = line;
			count++;
			break;
		}
		free(line);
	}
	while ((line = get_next_line(fd)))
	{
		cub_data->map[count] = line;
		count++;
	}
}

void get_map(char *file, t_map_data *cub_data)
{
	int		fd;

	cub_data->map_y = map_y_size(file);
	cub_data->map = malloc(cub_data->map_y* sizeof(char *));
	if (cub_data->map == NULL)
		ft_error("Malloc fail\n");
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error("Fail to read file\n");
	copy_map(file, cub_data);
	close(fd);
	map_x_size(cub_data);
}