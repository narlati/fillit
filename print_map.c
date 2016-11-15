/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 17:04:09 by ndombre           #+#    #+#             */
/*   Updated: 2016/11/15 17:04:12 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "map.h"

void	print_map(t_map *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < map->currantsize)
	{
		j = 0;
		while (j < map->currantsize)
		{
			ft_putchar(map->tab[i][j]);
			j++;
		}
		i++;
		ft_putchar('\n');
	}
}
