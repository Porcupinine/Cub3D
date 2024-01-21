/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:12:33 by akrepkov          #+#    #+#             */
/*   Updated: 2022/11/11 14:58:03 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*ptr;
	int		len;
	int		j;

	j = 0;
	len = ft_strlen(s);
	ptr = (void *)malloc(sizeof(*s) * (len + 1));
	if (ptr == 0)
		return (0);
	while (j <= len)
	{
		ptr[j] = s[j];
		j++;
	}
	return (ptr);
}
