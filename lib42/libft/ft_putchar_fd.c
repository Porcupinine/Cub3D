/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:56:32 by lpraca-l          #+#    #+#             */
/*   Updated: 2024/02/19 14:09:43 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Outputs the character ’c’ to the given file
descriptor.
c: The character to output.
fd: The file descriptor on which to write.*/

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	int	x;

	x = write(fd, &c, 1);
	(void)x;
}
