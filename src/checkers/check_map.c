/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 11:56:05 by laura         #+#    #+#                 */
/*   Updated: 2024/02/02 11:56:05 by laura         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"
#include "../../includes/utils.h"
#include "../../includes/cub3d.h"
#include "../../includes/checks.h"
#include "../../lib42/include/libft.h"

static void	check_around(t_data *cub_data, int x, int y, char *str)
{
	if (ft_strchr(str, cub_data->map_data->map[x][y - 1]) == 0 || \
	ft_strchr(str, cub_data->map_data->map[x][y + 1]) == 0 || \
	ft_strchr(str, cub_data->map_data->map[x - 1][y]) == 0 || \
	ft_strchr(str, cub_data->map_data->map[x + 1][y]) == 0)
		clean_up(cub_data, "Invalid map. Not surrounded\n");
}

static void	check_topbot(t_data *cub_data, int x)
{
	int	y;

	y = 0;
	while (cub_data->map_data->map[0][y] != '\n' && \
	cub_data->map_data->map[0][y] != '\0')
	{
		if (ft_strrchr("0WENS", cub_data->map_data->map[0][y]) != 0)
			clean_up(cub_data, "Invalid map. Invalid char\n");
		y++;
	}
	y = 0;
	while (cub_data->map_data->map[x - 1][y] != '\n' && \
	cub_data->map_data->map[x - 1][y] != '\0')
	{
		if (ft_strrchr("0WENS", cub_data->map_data->map[x - 1][y]) != 0)
			clean_up(cub_data, "Invalid map. Invalid char\n");
		y++;
	}
}

static void	found_player(t_data *cub_data, int x, int y)
{
	check_around(cub_data, x, y, "01");
	if (cub_data->player != NULL)
		clean_up(cub_data, "Multiple players\n");
	cub_data->player = ft_calloc(1, sizeof (t_player));
	if (cub_data->player == NULL)
		clean_up(cub_data, "Malloc fail\n");
	cub_data->player->posy = (double)x + 0.5;
	cub_data->player->posx = (double)y + 0.5;
	find_direction(cub_data, cub_data->map_data->map[x][y]);
}

static void	search_for_empty_line(t_data *cub_data, int limit)
{
	int	count;

	count = 0;
	while (count < limit)
	{
		if (test_isspace(cub_data->map_data->map[count]) == 1)
		{
			clean_up(cub_data, "Invalid map! Empty lines\n");
		}
		count++;
	}
}

void	check_map(t_data *cub_data)
{
	int	x;
	int	y;

	x = 1;
	check_topbot(cub_data, cub_data->map_data->map_y);
	while (x < cub_data->map_data->map_y)
	{
		y = 0;
		while (cub_data->map_data->map[x][y] != '\n' \
		&& cub_data->map_data->map[x][y] != '\0')
		{
			if (cub_data->map_data->map[x][y] == '0')
				check_around(cub_data, x, y, "01WENS");
			if (ft_strrchr("WENS", cub_data->map_data->map[x][y]) != 0)
				found_player(cub_data, x, y);
			y++;
		}
		x++;
	}
	search_for_empty_line(cub_data, cub_data->map_data->map_y);
	if (cub_data->player == NULL)
		clean_up(cub_data, "Invalid map! No player\n");
}
