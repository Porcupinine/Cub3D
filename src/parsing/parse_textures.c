/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_textures2.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/15 21:34:30 by laura         #+#    #+#                 */
/*   Updated: 2024/02/15 21:34:30 by laura         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"
#include "../../includes/utils.h"
#include "../../lib42/include/libft.h"
#include "../../lib42/include/get_next_line.h"
#include "../../MLX42/include/MLX42/MLX42.h"

#define VAL "/-_"

static char	*get_path(char *str)
{
	int		count;
	int		start;
	char	*sub;

	count = 0;
	start = 0;
	while (str[count] != '\0')
	{
		if (str[count] == '.' && str[count + 1] == '/')
		{
			start = count + 2;
			count++;
			while (ft_isalnum(str[count]) != 0 || \
			ft_strrchr(VAL, str[count]) != 0)
				count++;
			sub = ft_substr(str, start, (count + 4) - start);
		}
		count++;
	}
	return (sub);
}

static int	check_rgba(char **rgba_char)
{
	int	count;

	count = 0;
	while (rgba_char[count] != NULL)
		count++;
	if (count != 3)
		return (1);
	count = 0;
	while (rgba_char[count] != NULL)
	{
		if (all_digits(rgba_char[count]) == 0)
			return (1);
		if (ft_strlen(rgba_char[count]) == 3 && \
		ft_strncmp(rgba_char[count], "255", 3) > 0 || ft_strlen(rgba_char[count]) > 3)
		{
			printf("nb: %s\n", rgba_char[count]);
			return (1);
		}
		if (ft_strncmp(rgba_char[count], "0", 1) < 0)
			return (1);
		count++;
	}
	return (0);
}

static int	get_color(t_data *cub_data, char *str)
{
	int		count;
	char	**rgba_char;
	int		rgba;

	count = 0;
	rgba_char = NULL;
	str[ft_strlen(str) - 1] = '\0';
	while (str[count] != '\0')
	{
		if (ft_isdigit(str[count]) != 0)
		{
			rgba_char = ft_split(str + count, ',');
			if (rgba_char == NULL)
				clean_up(cub_data, "Fail to get colors!\n");
			break ;
		}
		count++;
	}
	if (check_rgba(rgba_char) == 1)
		clean_up(cub_data, "Invalid data!\n");
	rgba = get_rgba(ft_atoi(rgba_char[0]), ft_atoi(rgba_char[1]), \
	ft_atoi(rgba_char[2]), 255);
	free_split(rgba_char);
	return (rgba);
}

void	get_textures(char *line, t_data *cub_data)
{
	if (ft_strnstr(line, "NO", ft_strlen(line)) != 0)
	{
		if (cub_data->map_data->no_path != NULL)
			clean_up(cub_data, "Invalid map! Multiple textures\n");
		cub_data->map_data->no_path = get_path(line);
	}
	else if (ft_strnstr(line, "SO", ft_strlen(line)) != 0)
	{
		if (cub_data->map_data->so_path != NULL)
			clean_up(cub_data, "Invalid map! Multiple textures\n");
		cub_data->map_data->so_path = get_path(line);
	}
	else if (ft_strnstr(line, "WE", ft_strlen(line)) != 0)
	{
		if (cub_data->map_data->we_path != NULL)
			clean_up(cub_data, "Invalid map! Multiple textures\n");
		cub_data->map_data->we_path = get_path(line);
	}
	else if (ft_strnstr(line, "EA", ft_strlen(line)) != 0)
	{
		if (cub_data->map_data->ea_path != NULL)
			clean_up(cub_data, "Invalid map! Multiple textures\n");
		cub_data->map_data->ea_path = get_path(line);
	}
}

void	get_fc(char *line, t_data *cub_data)
{
	if (ft_strnstr(line, "F ", ft_strlen(line)) != 0)
	{
		if (cub_data->map_data->floor != 0)
			clean_up(cub_data, "Invalid map! Multiple colors\n");
		cub_data->map_data->floor = get_color(cub_data, line);
	}
	if (ft_strnstr(line, "C ", ft_strlen(line)) != 0)
	{
		if (cub_data->map_data->celling != 0)
			clean_up(cub_data, "Invalid map! Multiple colors\n");
		cub_data->map_data->celling = get_color(cub_data, line);
	}
}
