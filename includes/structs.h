/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structs.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/22 12:25:14 by laura         #+#    #+#                 */
/*   Updated: 2024/01/22 12:25:14 by laura         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCTS_H
#define CUB3D_STRUCTS_H

#include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_map_data {
	char				*no_path;
	char				*so_path;
	char				*we_path;
	char				*ea_path;
	int					floor;
	int 				celling;
	char				**map;
	int					map_y;
	int					map_x;
}t_map_data;

typedef struct s_player {
	char	orientation;
	int		x;
	int		y;
}t_player;

typedef struct s_data {
	t_map_data	*map_data;
	mlx_t 		*mlx;
	t_player	*player;
}t_data;

#endif //CUB3D_STRUCTS_H
