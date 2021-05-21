/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_to_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 10:33:20 by alexmarcell       #+#    #+#             */
/*   Updated: 2021/02/05 18:23:29 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*prefix(char c, char *str)
{
	char	*temp_str;

	if (c == 'p')
	{
		temp_str = str;
		str = ft_strjoin("0x", str);
		free(temp_str);
	}
	return (str);
}

char	*rev_hex(char c, char *str, int dim)
{
	int		i;
	char	temp;

	dim--;
	while (dim >= 1)
	{
		if (str[dim] == '0')
			str[dim] = 0;
		else
			break ;
		dim--;
	}
	i = 0;
	while (i != dim && ((i - 1) != dim))
	{
		temp = str[i];
		str[i++] = str[dim];
		str[dim--] = temp;
	}
	return (prefix(c, str));
}

char	*hex_to_string(char ch, size_t hex)
{
	char	*str;
	int		i;
	size_t	c;
	int		dim;

	dim = (ch == 'p') ? 16 : 8;
	if (!(str = (char*)malloc(dim + 1)))
		return (0);
	str[dim] = 0;
	i = 0;
	while (i < dim)
	{
		c = ((hex >> (4 * i)) & (15));
		if (c < 10)
			str[i] = c + '0';
		else
			str[i] = (ch == 'X') ? c + 'A' - 10 : c + 'a' - 10;
		i++;
	}
	str[i] = 0;
	str = rev_hex(ch, str, dim);
	return (str);
}
