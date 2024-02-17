/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:47:11 by lpraca-l          #+#    #+#             */
/*   Updated: 2024/01/31 14:28:41 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_GRAPHICS_H
#define CUB3D_GRAPHICS_H

#include "structs.h"

/**
 * draw celling and floor
 * @param data
 */
void	draw_env(t_data *data);
/**
 * load the textures into mlx_texture_t
 * @param cub_data
 */
void	load_textures(t_data *cub_data);
/**
 * find the coordinate x on the texture that is needed for drawing
 * the current line
 * @param cub_data
 * @param dist
 * @return coordinate of x in the texture
 */
int		find_texture_x(t_data *cub_data, double dist);
/**
 * starts drawing the walls
 * @param data struct with game data
 * @param dist distance between the player and the x point
 * @param x pint on th "wall"
 */
void	draw_walls(t_data *data, double dist, int x);
#endif //CUB3D_GRAPHICS_H
