/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narlati <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 17:06:47 by narlati           #+#    #+#             */
/*   Updated: 2016/11/17 10:47:11 by narlati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "map.h"
#include <stdlib.h>

t_map	*newmap(void)
{
	t_map		*ret;

	ret = malloc(sizeof(t_map));
	if (ret == NULL)
		return (NULL);
	ret->currantsize = 0;
	ret->optofind = 0;
	ft_memset(ret->tab, '.', sizeof(ret->tab));
	return (ret);
}

t_map	*cpymap(t_map *dest, t_map *src)
{
	return ((t_map*)ft_memcpy(dest, src, sizeof(t_map)));
}

int		canput_tetri_in_map(t_map *m, t_tetri *t, int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (t->tab[i][j] != '.' && m->tab[i + x][j + y] != '.')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	put_tetri_in_map(t_map *m, t_tetri *t, int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (t->tab[i][j] != '.')
			{
				m->tab[i + x][j + y] = t->tab[i][j];
				if (i + x >= m->currantsize)
					m->currantsize = i + x + 1;
				if (j + y >= m->currantsize)
					m->currantsize = j + y + 1;
			}
			j++;
		}
		i++;
	}
}
