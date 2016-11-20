/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narlati <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 17:07:00 by narlati           #+#    #+#             */
/*   Updated: 2016/11/17 10:32:53 by narlati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_H
# define FT_MAP_H

# include "tetri.h"

typedef struct	s_map
{
	char			tab[26 * 4][26 * 4];
	int				currantsize;
	int				optofind;
}				t_map;

void			print_map(t_map *map);
t_map			*newmap(void);
t_map			*cpymap(t_map *dest, t_map *src);
t_map			*dupmap(t_map *src);
int				canput_tetri_in_map(t_map *m, t_tetri *t, int x, int y);
void			put_tetri_in_map(t_map *m, t_tetri *t, int x, int y);
void			remap(t_map *t);

#endif
