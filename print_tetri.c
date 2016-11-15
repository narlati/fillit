/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 17:04:20 by ndombre           #+#    #+#             */
/*   Updated: 2016/11/15 17:04:22 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tetri.h"

void	printtetri(t_tetri *t)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ft_putchar(t->tab[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
