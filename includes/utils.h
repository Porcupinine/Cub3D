/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:49:11 by laura             #+#    #+#             */
/*   Updated: 2024/01/25 16:36:12 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_UTILS_H
#define CUB3D_UTILS_H
#include "structs.h"

/**
 *
 * @param str
 * @return 1 if the string is empty and 0 if not
 */
int	test_isspace(char*str);
int	test_isspace_limited(char*str, int n);
/**
 *
 * @param str
 * @return 1 if the string only contains spaces, new line, 0 and 1. 0 if not
 */
int	first_map_line(char*str);
void print_map(t_map_data *cub_data);
void print_colors(t_map_data *cub_data);
void print_paths(t_map_data *cub_data);
/**
 *
 * @param str
 * @return 1 if the string only contains digits, 0 if not
 */
int	all_digits(char*str);
int get_r(int rgba);
int get_g(int rgba);
int get_b(int rgba);
int get_a(int rgba);
int get_rgba(int r, int g, int b, int a);



#endif //CUB3D_UTILS_H
