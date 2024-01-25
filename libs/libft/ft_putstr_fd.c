/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:38:08 by akrepkov          #+#    #+#             */
/*   Updated: 2022/11/11 14:47:49 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}
// int	main()
// {
// 	char str[8] = "Coffee?";
// 	int	fd;

// 	fd = open("test", O_WRONLY);

// 	ft_putendl_fd (str, fd);
// 	return (0);
// }