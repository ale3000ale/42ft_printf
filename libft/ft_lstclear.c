/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 19:15:45 by amarcell          #+#    #+#             */
/*   Updated: 2021/01/16 19:20:25 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *current;

	if (lst && del)
	{
		while (*lst)
		{
			current = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = current;
		}
	}
}
