/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:34:30 by amarcell          #+#    #+#             */
/*   Updated: 2021/01/15 12:34:40 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void const *str, int c, size_t n)
{
	unsigned char			*st;
	size_t					i;

	st = (unsigned char*)str;
	i = 0;
	while (i < n)
	{
		if (st[i] == (unsigned char)c)
			return ((void *)&st[i]);
		i++;
	}
	return (0);
}
