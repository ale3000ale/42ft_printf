/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:44:32 by amarcell          #+#    #+#             */
/*   Updated: 2021/02/04 13:21:11 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		dim;
	char	*input;

	dim = 0;
	va_start(arg, str);
	input = ft_strdup(str);
	i = 0;
	while (*input)
	{
		if (*input != '%')
		{
			write(1, input++, 1);
			dim++;
		}
		else
			dim += bob_the_builder(&input, arg);
	}
	free(input - ft_strlen(str));
	return (dim);
}
