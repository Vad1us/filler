/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_closest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 19:26:45 by vradchen          #+#    #+#             */
/*   Updated: 2018/05/15 19:26:46 by vradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	ft_abs(int x, int y, t_info *c)
{
	int a;
	int b;

	a = y - (c->py + c->my);
	if (a < 0)
		a = -a;
	b = x - (c->px + c->mx);
	if (b < 0)
		b = -b;
	return (a + b);
}

static void	ft_part2(char **map, t_info *c)
{
	int y;
	int x;
	int len;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != '.' && map[y][x] != c->c)
			{
				len = ft_abs(x, y, c);
				if (c->len >= len || c->len == 0)
				{
					c->len = len;
					c->x = c->mx;
					c->y = c->my;
				}
			}
			x++;
		}
		y++;
	}
}

void		ft_closest(char **map, char **p, t_info *c)
{
	c->py = 0;
	while (p[c->py])
	{
		c->px = 0;
		while (p[c->py][c->px])
		{
			if (p[c->py][c->px] != '.')
			{
				ft_part2(map, c);
			}
			c->px++;
		}
		c->py++;
	}
}
