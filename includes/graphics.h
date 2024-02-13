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

void draw_env(t_data *data);
void	load_textures(t_data *cub_data);
int	find_texture_x(t_data *cub_data, double dist);
//int find_texture_y(t_data *cub_data);



#endif //CUB3D_GRAPHICS_H
