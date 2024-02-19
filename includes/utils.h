/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:49:11 by laura             #+#    #+#             */
/*   Updated: 2024/02/13 15:01:21 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "structs.h"

/**
 * testes if the string only contains ISSPACE chars
 * @param str
 * @return 1 if the string is empty and 0 if not
 */
int		test_isspace(char*str);
/**
 * testes iff all char in a string are ISSPACE up to  n bytes
 * @param str
 * @param n
 * @return 1 if the string is empty and 0 if not
 */
int		test_isspace_limited(char*str, int n);
/**
 * checks if the line consists in onlt 1, 0, space and new line
 * @param str
 * @return 1 if the string only contains spaces, new line, 0 and 1. 0 if not
 */
int		first_map_line(char*str);
/**
 * prints the parsed map
 * @param map_data
 */
void	print_map(t_map_data *map_data);
/**
 * print the floor and celling data
 * @param map_data
 */
void	print_colors(t_map_data *map_data);
/**
 * print the textures data
 * @param map_data
 */
void	print_paths(t_map_data *map_data);
/**
 * print the data from the parsed main file
 * @param map_data
 */
void	print_data(t_map_data *map_data);
/**
 * checks if the string only contains digits
 * @param str
 * @return 1 if the string only contains digits, 0 if not
 */
int		all_digits(char*str);
/**
 * gets r value
 */
int		get_r(int rgba);
/**
 * gets g value
 */
int		get_g(int rgba);
/**
 * gets b value
 */
int		get_b(int rgba);
/**
 * gets alpha value
 */
int		get_a(int rgba);
/**
 * converts r, g, b and a value into a single integer
 */
int		get_rgba(int r, int g, int b, int a);
/**
 * free all allocated memory
 */
void	free_cub(t_data *cub_data);
/**
 * free array of strings
 */
void	free_split(char **array);
/**
 * free the parsed data
 */
void	free_game_data(t_map_data *map_data);
/**
 * copy the file into a array of strings
 */
void	copy_data(t_data *data, char*file);
/**
 * delete all textures if not NULL
 */
void	delete_texture(t_data *cub_data);
/**
 * calls delete_texture and free_cub, and ft_error with
 * given message
 */
void	clean_up(t_data *cub_data, char *msg);

#endif //UTILS_H
