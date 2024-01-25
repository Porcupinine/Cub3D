/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 09:58:31 by akrepkov          #+#    #+#             */
/*   Updated: 2022/11/14 16:44:27 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int a)
{
	if (((a >= 97) && (a <= 122)) || ((a >= 65) && (a <= 90))
		|| ((a >= 48) && (a <= 57)))
		return (1);
	else
		return (0);
}