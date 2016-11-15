/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetri.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narlati <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 17:05:39 by narlati           #+#    #+#             */
/*   Updated: 2016/11/15 17:05:41 by narlati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetri.h"

void	push_tetri(t_tetri **t, t_tetri *new)
{
	t_tetri *tmp;

	if (*t == NULL)
	{
		*t = new;
		return ;
	}
	tmp = *t;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

int		get_tetrit(int fd, t_tetri **t)
{
	char	s[30];
	int		r;
	int		nb;

	nb = 0;
	ft_memset(s, '\0', 30);
	while ((r = read_tetri(fd, s)) == 21)
	{
		if (s[20] != '\n')
			return (0);
		if (check_tetri(s) != 1)
			return (0);
		push_tetri(t, make_tetri(s));
		nb++;
	}
	if (r != 20)
		return (0);
	if (check_tetri(s) != 1)
		return (0);
	push_tetri(t, make_tetri(s));
	return (nb < 26);
}
