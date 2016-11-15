/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 17:05:24 by ndombre           #+#    #+#             */
/*   Updated: 2016/11/15 17:05:25 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRI_H
# define TETRI_H

# include "libft.h"

typedef struct	s_tetri
{
	struct s_tetri	*next;
	char			tab[4][4];
	int				use;
	char			letter;
}				t_tetri;

int				get_tetrit(int fd, t_tetri **t);
void			printtetri(t_tetri *t);
t_tetri			*make_tetri(char *t);
int				read_tetri(int fd, char *s);
int				check_tetri(char *s);
t_tetri			*normalise_tetri(t_tetri *t);
void			listdel(t_tetri *l);
void			listprint(t_tetri *t);
void			put_letter(t_tetri *t);

#endif
