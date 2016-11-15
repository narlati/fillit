/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalise_tetri.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narlati <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 17:07:18 by narlati           #+#    #+#             */
/*   Updated: 2016/11/15 17:07:21 by narlati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetri.h"

static int	normalise_tetri_top(t_tetri *t)
{
	int i;

	i = 0;
	while (i < 4)
		if (t->tab[0][i++] != '.')
			return (0);
	i = 0;
	while (i < 3)
	{
		t->tab[i][0] = t->tab[i + 1][0];
		t->tab[i][1] = t->tab[i + 1][1];
		t->tab[i][2] = t->tab[i + 1][2];
		t->tab[i][3] = t->tab[i + 1][3];
		i++;
	}
	i = 0;
	while (i < 4)
		t->tab[3][i++] = '.';
	return (1);
}

static int	normalise_tetri_right(t_tetri *t)
{
	int i;

	i = 0;
	while (i < 4)
		if (t->tab[i++][0] != '.')
			return (0);
	i = 0;
	while (i < 3)
	{
		t->tab[0][i] = t->tab[0][i + 1];
		t->tab[1][i] = t->tab[1][i + 1];
		t->tab[2][i] = t->tab[2][i + 1];
		t->tab[3][i] = t->tab[3][i + 1];
		i++;
	}
	i = 0;
	while (i < 4)
		t->tab[i++][3] = '.';
	return (1);
}

t_tetri		*normalise_tetri(t_tetri *t)
{
	while (1)
	{
		if (normalise_tetri_top(t))
			;
		else if (normalise_tetri_right(t))
			;
		else
			return (t);
	}
}
