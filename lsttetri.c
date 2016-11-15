/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsttetri.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narlati <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 17:06:06 by narlati           #+#    #+#             */
/*   Updated: 2016/11/15 17:06:13 by narlati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetri.h"
#include <stdlib.h>
#include "libft.h"

void	listdel(t_tetri *l)
{
	if (l != NULL)
	{
		listdel(l->next);
		free(l);
	}
}

void	listprint(t_tetri *t)
{
	if (t == NULL)
		return ;
	ft_putchar('\n');
	ft_putnbr(t->use);
	ft_putchar('\n');
	printtetri(t);
	ft_putchar('\n');
	listprint(t->next);
}
