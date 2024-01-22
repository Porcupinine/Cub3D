/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_textures.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/18 13:48:12 by laura         #+#    #+#                 */
/*   Updated: 2024/01/18 13:48:12 by laura         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"
#include "../../includes/utils.h"
#include "../../lib42/include/libft.h"
#include "../../lib42/include/get_next_line.h"
#include "../../MLX42/include/MLX42/MLX42.h"

#define VAL "/-_"

static char *get_path (char* str)
{
	int count;
	int start;
	char *sub;

	count = 0;
	start = 0;
	while (str[count] != '\0')
	{
		if (str[count] == '.' && str[count + 1] == '/')
		{
			start = count;
			count++;
			while(ft_isalpha(str[count]) != 0 || \
			ft_strrchr(VAL, str[count]) != 0)
				count++;
			sub = ft_substr(str, start, count - start);
		}
		count++;
	}
	return(sub);
}

static int check_rgba(char **rgba_char)
{
	int count;

	count = 0;
	while (rgba_char[count] != NULL)
		count++;
	if (count != 3)
		ft_error("Invalid data\n");
	count = 0;
	while (rgba_char[count] != NULL)
	{
		if(all_digits(rgba_char[count]) == 0)
			ft_error("Invalid data\n");
		count++;
	}
	return(0);
}

static int get_color ( char *str)
{
	int count;
	char **rgba_char;
	int rgba;

	count = 0;
	rgba = 0;
	str[ft_strlen(str) - 1] = '\0';
	while (str[count] != '\0')
	{
		if (ft_isdigit(str[count]) != 0)
		{
			rgba_char = ft_split(str + count, ',');
			break;
		}
		count++;
	}
	check_rgba(rgba_char);
	rgba = get_rgba(ft_atoi(rgba_char[0]), ft_atoi(rgba_char[1]), \
	ft_atoi(rgba_char[2]), 0);
	free(rgba_char);
	return (rgba);
}

int get_textures(char* line, t_parse_data *cub_data)
{
	if (ft_strnstr(line, "NO", ft_strlen(line)) != 0) {
		if (cub_data->no_path != NULL)
			return (1);
		cub_data->no_path = get_path(line);
	}
	else if (ft_strnstr(line, "SO", ft_strlen(line)) != 0) {
		if (cub_data->so_path != NULL)
			return (1);
		cub_data->so_path = get_path(line);
	}
	else if (ft_strnstr(line, "WE", ft_strlen(line)) != 0) {
		if (cub_data->we_path != NULL)
			return (1);
		cub_data->we_path = get_path(line);
	}
	else if (ft_strnstr(line, "EA", ft_strlen(line)) != 0) {
		if (cub_data->ea_path != NULL)
			return (1);
		cub_data->ea_path = get_path(line);
	}
	free(line);
	return (0);
}

int get_fc(char *line, t_parse_data *cub_data)
{
	if (ft_strnstr(line, "F ", ft_strlen(line)) != 0)
	{
		if (cub_data->floor != NULL) //how do I test if it already exists??
			return (1);
		cub_data->floor = get_color(line);
	}
	if (ft_strnstr(line, "C ", ft_strlen(line)) != 0)
	{
		if (cub_data->celling != NULL)
			return (1);
		cub_data->celling = get_color(line);
	}
	return (0);
}
