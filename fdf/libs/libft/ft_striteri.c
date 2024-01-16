/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:23:31 by akrepkov          #+#    #+#             */
/*   Updated: 2022/11/11 14:48:19 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
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
	const char s[] = "Hey";
	f(s);
	return (0);
}*/