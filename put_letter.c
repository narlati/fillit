/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_letter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 17:04:41 by ndombre           #+#    #+#             */
/*   Updated: 2016/11/15 17:04:43 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetri.h"

static void	switch_letter(t_tetri *t, int *num_letter)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	t->letter = 65 + *num_letter;
	while (i < 5)
	{
		while (j < 5)
		{
			if (t->tab[i][j] == '#')
				t->tab[i][j] = t->letter;
			j++;
		}
		j = 0;
		i++;
	}
}

void		put_letter(t_tetri *t)
{
	int		i;

	i = 0;
	while (t != NULL)
	{
		switch_letter(t, &i);
		i++;
		t = t->next;
	}
}
