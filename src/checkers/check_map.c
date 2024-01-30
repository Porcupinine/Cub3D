/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 09:59:25 by laura             #+#    #+#             */
/*   Updated: 2024/01/30 12:20:53 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"
#include "../../includes/cub3d.h"
#include "../../lib42/include/libft.h"
#include <stdio.h>
#include <math.h>

static void check_around(char **map, int x, int y, char *str)
{
	if(ft_strchr(str, map[x][y - 1]) == 0 || \
	ft_strchr(str, map[x][y + 1]) == 0 || \
	ft_strchr(str, map[x - 1][y]) == 0 || \
	ft_strchr(str, map[x + 1][y]) == 0)
		ft_error("Invalid map\n");
}

static void check_topbot(char **map, int x) {
	int y;

	y = 0;
	while (map[0][y] != '\n' && map[0][y] != '\0') {
		if (ft_strrchr("0WENS", map[0][y]) != 0)
			ft_error("Invalid map\n");
		y++;
	}
	y = 0;
	while (map[x - 1][y] != '\n' && map[x - 1][y] != '\0') {
		if (ft_strrchr("0WENS", map[x - 1][y]) != 0)
			ft_error("Invalid map\n");
		y++;
	}
}
void	find_direction(t_data *cub_data, char dir)
{
	if (dir == 'N' || dir == 'S')
		cub_data->player->dirX = 0;
	if (dir == 'E' || dir == 'W')
		cub_data->player->dirY  = 0;
	if (dir == 'E')
		cub_data->player->dirX  = 1;
	if (dir == 'W')
		cub_data->player->dirX = -1;
	if (dir == 'N')
		cub_data->player->dirY = -1;
	if (dir == 'S')
		cub_data->player->dirY = 1;
	// data->plane_X = 0;
	// data->plane_Y = 0.66; //angle FOV
	cub_data->angle = atan2(cub_data->player->dirY, cub_data->player->dirX);
	if (cub_data->angle < 0)
		cub_data->angle += (2 * PI);
	if (cub_data->angle > (2 * PI))
		cub_data->angle -= (2 * PI);
	// printf("ANGLE %f and dir %f %f for %d\n", data->angle, data->dirX, data->dirY, data->matrix[y][x]);
}

static void found_player(t_data *cub_data, int x, int y)
{
	check_around(cub_data->map_data->map, x, y, "01");
	if(cub_data->player != NULL)
		ft_error("Multiple players\n");
	cub_data->player = ft_calloc(1, sizeof (t_player));
	if (cub_data->player == NULL)
		ft_error("Malloc fail\n");
	cub_data->player->posY = (double)x;
	cub_data->player->posX = (double)y;
	//cub_data->player->orientation = cub_data->map_data->map[x][y];
	find_direction(cub_data, cub_data->map_data->map[x][y]);
}

void check_map(t_data *cub_data)
{
	int x;
	int y;

	x = 1;
	check_topbot(cub_data->map_data->map, cub_data->map_data->map_y);
	while (x < cub_data->map_data->map_y)
	{
		y = 0;
		while (cub_data->map_data->map[x][y] != '\n' && cub_data->map_data->map[x][y] != '\0')
		{
			if (cub_data->map_data->map[x][y] == '0')
				check_around(cub_data->map_data->map, x, y, "01WENS");
			if(ft_strrchr("WENS", cub_data->map_data->map[x][y]) != 0)
				found_player(cub_data, x, y);
			y++;
		}
		x++;
	}
	if (cub_data->player == NULL)
		ft_error("Invalid map!\n");
}