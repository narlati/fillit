/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrplchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 16:57:27 by ndombre           #+#    #+#             */
/*   Updated: 2016/11/14 17:00:37 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memrplchr(void *mem, char find, char remplace, size_t len)
{
	while (len > 0)
	{
		len--;
		if (((unsigned char*)mem)[len] == (unsigned char)find)
			((unsigned char*)mem)[len] = (unsigned char)remplace;
	}
	return (mem);
}
