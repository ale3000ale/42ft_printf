/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 17:31:03 by amarcell          #+#    #+#             */
/*   Updated: 2021/01/13 17:31:10 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	long dim;
	long i;
	char *dup;

	i = 0;
	while (s1[i])
		i++;
	dim = i;
	if (!(dup = (char*)malloc(dim + 1)))
		return (0);
	i = 0;
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = s1[i];
	return (&dup[0]);
}
