/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 19:23:25 by vradchen          #+#    #+#             */
/*   Updated: 2018/05/15 19:23:26 by vradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	ft_part3(t_info *c)
{
	if (c->y == 0)
		c->flag = 0;
	ft_printf("%i %i\n", c->y, c->x);
	if (c->y == -1)
		return (0);
	return (1);
}

static int	ft_part2(char **map, char **p, t_info *c)
{
	int flag;

	flag = 0;
	c->py = 0;
	while (p[c->py] && flag < 2)
	{
		c->px = 0;
		while (p[c->py][c->px] && flag < 2)
		{
			if (p[c->py][c->px] != '.')
			{
				if (((c->mx + c->px) >= c->mw) || ((c->my + c->py) >= c->mh))
					flag = 2;
				else if (map[c->my + c->py][c->mx + c->px] == c->c)
					flag++;
				else if (map[c->my + c->py][c->mx + c->px] != '.')
					flag = 2;
			}
			c->px++;
		}
		c->py++;
	}
	return (flag);
}

int			ft_check(char **map, char **p, t_info *c)
{
	if (c->player == 1)
		c->c = 'O';
	c->my = 0;
	c->h = 0;
	c->len = 0;
	c->x = 0;
	c->y = 0;
	while (map[c->my])
	{
		c->mx = 0;
		while (map[c->my][c->mx])
		{
			if (ft_part2(map, p, c) == 1)
			{
				if (c->flag == 1)
					ft_roadtozero(p, c);
				else
					ft_closest(map, p, c);
			}
			c->mx++;
		}
		c->my++;
	}
	return (ft_part3(c));
}
