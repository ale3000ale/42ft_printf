/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 10:57:41 by alexmarcell       #+#    #+#             */
/*   Updated: 2021/02/05 18:33:12 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		zero_point(va_list arg, char **str)
{
	(*str)++;
	if (ft_isdigit(**str) || **str == '*')
		return (number_int(arg, str));
	else
		return (0);
}

char	*build_digit(char *temp, size_t cut, va_list arg, char **str)
{
	cut = number_int(arg, str);
	temp = terminator(arg, str);
	if (ft_strlen(temp) > cut && **str == 's')
		temp[cut] = 0;
	if (ft_strlen(temp) - 2 < cut && **str == 'p')
	{
		ft_strshift(temp, 2);
		temp = build_zero((int)cut, (int)cut, (int)ft_strlen(temp), temp);
		return (ft_strjoin("0x", temp));
	}
	if (ft_strlen(temp) < cut && **str != 's' &&
		**str != 'c' && temp[0] == '-')
		return (build_zero((int)cut, (int)cut,
				(int)ft_strlen(temp) - 1, temp));
	else if (ft_strlen(temp) < cut && **str != 's' && **str != 'c')
		return (build_zero((int)cut, (int)cut, (int)ft_strlen(temp), temp));
	return (temp);
}

char	*point(va_list arg, char **str)
{
	char		*temp;
	size_t		cut;

	temp = 0;
	(*str)++;
	cut = 0;
	if ((**str == '0' && str[0][1] == 's') || **str == 's')
	{
		if (**str == '0')
			(*str)++;
		temp = terminator(arg, str);
		temp[0] = 0;
		return (temp);
	}
	if (**str == '0')
		(*str)++;
	if (ft_isdigit(**str) || **str == '*')
		return (build_digit(temp, cut, arg, str));
	temp = terminator(arg, str);
	if (**str == 'p' && temp[2] == '0' && ft_strlen(temp) == 3)
		temp[2] = 0;
	else
		temp = build_zero(0, 0, (int)ft_strlen(temp), temp);
	return (temp);
}
