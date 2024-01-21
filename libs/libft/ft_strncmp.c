/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:14:12 by akrepkov          #+#    #+#             */
/*   Updated: 2022/10/29 11:41:33 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			i;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	i = 0;
	while ((p1[i] != '\0' || p2[i] != '\0') && i < n)
	{
		if (p1[i] > p2[i])
		{
			return (1);
		}
		if (p1[i] < p2[i])
		{
			return (-1);
		}
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
	printf ("%d\n",ft_strncmp(sl, s2, n));
	printf ("%d",strncmp(sl, s2, n));
	return (0);
}*/