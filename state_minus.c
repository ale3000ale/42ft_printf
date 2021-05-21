/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_minus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 10:59:54 by alexmarcell       #+#    #+#             */
/*   Updated: 2021/02/05 18:12:51 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*minus_peter(va_list arg, char **str)
{
	(*str)++;
	if (ft_isdigit(**str) || **str == '*' || **str == ' ')
		return (number(arg, str, 1));
	else if (**str == '.')
		return (point(arg, str));
	return (terminator(arg, str));
}
