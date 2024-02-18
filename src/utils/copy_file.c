/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   copy_file.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/15 20:55:11 by laura         #+#    #+#                 */
/*   Updated: 2024/02/17 08:35:48 by laura         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../../includes/structs.h"
#include "../../lib42/include/libft.h"
#include "../../lib42/include/get_next_line.h"
#include "../../includes/utils.h"

char	**realloc_data(t_data *cub_data, int *allocated)
{
	int		count;
	char	**new_data;

	count = 0;
	new_data = ft_calloc((*allocated) * 2, sizeof (char *));
	if (new_data == NULL)
		clean_up(cub_data, "Malloc fail\n");
	while (count != *allocated)
	{
		new_data[count] = cub_data->map_data->game_data[count];
		count++;
	}
	*allocated *= 2;
	free(cub_data->map_data->game_data);
	return (new_data);
}

void	copy_data(t_data *data, char *file)
{
	int		fd;
	int		count;
	char	*line;
	int		alloc;

	count = 0;
	alloc = 30;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		clean_up(data, "Fail to read file\n");
	data->map_data->game_data = ft_calloc(alloc, sizeof (char *));
	if (data->map_data->game_data == NULL)
		clean_up(data, "Malloc fail\n");
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (count == alloc)
			data->map_data->game_data = realloc_data(data, &alloc);
		data->map_data->game_data[count] = line;
		count++;
		data->map_data->data_size++;
		line = get_next_line(fd);
	}
	close(fd);
}
