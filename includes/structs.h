/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:25:14 by laura             #+#    #+#             */
/*   Updated: 2024/01/30 11:55:03 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCTS_H
#define CUB3D_STRUCTS_H

#include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_map_data
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	int		floor;
	int		celling;
	char	**map;
	int		map_y; //height
	int		map_x; //still to find
} t_map_data;

typedef struct s_player
{
	char	orientation;
	double	posX;
	double	posY;
	int		mapX;
	int		mapY;
	double	dirX;
	double	dirY;
	mlx_texture_t	*player_png;
} t_player;

typedef struct s_ray
{
	int		stepX;
	int		stepY;
	double	sideX;
	double	sideY;
	double	deltaX;
	double	deltaY;
	double planeX;
	double planeY;
} t_ray;

typedef struct s_data
{
	t_ray		*ray;
	t_map_data	*map_data;
	t_player	*player;
	mlx_t		*mlx;
	mlx_image_t	*img;
	mlx_image_t	*img2; //minimap background
	mlx_image_t		*img_player;
	double		angle;
	int scale_map; //temporarily
} t_data;

#endif // CUB3D_STRUCTS_H
