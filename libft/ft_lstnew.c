/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:02:06 by amarcell          #+#    #+#             */
/*   Updated: 2021/01/16 16:02:09 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *l;

	if (!(l = (t_list*)malloc(sizeof(t_list))))
		return (0);
	l->content = content;
	l->next = 0;
	return (l);
}
