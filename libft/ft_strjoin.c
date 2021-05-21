/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:18:56 by amarcell          #+#    #+#             */
/*   Updated: 2021/02/05 17:58:04 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		len[2];
	char	*str;

	i = 0;
	while (s1[i])
		i++;
	len[0] = i;
	i = 0;
	while (s2[i])
		i++;
	len[1] = i;
	if (!(str = (char*)malloc(len[0] + len[1] + 1)))
		return (0);
	i = 0;
	while (i < len[0] + len[1])
	{
		if (i < len[0])
			str[i] = s1[i];
		else
			str[i] = s2[i - len[0]];
		i++;
	}
	str[i] = '\0';
	return (str);
}
