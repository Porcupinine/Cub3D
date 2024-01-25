/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:32:47 by akrepkov          #+#    #+#             */
/*   Updated: 2023/02/22 12:42:35 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

void	*ft_memset(void *str, int c, size_t n)
{
	char	*p;

	p = str;
	while (n != 0)
	{
		*p = c;
		p++;
		n--;
	}
	return (str);
}
