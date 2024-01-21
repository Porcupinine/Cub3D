/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 15:48:37 by akrepkov          #+#    #+#             */
/*   Updated: 2022/11/11 14:45:29 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_ilength(long long int n)
{
	long long int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long long int	len;
	long long int	n2;
	char			*res;

	n2 = (long long int)n;
	len = ft_ilength(n2);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == 0)
		return (0);
	res[len] = '\0';
	if (n2 == 0)
		res[0] = '0';
	if (n2 < 0 && n2 != -2147483648)
	{
		res[0] = '-';
		n2 = -n;
	}
	if (n2 == -2147483648)
		ft_strlcpy(res, "-2147483648", len + 1);
	while (len-- && n2 > 0)
	{
		res[len] = '0' + (n2 % 10);
		n2 = n2 / 10;
	}
	return (res);
}
