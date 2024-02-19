/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:47:11 by lpraca-l          #+#    #+#             */
/*   Updated: 2024/02/06 15:08:20 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "structs.h"

/**
 * checks for the extension and loops the data looking for patterns
 * as son it finds one line that only contains isspaces and 1s, it breaks.
 * it will also braek in case it finds any line that is not isspaces and
 * doesn't start with NO, SO, WE, EA, F or C.
 * @param file
 * @return parsed data of the map.
 */
void	get_data(t_data *cub_data, char *file);
/**
 * loops the line containing either F or C to extract the RGBA data.
 * The data is saved as a single integer using rgba.c functions. If it
 * contains either characters that aren't digits or if the digit is bigger
 * than 255, it gives up and exit with invalid map.
 * @param line
 * @param cub_data
 * @return
 */
void	get_fc(char *line, t_data *cub_data);
/**
 * Loops the line to extract the path for the textures used for each side
 * of the walls. If it finds a repeated coordinate or there is no ./ it
 * gives up and exits with invalid map.
 * @param line
 * @param cub_data
 * @return
 */
void	get_textures(char *line, t_data *cub_data);
/**
 *Count how many lines the map part has and parse it into an array
 * of strings. At the end finds the longest string in the array and
 * saves it as the width of the map.
 * @param file
 * @param map_data
 */
void	get_map(t_data *map_data);

#endif //PARSING_H
