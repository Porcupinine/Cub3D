/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:40:36 by akrepkov          #+#    #+#             */
/*   Updated: 2022/11/11 14:52:35 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;
	size_t				i;

	p1 = (const unsigned char *)s1;
	p2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
	i++;
	}
	return (0);
}
/*
int main (void)
{
	size_t n;

	n = 6;

	char sl[] = "\x12\xff\x65\x12\xbd\xde\xad";
	char s2[] = "\x12\x02";
	printf ("%d\n",ft_memcmp(sl, s2, n));
	printf ("%d",memcmp(sl, s2, n));
	return (0);
}*/