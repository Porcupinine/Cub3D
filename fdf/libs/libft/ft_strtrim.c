/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:35:04 by akrepkov          #+#    #+#             */
/*   Updated: 2022/11/14 18:12:47 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
//#include <string.h>
// #include <stdio.h>

static int	ft_starttrim(char const *s1, char const *set)
{
	int		i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (ft_strchr(set, s1[i]) != 0)
			i++;
		else
			return (i);
	}
	return (i);
}

static int	ft_endtrim(char const *s1, char const *set)
{
	int		i;

	i = ft_strlen(s1);
	while (i >= 0)
	{
		if (ft_strchr(set, s1[i]) != 0)
			i--;
		else
			return (i);
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		start;
	int		end;
	int		n;
	char	*s;

	s = (char *)s1;
	if (set == 0)
		return (NULL);
	if (s1 == 0)
		return (NULL);
	start = ft_starttrim(s, set);
	end = ft_endtrim(s, set);
	if (start > end)
		return (ft_strdup(""));
	n = (end - start + 1);
	res = (char *)malloc(sizeof(char) * (n + 1));
	if (!(res))
		return (0);
	ft_strlcpy(res, &s[start], n + 1);
	return (res);
}

// int	main()
// {
// 	char const *s = "abcdabc";
// 	char const	*set = "acb";
// 	printf("%s\n", ft_strtrim (s, set));
// 	return (0);
// }
