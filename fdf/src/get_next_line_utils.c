/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:57:16 by akrepkov          #+#    #+#             */
/*   Updated: 2023/02/28 12:55:31 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*newstring(int size)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	str[size] = '\0';
	while (size--)
		str[size] = '\0';
	return (str);
}

size_t	ft_strlen_gnl(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char		*res;
	size_t		i;
	size_t		j;

	if (!s1)
		s1 = newstring(0);
	if (!s1 || !s2)
		return (NULL);
	res = malloc(sizeof(char) *(ft_strlen_gnl(s1) + ft_strlen_gnl(s2)) + 1);
	if (!res)
	{
		free(s1);
		return (NULL);
	}
	i = -1;
	while (s1[++i] != '\0')
		res[i] = s1[i];
	j = 0;
	while (s2[j] != '\0')
		res[i++] = s2[j++];
	res[i] = '\0';
	free (s1);
	return (res);
}

int	ft_strchr_gnl(char *s, char c)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}
