/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 20:59:09 by laura             #+#    #+#             */
/*   Updated: 2024/02/19 13:17:22 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/structs.h"
#include "../../includes/utils.h"
#include "../../lib42/include/libft.h"

void	clean_up(t_data *cub_data, char *msg)
{
	delete_texture(cub_data);
	free_cub(cub_data);
	ft_error(msg);
}
