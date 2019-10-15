/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_coords.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 19:50:33 by cpollich          #+#    #+#             */
/*   Updated: 2019/10/15 19:51:22 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_coords_in_screen_by_iso(t_coords *s,
			t_coords *c, t_coords *i, t_map *map)
{
	(void)s;
	c->x = (WIDTH / 2 - i->x) + map->lr;
	c->y = (HEIGHT / 2 - i->y) + map->updown;
	c->color = i->color;
}

void	set_coords_in_screen_by_conic(t_coords *s,
			t_coords *c, t_coords *i, t_map *map)
{
	(void)i;
	c->x = (WIDTH / 2 - s->x) + map->lr;
	c->y = (HEIGHT / 2 - s->y) + map->updown;
	c->color = s->color;
}
