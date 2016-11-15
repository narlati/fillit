/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 11:20:04 by ndombre           #+#    #+#             */
/*   Updated: 2016/11/10 16:21:28 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "unistd.h"

#ifdef FT_LIBFT_DEBUG

int		ft_write(int fd, char const *s, size_t n)
{
	if (!(ft_strntest(s, ft_isprint, n) || ft_strntest(s, ft_isspace, n)))
		ft_puterrl("carracter non affichable afficher");
	if (fd == 0)
		ft_puterrl("le fd est 0 attention");
	return (write(fd, s, n));
}

#else

int		ft_write(int fd, char const *s, size_t n)
{
	return (write(fd, s, n));
}

#endif
