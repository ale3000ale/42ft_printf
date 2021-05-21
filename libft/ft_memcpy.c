/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:26:52 by amarcell          #+#    #+#             */
/*   Updated: 2021/01/15 12:27:13 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ds;
	unsigned char	*sr;
	size_t			i;

	if (!dest && !src)
		return (0);
	ds = (unsigned char*)dest;
	sr = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		ds[i] = sr[i];
		i++;
	}
	return (ds);
}
