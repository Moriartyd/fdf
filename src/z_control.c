/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_control.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 01:09:53 by cpollich          #+#    #+#             */
/*   Updated: 2019/10/22 21:26:20 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "key_map.h"

static void	z_bol(t_coords *s, t_coords *c, t_coords *i, t_map *map)
{
	(void)c;
	(void)i;
	(void)map;
	s->z += 0.1 * s->z;
}

static void	z_men(t_coords *s, t_coords *c, t_coords *i, t_map *map)
{
	(void)c;
	(void)i;
	(void)map;
	s->z -= 0.1 * s->z;
}

void		z_control(t_fdf *fdf, int key)
{
	for_each(fdf->map, key == K_BOL ? z_men : z_bol);
}
