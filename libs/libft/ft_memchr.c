/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 14:56:46 by akrepkov          #+#    #+#             */
/*   Updated: 2022/11/11 14:52:27 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	cc;

	i = 0;
	p = (unsigned char *)s;
	cc = (unsigned char)c;
	while (i < n)
	{
		if (p[i] == cc)
			return (&p[i]);
		i++;
	}
	return (0);
}
/*
int main ()
{
	int c = 72;
  	const char s[] = "adfssff";
	printf("\n\n%s", memchr(s, c, 3));
  	printf("\n\n%s", ft_memchr(s, c, 3));
	
  	return (0);
	
}*/