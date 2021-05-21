/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:37:54 by amarcell          #+#    #+#             */
/*   Updated: 2021/01/15 12:37:56 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t i;
	size_t dim;

	i = 0;
	while (dest[i] && i < destsize)
		i++;
	dim = i;
	i = 0;
	while (src[i] && (dim + i + 1) < destsize)
	{
		dest[i + dim] = src[i];
		i++;
	}
	if (dim < destsize)
		dest[i + dim] = '\0';
	return (dim + ft_strlen(src));
}
