/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/18 12:49:11 by laura         #+#    #+#                 */
/*   Updated: 2024/01/18 12:49:11 by laura         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_UTILS_H
#define CUB3D_UTILS_H


int	test_isspace(char*str);
int	first_map_line(char*str);
void print_map(t_parse_data *cub_data);
void print_paths(t_parse_data *cub_data);
int	all_digits(char*str);

#endif //CUB3D_UTILS_H
