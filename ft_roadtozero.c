/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_roadtozero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 19:26:06 by vradchen          #+#    #+#             */
/*   Updated: 2018/05/15 19:26:08 by vradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_roadtozero(char **p, t_info *c)
{
	int h;

	c->py = 0;
	while (p[c->py])
	{
		c->px = 0;
		while (p[c->py][c->px])
		{
			if (p[c->py][c->px] != '.')
			{
				h = c->mh - (c->py + c->my);
				if (c->h < h || c->h == -1)
				{
					c->h = h;
					c->x = c->mx;
					c->y = c->my;
					if (h == c->mh)
						c->flag = 0;
				}
			}
			c->px++;
		}
		c->py++;
	}
}
