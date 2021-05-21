/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strshift.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:26:02 by amarcell          #+#    #+#             */
/*   Updated: 2021/02/05 17:59:22 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strshift(char *str, int shift)
{
	int i;

	i = 0;
	if (!shift)
		return (str);
	if ((int)ft_strlen(str) <= shift)
	{
		str[0] = 0;
		return (str);
	}
	while (str[shift + i])
	{
		str[i] = str[shift + i];
		i++;
	}
	str[i] = 0;
	return (str);
}
