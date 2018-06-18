/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 16:42:39 by vradchen          #+#    #+#             */
/*   Updated: 2018/04/27 16:42:40 by vradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		ft_initial(t_info *c)
{
	c->mw = 0;
	c->mh = 0;
	c->pw = 0;
	c->ph = 0;
	c->mx = 0;
	c->my = 0;
	c->px = 0;
	c->py = 0;
	c->player = 0;
	c->c = 'X';
	c->len = 0;
	c->y = 0;
	c->x = 0;
	c->h = -1;
}

static int		ft_part3(t_info *c, char *s, char **map)
{
	char	*s2;
	char	**p;
	int		i;

	get_next_line(0, &s);
	if (ft_strncmp(s, "Piece ", 6) == 0)
	{
		s2 = ft_strsub(s, 6, ft_strlen(s));
		c->ph = ft_atoi(s2);
		while (*s2 != ' ')
			s2++;
		c->pw = ft_atoi(s2);
	}
	p = (char **)malloc(sizeof(char *) * (c->ph + 1));
	i = 0;
	while (i < c->ph)
	{
		get_next_line(0, &s);
		p[i++] = s;
	}
	p[i] = NULL;
	if (ft_check(map, p, c) == 0)
		return (0);
	return (1);
}

static int		ft_part2(t_info *c, char *s)
{
	char	**map;
	char	*s2;
	int		i;

	if (ft_strncmp(s, "Plateau ", 8) == 0)
	{
		s2 = ft_strsub(s, 8, ft_strlen(s));
		c->mh = ft_atoi(s2);
		while (*s2 != ' ')
			s2++;
		c->mw = ft_atoi(s2);
	}
	get_next_line(0, &s);
	map = (char **)malloc(sizeof(char *) * (c->mh + 1));
	i = 0;
	while (i < c->mh)
	{
		get_next_line(0, &s);
		map[i++] = ft_strsub(s, 4, ft_strlen(s));
	}
	map[i] = NULL;
	return (ft_part3(c, s, map));
}

int				main(void)
{
	char	*s;
	t_info	c;

	ft_initial(&c);
	while (1)
	{
		get_next_line(0, &s);
		if (c.player == 0)
		{
			if (ft_strncmp(s, "$$$ exec p1", 11) == 0)
				c.player = 1;
			else if (ft_strncmp(s, "$$$ exec p2", 11) == 0)
			{
				c.flag = 1;
				c.player = 2;
			}
			get_next_line(0, &s);
		}
		if (c.player == 1)
			c.c = 'O';
		ft_part2(&c, s);
	}
	return (0);
}
