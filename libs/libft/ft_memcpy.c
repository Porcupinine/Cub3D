/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:15:20 by akrepkov          #+#    #+#             */
/*   Updated: 2022/11/11 14:51:52 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*p;
	const char	*p2;
	size_t		i;

	p = dest;
	p2 = src;
	i = 0;
	if (n == 0)
		return (p);
	if (dest == 0 && src == 0)
		return (p);
	while (i < n)
	{
		p[i] = p2[i];
		i++;
	}
	return (p);
}

// int main () 
// {
//    char src[50];
//    char dest[50];
//    ft_memcpy(dest, src, 0);
//    printf ("%lu\n", strlen(src));
//    printf("where are %s\n", dest);
//    printf("Return: %s", ft_memcpy(dest, src, 5));
//    return(0);
// }