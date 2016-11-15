/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 11:31:15 by ndombre           #+#    #+#             */
/*   Updated: 2016/11/10 12:27:58 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

#ifdef FT_LIBFT_DEBUG

void	ft_free(void *p)
{
	if (p == NULL)
		ft_puterrl("attention vous essayer de free quelque chose null");
	free(p);
}

#else

void	ft_free(void *p)
{
	free(p);
}

#endif
