/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   all_digits.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/19 15:55:17 by laura         #+#    #+#                 */
/*   Updated: 2024/01/26 11:46:53 by laura         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib42/include/libft.h"

int	all_digits(char*str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		if (ft_strchr("0123456789", str[count]) == 0)
			return (0);
		count++;
	}
	return (1);
}
