/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 10:09:18 by ndombre           #+#    #+#             */
/*   Updated: 2016/11/10 12:27:30 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

#ifdef FT_LIBFT_DEBUG

void		*ft_malloc(size_t s)
{
	void *ret;

	if (s == 0)
		ft_puterrl("malloc of size 0");
	ret = malloc(s);
	if (ret == NULL)
		ft_puterrl("pas de chance, malloc retour null");
	return (ret);
}

#else

void		*ft_malloc(size_t s)
{
	return (malloc(s));
}

#endif
