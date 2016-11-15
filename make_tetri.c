/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narlati <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 17:06:38 by narlati           #+#    #+#             */
/*   Updated: 2016/11/15 17:06:39 by narlati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tetri.h"

t_tetri		*make_tetri(char *t)
{
	t_tetri *ret;

	ret = ft_malloc(sizeof(t_tetri));
	ret->next = NULL;
	ret->use = 0;
	ft_memcpy(ret->tab[0], t + 0, 4);
	ft_memcpy(ret->tab[1], t + 5, 4);
	ft_memcpy(ret->tab[2], t + 10, 4);
	ft_memcpy(ret->tab[3], t + 15, 4);
	return (normalise_tetri(ret));
}
