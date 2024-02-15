/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   copy_file.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/15 20:55:11 by laura         #+#    #+#                 */
/*   Updated: 2024/02/15 20:55:11 by laura         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../../includes/structs.h"
#include "../../lib42/include/libft.h"
#include "../../lib42/include/get_next_line.h"

char	**relloc_data(char** data, int allocated)
{
	int		count;
	char	**new_data;

	count = 0;
	new_data = ft_calloc(allocated * 2, sizeof (char *));
	if(new_data == NULL)
		ft_error("Malloc fail\n");
	while(count != allocated)
	{
		new_data[count] = data[count];
		count++;
	}
	free(data);
	return (new_data);
}

void	copy_data(t_map_data *map_data, char *file)
{
	int		fd;
	int		count;
	char	*line;
	int		allocated;

	count = 0;
	allocated = 30;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error("Fail to read file\n");
	map_data->game_data = ft_calloc(allocated, sizeof (char *));
	if (map_data->game_data == NULL)
		ft_error("Malloc fail\n");
	while((line = get_next_line(fd)))
	{
		if (count == allocated)
		{
			map_data->game_data = relloc_data(map_data->game_data, allocated);
			allocated = 2*allocated;
		}
		map_data->game_data[count] = line;
		count++;
		map_data->data_size++;
	}
	close(fd);
}