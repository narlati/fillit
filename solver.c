/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 17:05:15 by ndombre           #+#    #+#             */
/*   Updated: 2016/11/15 17:14:15 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "solve.h"
#include "tetri.h"

void	remouvecharmap(t_map *m, char c)
{
	int i;

	i = 0;
	while (i < m->currantsize)
	{
		ft_memrplchr(m->tab[i], c, '.', m->currantsize);
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
				solver(cmap, a, best);
				remouvecharmap(cmap, aplacer->letter);
				cmap->currantsize = oldsize;
			}
			cj++;
		}
		ci++;
	}
}

void	solver(t_map *tm, t_tetri *t, t_map *best)
{
	t_tetri	*cur;
	int		edit;

	cur = t;
	edit = 0;
	if (best->optofind++ > 250000)
		return ;
	if (tm->currantsize >= best->currantsize)
		return ;
	while (cur != NULL)
	{
		if (cur->use != 1)
		{
			cur->use = 1;
			edit = 1;
			try(tm, cur, t, best);
			cur->use = 0;
		}
		cur = cur->next;
	}
	if (edit == 0 && tm->currantsize < best->currantsize)
		cpymap(best, tm);
}
