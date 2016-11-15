/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:07:45 by ndombre           #+#    #+#             */
/*   Updated: 2016/11/10 10:23:55 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_itoa_nb(int n)
{
	size_t i;

	i = 1;
	if (n < 0)
		i++;
	if (n == 0)
		i++;
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static int		ft_itoa_r(char *tab, int n)
{
	unsigned int	nu;
	int				i;

	if (n < 0)
	{
		*tab++ = '-';
		nu = -n;
	}
	else
		nu = n;
	i = 0;
	if (nu >= 10)
		i = ft_itoa_r(tab, nu / 10);
	tab[i] = (nu % 10) + '0';
	return (i + 1);
}

char			*ft_itoa(int n)
{
	char *ret;

	ret = ft_malloc(sizeof(char) * (ft_itoa_nb(n)));
	if (ret == NULL)
		return (NULL);
	ft_bzero(ret, ft_itoa_nb(n) + 5);
	ft_itoa_r(ret, n);
	return (ret);
}
