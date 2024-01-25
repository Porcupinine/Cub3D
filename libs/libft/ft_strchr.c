/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 12:16:27 by akrepkov          #+#    #+#             */
/*   Updated: 2022/10/28 15:20:31 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ps;
	char	cc;

	i = 0;
	ps = (char *)s;
	cc = (char)c;
	while (ps[i] != cc)
	{
		if (ps[i] == '\0')
			return (0);
		i++;
	}
	return (&ps[i]);
}

/*
int main ()
{
  char str[] = "adfssff";
  printf("\n\n%s", ft_strchr(str, 's'));
  return 0;
}
*/