/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result_zero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 17:46:06 by amarcell          #+#    #+#             */
/*   Updated: 2021/02/06 17:53:20 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*result_zero(int *p_d_l, char **str, int *sig, va_list arg)
{
	if (**str == '-')
	{
		(*sig)++;
		(*str)++;
	}
	if (ft_isdigit(**str) || **str == '*')
		p_d_l[1] = number_int(arg, str);
	if (**str == '.')
		p_d_l[0] = zero_point(arg, str);
	else
		p_d_l[0] = p_d_l[1];
	return (terminator(arg, str));
}
