/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   first_map_line.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/18 13:14:39 by laura         #+#    #+#                 */
/*   Updated: 2024/01/18 13:14:39 by laura         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib42/include/libft.h"

int	first_map_line(char*str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		if (ft_strchr(" 1\n0", str[count]) == 0)
			return (0);
		count++;
	}
	return (1);
}