/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 12:50:33 by amarcell          #+#    #+#             */
/*   Updated: 2021/01/26 12:50:35 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strndup(const char *s1, size_t n)
{
	char	*clone;
	size_t	len;

	if (!(clone = (char*)malloc(sizeof(char) * (n + 1))))
		return (0);
	clone[n] = '\0';
	len = ft_strlen(s1);
	if (n < len)
		ft_memcpy(clone, s1, n);
	else
		ft_memcpy(clone, s1, len);
	if (len < n)
		ft_bzero(clone + len, n - len);
	return (clone);
}
