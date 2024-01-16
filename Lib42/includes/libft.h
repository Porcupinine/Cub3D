/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lpraca-l <lplacerdadesign@gmail.com>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/09 19:47:08 by lpraca-l      #+#    #+#                 */
/*   Updated: 2023/05/23 15:14:27 by lpraca-l      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/**
 * Gets the length
 * @param c string to be measured
 * @return length of the string
 */
size_t	ft_strlen(const char *c);
/**
 * prints message on stderr and call exit with code 1
 * @param error error message;
 */
void	ft_error(char *error);

#endif