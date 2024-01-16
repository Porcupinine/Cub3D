/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:35:44 by akrepkov          #+#    #+#             */
/*   Updated: 2022/11/11 14:52:03 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*p;
	const char	*p2;
	size_t		i;

	p = (char *)dest;
	p2 = (char *)src;
	i = 0;
	if (dest == 0 && src == 0)
		return (p);
	while (p > p2 && n > 0)
	{
		p[n - 1] = p2[n - 1];
		n--;
	}
	if (p <= p2)
	{
		while (i < n)
		{
			p[i] = p2[i];
			i++;
		}
	}
	return (p);
}

/* int main () 
{
   char dest[50] = "old";
   const char src[]  = "newstring";

   printf("Before memmove dest = %s, src = %s\n", dest, src);
   ft_memmove(dest, src, 4);
   printf("Mijn dest = %s, src = %s\n", dest, src);

   return(0);
} */