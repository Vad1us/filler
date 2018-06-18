/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 16:43:16 by vradchen          #+#    #+#             */
/*   Updated: 2018/04/27 16:43:17 by vradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_info
{
	int			mw;
	int			mh;
	int			mx;
	int			my;
	int			px;
	int			py;
	int			pw;
	int			ph;
	int			player;
	char		c;
	int			len;
	int			x;
	int			y;
	int			h;
	int			flag;
}				t_info;

int				ft_check(char **map, char **p, t_info *c);
void			ft_roadtozero(char **p, t_info *c);
void			ft_closest(char **map, char **p, t_info *c);

#endif
