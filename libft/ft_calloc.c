/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mal.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:07:53 by amarcell          #+#    #+#             */
/*   Updated: 2021/01/14 12:29:35 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void		*array;

	if (!(array = (void *)malloc(count * size)))
		return (0);
	ft_bzero(array, size * count);
	return (array);
}
