/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 16:09:47 by amarcell          #+#    #+#             */
/*   Updated: 2021/02/06 17:51:30 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdarg.h>
# include "libft/libft.h"

char	g_ch;
int		is_that_char(char c);
char	*char_to_string(va_list arg);
char	*terminator(va_list arg, char **str);
char	*number(va_list arg, char **str, int right);
char	*point(va_list arg, char **str);
int		bob_the_builder(char **str, va_list arg);
int		ft_printf(char const *str, ...);
char	*hex_to_string(char ch, size_t hex);
int		number_int(va_list arg, char **str);
int		zero_point(va_list arg, char **str);
char	*zero(va_list arg, char **str);
char	*minus_peter(va_list arg, char **str);
char	*build_zero(int precision, int dim, int len, char *str);
char	*number_direct(int num, char *str);
void	space_flag(char **sp, int sp_flag);
char	*result_zero(int *p_d_l, char **str, int *sig, va_list arg);

#endif
