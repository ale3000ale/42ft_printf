/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_star.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 10:59:20 by alexmarcell       #+#    #+#             */
/*   Updated: 2021/02/06 13:17:15 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	space_flag(char **sp, int sp_flag)
{
	char	*f_space;
	char	*free_me;

	if (sp_flag)
	{
		f_space = ft_strdup(" ");
		free_me = *sp;
		*sp = ft_strjoin(f_space, *sp);
		free(free_me);
		free(f_space);
	}
}

int		number_int(va_list arg, char **str)
{
	int		num;
	char	*st_num;
	int		i;

	if (**str == '*')
	{
		num = va_arg(arg, int);
		(*str)++;
	}
	else
	{
		st_num = ft_strjoin("", *str);
		i = 0;
		while (ft_isdigit(st_num[i]))
			i++;
		st_num[i] = 0;
		*str += i;
		num = ft_atoi_zero(st_num);
		free(st_num);
	}
	return (num);
}

char	*number_direct(int num, char *str)
{
	char	**sp_rs_s;

	if (!(sp_rs_s = malloc(sizeof(char*) * (3))))
		return (0);
	sp_rs_s[2] = 0;
	sp_rs_s[1] = str;
	sp_rs_s[0] = 0;
	num *= -1;
	num -= ft_strlen(sp_rs_s[1]);
	if (num > 0)
	{
		if (!(sp_rs_s[0] = (char *)malloc(sizeof(char) * (num + 1))))
			return (0);
		sp_rs_s[0][num] = 0;
		num--;
		while (num >= 0)
			sp_rs_s[0][num--] = ' ';
		sp_rs_s[0][num] = 0;
		sp_rs_s[2] = ft_strjoin(sp_rs_s[1], sp_rs_s[0]);
		free(sp_rs_s[1]);
		free(sp_rs_s[0]);
	}
	return (sp_rs_s[2]);
}
