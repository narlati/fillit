/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narlati <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 17:05:27 by narlati           #+#    #+#             */
/*   Updated: 2016/11/15 17:05:29 by narlati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_tetri_map(char *s)
{
	int		i;

	i = 0;
	while (i < 20)
	{
		if ((s[i] == '.' || s[i] == '#') && (i % 5 != 4))
			i++;
		else if (s[i] == '\n' && (i % 5 == 4))
			i++;
		else
			return (0);
	}
	return (1);
}

static int	check_number_piece(char *s)
{
	int		i;
	int		piece;

	i = 0;
	piece = 0;
	while (i < 20)
	{
		if (s[i] == '#')
			piece++;
		i++;
	}
	if (piece != 4)
		return (0);
	return (1);
}

static int	check_tetri_viable(char *s)
{
	int		i;
	int		link;

	i = 0;
	link = 0;
	while (i < 20)
	{
		if (s[i] == '#')
			link += (s[i + 1] == '#') + (s[i + 5] == '#');
		i++;
	}
	if (link >= 3)
		return (1);
	return (0);
}

static int	check_tetri_form(char *s)
{
	if (check_number_piece(s) != 1)
		return (0);
	if (check_tetri_viable(s) != 1)
		return (0);
	return (1);
}

int			check_tetri(char *s)
{
	if (check_tetri_map(s) == 0)
		return (0);
	else
	{
		if (check_tetri_form(s) == 0)
			return (0);
	}
	return (1);
}
