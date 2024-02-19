/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:32:16 by laura             #+#    #+#             */
/*   Updated: 2024/02/06 15:03:40 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKS_H
# define CHECKS_H

# include "structs.h"

/**
 * checks if the map is surrounded and if there is one and only player
 * in case any error occurs, exit with invalid map.
 * @param cub_data
 */
void	check_map(t_data *cub_data);
/**
 * check if there is data for all coordinates
 * @param map_data
 */
void	check_values(t_data *map_data);
void	find_direction(t_data *cub_data, char dir);

#endif //CHECKS_H
