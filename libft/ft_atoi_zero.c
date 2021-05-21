/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_zero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 15:24:21 by amarcell          #+#    #+#             */
/*   Updated: 2021/02/04 12:48:08 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		zero_is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\r' ||
		c == '\v' || c == '\f' || c == ' ')
		return (1);
	return (0);
}

int		zero_ret(int sign, int size, int result)
{
	if (size > 10 && sign > 0)
		return (-1);
	else if (size > 10 && sign < 0)
		return (0);
	return ((int)(sign * result));
}

int		ft_atoi_zero(const char *str)
{
	int		i;
	int		sign;
	int		result;
	int		size;

	result = 0;
	sign = 1;
	i = 0;
	while (zero_is_space(str[i]))
		i++;
	if (str[i] == '-')
		i++;
	else if (str[i] == '+')
		i++;
	else if (str[i] == '0')
		i++;
	size = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + (str[i] - '0');
		i++;
		size++;
	}
	return (zero_ret(sign, size, result));
}
