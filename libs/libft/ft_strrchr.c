/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:31:50 by akrepkov          #+#    #+#             */
/*   Updated: 2022/11/09 12:39:27 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <string.h> 

char	*ft_strrchr(const char *str, int c)
{
	char	*p;
	int		len;
	char	cc;

	p = (char *)str;
	cc = (char)c;
	len = ft_strlen(p);
	while (len >= 0)
	{
		if (p[len] == cc)
			return (&p[len]);
		len--;
	}
	return (0);
}
/*
int main ()
{
  char str[] = "qweqw";
  printf("\n\n%s", ft_strrchr(str, '\0'));
  printf("\n\n%s", strrchr(str, '\0'));  
  return 0;
}*/
