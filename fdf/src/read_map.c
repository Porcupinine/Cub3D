/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:54:45 by akrepkov          #+#    #+#             */
/*   Updated: 2023/06/02 19:00:20 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/libft/libft.h"
#include "fdf.h"

void	ft_perror(char *str)
{
	perror(str);
	exit(0);
}

int	get_height(char *file)
{
	int		fd;
	int		height;
	char	*line;

	height = 0;
	fd = open(file, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

char	*extra_check(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len > 0 && str[len - 1] == '\n')
		str[len - 1] = '\0';
	return (str);
}

int	*map_to_int(t_fdf *data, char *str)
{
	int		i;
	char	**nums;
	int		*res;

	i = 0;
	str = extra_check(str);
	nums = ft_split(str, ' ');
	while (nums[i] != '\0')
		i++;
	res = malloc(sizeof(int) * i);
	i = 0;
	while (nums[i])
	{
		res[i] = ft_atoi(nums[i]);
		check_the_z(data, res[i]);
		free(nums[i]);
		i++;
	}
	if (data->width != 0 && data->width != i)
		ft_perror("The map is wrong");
	data->width = i;
	free(nums);
	return (res);
}

int	read_map(char *file, t_fdf *data)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	data->height = get_height(file);
	data->matrix = malloc (sizeof(int *) * (data->height) + 1);
	if (!data->matrix)
		return (-1);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		data->matrix[i] = map_to_int(data, line);
		i++;
		free(line);
	}
	data->matrix[i] = NULL;
	close(fd);
	return (0);
}
