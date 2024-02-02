/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:25:14 by laura             #+#    #+#             */
/*   Updated: 2024/02/02 13:33:01 by akrepkov         ###   ########.fr       */
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
	int	orientation;
	double	posX;
	double	posY;
	int		mapX;
	int		mapY;
	double	dirX;
	double	dirY;
	mlx_texture_t	*player_png;
}	t_player;

typedef struct s_cub_textures
{
	mlx_texture_t	*n;
	mlx_texture_t	*s;
	mlx_texture_t	*e;
	mlx_texture_t	*w;
}	t_cub_textures;

typedef struct s_ray
{
	int		stepX;
	int		stepY;
	double	sideX;
	double	sideY;
	double	deltaX;
	double	deltaY;
	double	planeX;
	double	planeY;
	double	x1;
	double	y1;
} t_ray;

typedef struct s_minimap
{
	mlx_texture_t	*wall_png;
	mlx_texture_t	*player_png;
	mlx_texture_t	*floor_png;
	mlx_image_t		*img_player;
	mlx_image_t		*img_wall;
	mlx_image_t		*img_floor;
	
} t_minimap;

typedef struct s_data
{
	t_ray		*ray;
	t_map_data	*map_data;
	t_player	*player;
	mlx_t		*mlx;
	mlx_image_t	*img;
	mlx_image_t	*comb; //not using
	double		angle;
	char texture;
	int scale_map; //temporarily
	t_cub_textures	walls;
	t_minimap	*map;
} t_data;


#endif // CUB3D_STRUCTS_H
