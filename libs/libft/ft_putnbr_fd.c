/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 15:29:55 by akrepkov          #+#    #+#             */
/*   Updated: 2022/11/11 14:47:43 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		n = n % 10;
	}
	if (n >= 0 && n < 10)
		ft_putchar_fd(n + '0', fd);
}
// int	main()
// {
// 	int = 4568;
// 	int	fd;

// 	fd = TRY ANOTHER FUNCTION!("test", O_WRONLY);

// 	ft_putendl_fd (str, fd);
// 	return (0);
// }
