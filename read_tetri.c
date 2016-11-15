/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 17:04:56 by ndombre           #+#    #+#             */
/*   Updated: 2016/11/15 17:04:58 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int			read_tetri(int fd, char *s)
{
	int		ret;
	char	buffer;
	int		i;

	i = 0;
	while (i <= 20 && (ret = read(fd, &buffer, 1) != 0))
	{
		s[i++] = buffer;
	}
	s[i] = '\0';
	return (i);
}
