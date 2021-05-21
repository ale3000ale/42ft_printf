/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_zero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 11:00:25 by alexmarcell       #+#    #+#             */
/*   Updated: 2021/02/06 17:49:44 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	precision(int prec, char **str, int neg)
{
	int	len;
	int	i;

	len = ft_strlen(*str) - prec;
	i = 0;
	if ((*str)[0] == '0' && ft_strlen(*str) == 1)
	{
		(*str)[0] = 0;
		return ;
	}
	while (i < len && (*str)[i] && (*str)[i] == '0')
		(*str)[i++] = ' ';
	if (i > 0 && neg)
	{
		(*str)[--i] = '-';
		(*str) = ft_strjoin(" ", (*str));
	}
	else if (neg)
		(*str) = ft_strjoin("-", (*str));
}

void	sizing(int *neg, char *str)
{
	if (str[0] == '-')
	{
		*neg = 1;
		str = ft_strshift(str, 1);
	}
}

char	*build_zero(int prec, int dim, int len, char *str)
{
	char	*str_zero;
	char	*supp;
	int		size;
	int		neg;

	neg = 0;
	sizing(&neg, str);
	size = (prec > dim) ? prec - len + neg : dim - len;
	if (size && size > 0)
	{
		if (!(str_zero = (char*)malloc(size + 1 + neg)))
			return (0);
		str_zero[size + neg] = 0;
		dim = 0;
		while (dim < size)
			str_zero[dim++] = '0';
		supp = ft_strjoin(str_zero, str);
		precision(prec, &supp, neg);
		free(str);
		free(str_zero);
		return (supp);
	}
	else
		precision(prec, &str, neg);
	return (str);
}

char	*sign(int prec, char *res)
{
	int	space;
	int	dim;
	int	i;

	space = 0;
	dim = 0;
	i = 0;
	while (res[i])
	{
		if (ft_isdigit(res[i]) || ft_isalpha(res[i]) || res[i] == '-')
			space++;
		i++;
	}
	if (space > prec)
		prec = space;
	space = ft_strlen(res) - space;
	i = 0;
	res = ft_strshift(res, space);
	dim = ft_strlen(res);
	while (i < space)
	{
		res[dim + i] = ' ';
		i++;
	}
	return (res);
}

char	*zero(va_list arg, char **str)
{
	int		p_d_l[3];
	char	*res;
	int		sig;

	sig = 0;
	res = 0;
	p_d_l[0] = 0;
	p_d_l[1] = 0;
	(*str)++;
	if (**str)
	{
		if (is_that_char(**str))
			return (terminator(arg, str));
		res = result_zero(p_d_l, str, &sig, arg);
		if (p_d_l[1] < 0)
			return (number_direct(p_d_l[1], res));
		p_d_l[2] = ft_strlen(res) ? ft_strlen(res) : 1;
		if (!(res = build_zero(p_d_l[0], p_d_l[1], p_d_l[2], res)))
			return (0);
	}
	if (sig)
		res = sign(p_d_l[0], res);
	return (res);
}
