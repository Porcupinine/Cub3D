/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   remove_new_line.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/19 17:46:34 by laura         #+#    #+#                 */
/*   Updated: 2024/01/19 17:46:34 by laura         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib42/include/libft.h"

void remove_new_line(char *str)
{
	str[ft_strlen(str)] = '\0';
}