/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:21:05 by akrepkov          #+#    #+#             */
/*   Updated: 2022/11/11 15:33:07 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
// #include <stddef.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	len_s;
	size_t	i;

	i = 0;
	len_s = ft_strlen(s);
	if ((start + len) > len_s)
		len = len_s - start;
	if (start >= len_s)
		return (ft_strdup("\0"));
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (0);
	ft_strlcpy (str, s + start, len + 1);
	return (str);
}
/*
int main ()
{
	const char *s = "yiiugsd";
	printf("%s", ft_substr(s, 2, 2));
	return (0);
}*/