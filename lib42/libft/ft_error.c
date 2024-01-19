/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_error.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lpraca-l <lpraca-l@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/14 14:46:16 by lpraca-l      #+#    #+#                 */
/*   Updated: 2023/05/23 15:00:30 by lpraca-l      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_error(char *error)
{
	size_t	str_len;
	int x;

	str_len = ft_strlen(error);
	x = write(2, error, str_len);
	(void)x;
	exit(1);
}
