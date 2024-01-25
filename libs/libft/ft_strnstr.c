/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 16:07:53 by akrepkov          #+#    #+#             */
/*   Updated: 2022/11/14 16:39:30 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*haystack, const char *needle, size_t len)
{
	char	*haystack1;
	size_t	i;
	size_t	j;

	i = 0;
	haystack1 = (char *)haystack;
	if (needle[0] == '\0' || haystack1 == needle)
		return (haystack1);
	if (haystack1[i] == '\0')
		return (0);
	while (haystack1[i] && (i < len))
	{
		j = 0;
		while ((i + j) < len && haystack1[i + j] == needle[j]
			&& haystack1[i + j] != '\0' && needle[j] != '\0')
		{
			j++;
			if (needle[j] == '\0')
				return (haystack1 + i);
		}
		i++;
	}
	return (0);
}
/*
int main()
{
	char str[] = "abcdef";
	char needle[] = "tweeabcdefghijklmnop";
	printf("%s\n", ft_strnstr(str, needle, 10));
	printf("%s", strnstr(str, needle, 10));
	return (0);
}*/
