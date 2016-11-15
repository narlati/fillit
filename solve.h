/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 17:05:07 by ndombre           #+#    #+#             */
/*   Updated: 2016/11/15 17:05:09 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SOLVE_H
# define FT_SOLVE_H

# include "map.h"
# include "tetri.h"

void	solver(t_map *tm, t_tetri *t, t_map *best);

#endif
