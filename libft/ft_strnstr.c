/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:38:24 by amarcell          #+#    #+#             */
/*   Updated: 2021/01/15 12:38:34 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i])
	{
		if (haystack[i] == needle[0] && i < len)
		{
			j = 1;
			while (haystack[i + j] && needle[j] && i + j < len)
			{
				if (haystack[i + j] == needle[j])
					j++;
				else
					break ;
			}
			if (needle[j] == '\0')
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (0);
}
