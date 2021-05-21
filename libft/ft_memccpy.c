/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:27:32 by amarcell          #+#    #+#             */
/*   Updated: 2021/01/15 12:27:37 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*ds;
	unsigned const char	*sr;
	size_t				i;

	if (!dest && !src)
		return (0);
	ds = (unsigned char*)dest;
	sr = (unsigned const char*)src;
	i = 0;
	while (i < n)
	{
		ds[i] = sr[i];
		if (sr[i] == (unsigned char)c)
			return ((void*)&ds[i + 1]);
		i++;
	}
	return (0);
}
