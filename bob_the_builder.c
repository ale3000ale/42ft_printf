/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bob_the_builder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 13:24:10 by amarcell          #+#    #+#             */
/*   Updated: 2021/02/05 18:22:02 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		minum(char *str)
{
	int		min;

	min = 0;
	while (*str != '%')
	{
		if (*(str--) == '-')
		{
			min = 1;
			break ;
		}
	}
	return (min);
}

int		control_char(char *str, int dim, char *build)
{
	int		min;

	min = minum(str);
	if (!g_ch && !min)
	{
		ft_putstr_fd(build, 1);
		write(1, "\0", 1);
		dim++;
	}
	else if (!g_ch)
	{
		write(1, "\0", 1);
		ft_putstr_fd(build, 1);
		dim++;
	}
	else
		ft_putstr_fd(build, 1);
	return (dim);
}

char	*builder(char **str, va_list arg)
{
	char	*build;

	(*str)++;
	if (**str == '0')
		build = zero(arg, str);
	else if (**str == '-')
		build = minus_peter(arg, str);
	else if (**str == '*' || ft_isdigit(**str) || **str == ' ')
		build = number(arg, str, 0);
	else if (**str == '.')
		build = point(arg, str);
	else if (is_that_char(**str))
		build = terminator(arg, str);
	else
		return (0);
	return (build);
}

int		bob_the_builder(char **str, va_list arg)
{
	int		dim;
	char	*build;

	dim = 0;
	build = builder(str, arg);
	arg = 0;
	if (build)
	{
		dim = ft_strlen(build);
		if (**str == 'c')
			dim = control_char(*str, dim, build);
		else
			ft_putstr_fd(build, 1);
	}
	(*str)++;
	return (dim);
}
