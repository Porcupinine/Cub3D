/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:02:52 by akrepkov          #+#    #+#             */
/*   Updated: 2022/11/11 14:49:07 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (!s)
		return (0);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s)) + 1);
	if (str == 0)
		return (0);
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
char	*f(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		printf("%c\n", s[i]);
		i++;
	}
	return (0);
}

int main ()
{
	const char s[] = "Privet";
	f(s);
	return (0);
}*/