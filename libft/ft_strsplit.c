/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:40:15 by ndombre           #+#    #+#             */
/*   Updated: 2016/11/10 10:28:41 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*strdupchr(char const *str, int c)
{
	size_t		i;
	char		*ret;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	ret = ft_malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] != '\0' && str[i] != c)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

static char		**ft_strspliti_p2(char **ret, char const *s, char c)
{
	unsigned int	nb;
	unsigned int	i;
	int				isspechar;

	i = 0;
	nb = 0;
	isspechar = 1;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			if (isspechar == 1)
			{
				ret[nb++] = strdupchr(s + i, c);
			}
			isspechar = 0;
		}
		else
			isspechar = 1;
		i++;
	}
	return (ret);
}

static char		**ft_strsplit_p(char const *s, char c, unsigned int nb)
{
	char			**ret;

	ret = ft_malloc(sizeof(char*) * (nb + 1));
	if (ret == NULL)
		return (NULL);
	ret[nb] = 0;
	return (ft_strspliti_p2(ret, s, c));
}

char			**ft_strsplit(char const *s, char c)
{
	unsigned int	nb;
	unsigned int	i;
	int				isspechar;

	isspechar = 1;
	i = 0;
	nb = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			if (isspechar == 1)
				nb++;
			isspechar = 0;
		}
		else
			isspechar = 1;
		i++;
	}
	return (ft_strsplit_p(s, c, nb));
}
