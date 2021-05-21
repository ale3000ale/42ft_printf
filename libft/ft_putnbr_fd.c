/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 15:05:15 by amarcell          #+#    #+#             */
/*   Updated: 2021/01/15 15:05:16 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		dimension_nbr(int n)
{
	int dim;

	if (n == 0)
		return (0);
	dim = 0;
	while (n)
	{
		n = n / 10;
		dim++;
	}
	return (dim - 1);
}

int		power_nbr(int n, int p)
{
	int res;

	res = 1;
	while (p)
	{
		res *= n;
		p--;
	}
	return (res);
}

int		converter_nbr(int dim, int i, long num, char *str)
{
	while (dim >= 10)
	{
		str[i] = '0' + (num / dim);
		num = num % dim;
		dim /= 10;
		i++;
	}
	str[i] = '0' + num;
	return (i + 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		dim;
	long	num;
	char	str[12];
	int		i;

	i = 0;
	num = n;
	dim = dimension_nbr(n);
	if (num < 0 && num != 0)
	{
		str[i] = '-';
		num *= -1;
		i++;
	}
	dim = power_nbr(10, dim);
	i = converter_nbr(dim, i, num, str);
	str[i] = 0;
	ft_putstr_fd(str, fd);
}
