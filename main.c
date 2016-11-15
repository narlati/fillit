/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narlati <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 17:06:24 by narlati           #+#    #+#             */
/*   Updated: 2016/11/15 17:06:30 by narlati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <unistd.h>
#include "tetri.h"
#include "solve.h"
#include "map.h"

void	findsolve(t_tetri *t)
{
	t_map *tm;
	t_map *best;

	best = newmap();
	best->currantsize = 26 * 4;
	tm = newmap();
	solver(tm, t, best);
	print_map(best);
}

void	run(int fd)
{
	t_tetri *t;

	t = NULL;
	if (get_tetrit(fd, &t) != 1)
	{
		write(1, "error\n", sizeof("error\n"));
		return ;
	}
	put_letter(t);
	findsolve(t);
	listdel(t);
}

int		main(int nv, char **vv)
{
	int		fd;

	if (nv != 2 && nv != 1)
	{
		write(1, "usage: fillit [source_file]\n", 28);
		return (-1);
	}
	fd = 0;
	if (nv == 2)
	{
		if ((fd = open(vv[1], O_RDONLY)) == -1)
		{
			write(1, "error\n", sizeof("error\n"));
			return (-1);
		}
	}
	run(fd);
	if (fd != 0)
		close(fd);
	return (0);
}
