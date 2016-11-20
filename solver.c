/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 17:05:15 by ndombre           #+#    #+#             */
/*   Updated: 2016/11/20 15:25:20 by narlati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "solve.h"
#include "tetri.h"

void	rm_tetri_in_map(t_map *m, t_tetri *t, int x, int y)
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
				m->tab[i + x][j + y] = '.';
			}
			j++;
		}
		i++;
	}
}

void	try(t_map *cmap, t_tetri *aplacer, t_tetri *a, t_map *best)
{
	int ci;
	int cj;
	int oldsize;

	ci = 0;
	oldsize = cmap->currantsize;
	while (ci < best->currantsize)
	{
		cj = 0;
		while (cj < best->currantsize)
		{
			if (canput_tetri_in_map(cmap, aplacer, ci, cj))
			{
				put_tetri_in_map(cmap, aplacer, ci, cj);
				if (cmap->currantsize < best->currantsize)
					solver(cmap, a, best);
				rm_tetri_in_map(cmap, aplacer, ci, cj);
				cmap->currantsize = oldsize;
			}
			cj++;
		}
		ci++;
	}
}

int		stopall(t_map *tm)
{
	int i;
	int j;
	int nbpoin;

	nbpoin = 0;
	i = 0;
	while (i < tm->currantsize)
	{
		j = 0;
		while (j < tm->currantsize)
		{
			if (tm->tab[i][j] == '.')
				nbpoin++;
			j++;
		}
		i++;
	}
	if (nbpoin < tm->currantsize * 2 - 1)
		return (42);
	return (0);
}

void	solver(t_map *tm, t_tetri *cur, t_map *best)
{
	if (best->optofind > 7 || tm->currantsize >= best->currantsize)
		return ;
	if (cur != NULL)
	{
		try(tm, cur, cur->next, best);
		return ;
	}
	if (tm->currantsize < best->currantsize)
	{
		cpymap(best, tm);
		best->optofind = stopall(best);
	}
}
