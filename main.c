/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narlati <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 17:06:24 by narlati           #+#    #+#             */
/*   Updated: 2016/11/20 15:26:03 by narlati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <unistd.h>
#include "tetri.h"
#include "solve.h"
#include "map.h"
#include <stdlib.h>

void	findsolve(t_tetri *t)
{
	t_map	*tm;
	t_map	*best;

	best = newmap();
	tm = newmap();
	best->currantsize = 26 * 4;
	solver(tm, t, best);
	print_map(best);
	free(tm);
	free(best);
}

void	run(int fd)
{
	t_tetri *t;

	t = NULL;
	if (get_tetrit(fd, &t) != 1)
	{
		listdel(t);
		write(1, "error\n", 6);
		return ;
	}
	put_letter(t);
	findsolve(t);
	listdel(t);
}

int		main(int nv, char **vv)
{
	int		fd;

	if (nv != 2)
	{
		write(1, "usage: fillit [source_file]\n", 28);
		return (-1);
	}
	fd = 0;
	if ((fd = open(vv[1], O_RDONLY)) == -1)
	{
		write(1, "error\n", 6);
		return (-1);
	}
	run(fd);
	if (fd != 0)
		close(fd);
	return (0);
}
