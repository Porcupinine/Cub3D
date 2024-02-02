/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   empty_line.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/18 12:31:31 by laura         #+#    #+#                 */
/*   Updated: 2024/01/26 11:47:00 by laura         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib42/include/libft.h"

#define ISSPACE " \f\n\r\t\v"

int	test_isspace(char*str)
{
	int	count;

	count = 0;
	while (str[count] != '\0' || str[count] != '\n')
	{
		if (ft_strchr(ISSPACE, str[count]) == 0)
			return (0);
		count++;
	}
	return (1);
}

int	test_isspace_limited(char*str, int n)
{
	int	count;

	count = 0;
	while (count < n)
	{
		if (ft_strchr(ISSPACE, str[count]) == 0)
			return (0);
		count++;
	}
	return (1);
}
