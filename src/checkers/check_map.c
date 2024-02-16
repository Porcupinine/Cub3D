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

static void	check_around(char **map, int x, int y, char *str)
{
	if (ft_strchr(str, map[x][y - 1]) == 0 || \
	ft_strchr(str, map[x][y + 1]) == 0 || \
	ft_strchr(str, map[x - 1][y]) == 0 || \
	ft_strchr(str, map[x + 1][y]) == 0)
		ft_error("Invalid map. Not surrounded\n");
}

static void	check_topbot(char **map, int x)
{
	int	y;

	y = 0;
	while (map[0][y] != '\n' && map[0][y] != '\0')
	{
		if (ft_strrchr("0WENS", map[0][y]) != 0)
			ft_error("Invalid map. Invalid char\n");
		y++;
	}
	y = 0;
	while (map[x - 1][y] != '\n' && map[x - 1][y] != '\0')
	{
		if (ft_strrchr("0WENS", map[x - 1][y]) != 0)
			ft_error("Invalid map. Invalid char\n");
		y++;
	}
}

static void	found_player(t_data *cub_data, int x, int y)
{
	check_around(cub_data->map_data->map, x, y, "01");
	if (cub_data->player != NULL)
		ft_error("Multiple players\n");
	cub_data->player = ft_calloc(1, sizeof (t_player));
	if (cub_data->player == NULL)
		ft_error("Malloc fail\n");
	cub_data->player->posY = (double)x + 0.5;
	cub_data->player->posX = (double)y + 0.5;
	find_direction(cub_data, cub_data->map_data->map[x][y]);
}

static void	search_for_empty_line(char **map, int limit)
{
	int	count;

	count = 0;
	while (count < limit)
	{
		if (test_isspace(map[count]) == 1)
		{
			ft_error("Invalid map! Empty lines\n");
		}
		count++;
	}
}

void	check_map(t_data *cub_data)
{
	int	x;
	int	y;

	x = 1;
	check_topbot(cub_data->map_data->map, cub_data->map_data->map_y);
	while (x < cub_data->map_data->map_y)
	{
		y = 0;
		while (cub_data->map_data->map[x][y] != '\n' \
		&& cub_data->map_data->map[x][y] != '\0')
		{
			if (cub_data->map_data->map[x][y] == '0')
				check_around(cub_data->map_data->map, x, y, "01WENS");
			if (ft_strrchr("WENS", cub_data->map_data->map[x][y]) != 0)
				found_player(cub_data, x, y);
			y++;
		}
		x++;
	}
	search_for_empty_line(cub_data->map_data->map, cub_data->map_data->map_y);
	if (cub_data->player == NULL)
		ft_error("Invalid map! No player\n");
}
