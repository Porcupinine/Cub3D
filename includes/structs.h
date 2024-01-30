/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:25:14 by laura             #+#    #+#             */
/*   Updated: 2024/01/25 16:24:00 by akrepkov         ###   ########.fr       */
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
}	t_map_data;

typedef struct s_player
{
	char	orientation;
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
}	t_player;

typedef struct s_cub_textures
{
	mlx_texture_t	*n;
	mlx_texture_t	*s;
	mlx_texture_t	*e;
	mlx_texture_t	*w;
}	t_cub_textures;

typedef struct s_data
{
	t_map_data	*map_data;
	mlx_t		*mlx;
	t_player	*player;
	mlx_image_t	*img;
	double		angle;
	mlx_image_t	*img2; //minimap background
	mlx_image_t	*img_player;
	int			scale_map; //temporarily
	t_cub_textures	walls;
}	t_data;

#endif // CUB3D_STRUCTS_H
