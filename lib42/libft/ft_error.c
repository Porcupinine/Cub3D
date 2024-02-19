/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:46:16 by lpraca-l          #+#    #+#             */
/*   Updated: 2024/02/19 14:10:09 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_error(char *error)
{
	size_t	str_len;
	int		x;

	str_len = ft_strlen(error);
	x = write(2, error, str_len);
	(void)x;
	exit(1);
}
