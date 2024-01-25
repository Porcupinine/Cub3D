/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:36:37 by akrepkov          #+#    #+#             */
/*   Updated: 2022/11/16 14:15:18 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*new;
	t_list	*check;

	if (!lst || !f || !del)
		return (NULL);
	temp = NULL;
	while (lst)
	{
		check = f(lst -> content);
		if (!check)
		{
			ft_lstclear(&temp, del);
			return (NULL);
		}
		new = ft_lstnew(check);
		ft_lstadd_back(&temp, new);
		lst = lst -> next;
	}
	return (temp);
}
