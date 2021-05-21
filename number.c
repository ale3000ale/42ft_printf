/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 13:16:49 by amarcell          #+#    #+#             */
/*   Updated: 2021/02/06 16:48:52 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			**init(char **sp_rs_s, int *num, int *sp_flag)
{
	if (!(sp_rs_s = malloc(sizeof(char*) * (3))))
		return (0);
	sp_rs_s[2] = 0;
	sp_rs_s[1] = 0;
	*num = 0;
	*sp_flag = 0;
	sp_rs_s[0] = 0;
	return (sp_rs_s);
}

static	void	digit(char **str, va_list arg, int *num, int *right)
{
	if (**str == '*' || ft_isdigit(**str))
	{
		*num = number_int(arg, str);
		if (*num < 0)
		{
			*num *= -1;
			*right = 1;
		}
	}
}

static	char	*call(char **str, char **sp_rs_s, va_list arg, int *num)
{
	if (**str == '.')
		sp_rs_s[1] = point(arg, str);
	else
		sp_rs_s[1] = terminator(arg, str);
	if (**str == 'c' && !sp_rs_s[1][0])
		(*num)--;
	if (!sp_rs_s[1])
		return (0);
	return (sp_rs_s[1]);
}

char			*spacing(char *boh_non_ne_ho_idea, char **sp_rs_s,
int num, int right)
{
	if (!(boh_non_ne_ho_idea = (char *)malloc(sizeof(char) * (num + 1))))
		return (0);
	if (!(sp_rs_s[0] = (char *)malloc(sizeof(char) * (num + 1))))
		return (0);
	sp_rs_s[0][num] = 0;
	num--;
	while (num >= 0)
		sp_rs_s[0][num--] = ' ';
	sp_rs_s[0][num] = 0;
	if (right)
		sp_rs_s[2] = ft_strjoin(sp_rs_s[1], sp_rs_s[0]);
	else
		sp_rs_s[2] = ft_strjoin(sp_rs_s[0], sp_rs_s[1]);
	free(sp_rs_s[1]);
	free(sp_rs_s[0]);
	return (sp_rs_s[2]);
}

char			*number(va_list arg, char **str, int right)
{
	char	**sp_rs_s;
	int		num;
	int		sp_flag;
	char	*boh_non_ne_ho_idea;

	boh_non_ne_ho_idea = 0;
	sp_rs_s = 0;
	sp_rs_s = init(sp_rs_s, &num, &sp_flag);
	digit(str, arg, &num, &right);
	sp_rs_s[1] = call(str, sp_rs_s, arg, &num);
	while (**str == ' ')
	{
		(*str)++;
		sp_flag = 1;
	}
	num = num - ft_strlen(sp_rs_s[1]) - sp_flag;
	if (num > 0)
		sp_rs_s[2] = spacing(boh_non_ne_ho_idea, sp_rs_s, num, right);
	else
	{
		space_flag(&sp_rs_s[1], sp_flag);
		return (sp_rs_s[1]);
	}
	space_flag(&sp_rs_s[2], sp_flag);
	return (sp_rs_s[2]);
}
