/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 19:21:08 by amarcell          #+#    #+#             */
/*   Updated: 2021/01/30 18:01:22 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*first;

	first = 0;
	if (lst && f)
	{
		while (lst)
		{
			if (!(new = ft_lstnew((*f)(lst->content))))
			{
				ft_lstclear(&first, del);
				first = 0;
			}
			ft_lstadd_back(&first, new);
			lst = lst->next;
		}
	}
	return (first);
}
