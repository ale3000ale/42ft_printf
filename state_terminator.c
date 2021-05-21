/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_terminator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 10:58:32 by alexmarcell       #+#    #+#             */
/*   Updated: 2021/02/05 18:56:05 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*char_to_string(va_list arg)
{
	char	*str;

	g_ch = (char)va_arg(arg, int);
	if (!(str = malloc(2)))
		return (0);
	str[0] = g_ch;
	str[1] = 0;
	return (str);
}

char	*perc_void(int perc, char **tm)
{
	char *str;

	if (!(str = malloc(2)))
		return (0);
	if (perc)
		str[0] = '%';
	else
	{
		str[0] = 0;
		(*tm)--;
	}
	str[1] = 0;
	return (str);
}

int		is_that_char(char c)
{
	if (c == 'c' || c == 's' || c == 'p' ||
			c == 'd' || c == 'i' || c == 'u' ||
			c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

char	*terminator(va_list arg, char **str)
{
	char	*s;

	if (**str == 'c')
		return (char_to_string(arg));
	else if (**str == 's')
	{
		s = va_arg(arg, char*);
		if (!s)
			return (ft_strdup("(null)"));
		s = ft_strdup(s);
		return (s);
	}
	else if (**str == 'p' || **str == 'x' || **str == 'X')
		return (hex_to_string(**str, va_arg(arg, size_t)));
	else if (**str == 'd' || **str == 'i')
		return (ft_itoa(va_arg(arg, int)));
	else if (**str == 'u')
		return (ft_unsigned_itoa(va_arg(arg, unsigned int)));
	else if (**str == '%')
		return (perc_void(1, str));
	else
		return (perc_void(0, str));
	return (0);
}
