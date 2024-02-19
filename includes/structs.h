/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:25:14 by laura             #+#    #+#             */
/*   Updated: 2024/02/14 13:18:40 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_map_data
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	int		floor;
	int		celling;
	char	**map;
	int		map_y;
	int		map_x;
	char	**game_data;
	int		data_size;
}	t_map_data;

/**
 * orientation where we are looking
 * posx and posy are characters position
 * mapx and mapy are current square of the map the ray is in
 * dirx and diry are looking
 */
typedef struct s_player
{
	int				orientation;
	double			posx;
	double			posy;
	int				mapx;
	int				mapy;
	double			dirx;
	double			diry;
	mlx_texture_t	*player_png;
}	t_player;

/**
 * texture, current_width and current_height refers to the values of the
 * texture that is being used at the moment
 * draw_start and draw_end are the position in the screen where the wall
 * starts and end
 */
typedef struct s_cub_textures
{
	mlx_texture_t	*n;
	mlx_texture_t	*s;
	mlx_texture_t	*e;
	mlx_texture_t	*w;
	mlx_texture_t	*texture;
	uint32_t		current_width;
	uint32_t		current_height;
	int				line_height;
	int				draw_start;
	int				draw_end;
}	t_cub_textures;

/**
 * stepx and stepy are where to go
 * sidex and sidey are initially the distance the ray has to travel from its
 * start position to the first x-side and the first y-side.
 * deltax and deltay are distance the ray has to travel to go from 1 x-side
 * to the next x-side, or from 1 y-side to the next y-side.
 * planex and planey are area we can see
 * x1 and y1 are were we are going
 */
typedef struct s_ray
{
	int		stepx;
	int		stepy;
	double	sidex;
	double	sidey;
	double	deltax;
	double	deltay;
	double	planex;
	double	planey;
	double	x1;
	double	y1;
}	t_ray;

typedef struct s_minimap
{
	mlx_texture_t	*wall_png;
	mlx_texture_t	*player_png;
	mlx_texture_t	*floor_png;
	mlx_image_t		*img_player;
	mlx_image_t		*img_wall;
	mlx_image_t		*img_floor;
}	t_minimap;

typedef struct s_data
{
	t_ray			*ray;
	int				side;
	t_map_data		*map_data;
	t_player		*player;
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_image_t		*mini_img;
	mlx_image_t		*strimage;
	double			angle;
	char			texture;
	int				scale_map;
	t_cub_textures	*walls;
	t_minimap		*map;
	double			r_d2;
	double			r_d;
	double			wallx;
}	t_data;

#endif //STRUCTS_H
