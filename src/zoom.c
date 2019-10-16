/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 20:06:38 by cpollich          #+#    #+#             */
/*   Updated: 2019/10/16 15:36:56 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	multi(t_coords *s, t_coords *c, t_coords *i, t_map *map)
{
	(void)c;
	(void)i;
	(void)map;
	s->x = s->x * 1.1;
	s->y = s->y * 1.1;
	s->z = s->z * 1.1;
}

void	unmulti(t_coords *s, t_coords *c, t_coords *i, t_map *map)
{
	(void)c;
	(void)i;
	(void)map;
	s->x = s->x / 1.1;
	s->y = s->y / 1.1;
	s->z = s->z / 1.1;
}

void	zoom_in(t_fdf *fdf)
{
	for_each(fdf->map, multi);
	if (fdf->map->camera == CAM_ISO)
	{
		for_each(fdf->map, iso);
		for_each(fdf->map, set_coords_in_screen_by_iso);
	}
	else if (fdf->map->camera == CAM_PARALLEL)
		for_each(fdf->map, set_coords_in_screen_by_conic);
}

void	zoom_out(t_fdf *fdf)
{
	for_each(fdf->map, unmulti);
	if (fdf->map->camera == CAM_ISO)
	{
		for_each(fdf->map, iso);
		for_each(fdf->map, set_coords_in_screen_by_iso);
	}
	else if (fdf->map->camera == CAM_PARALLEL)
		for_each(fdf->map, set_coords_in_screen_by_conic);
}

/*
**void	small_z(t_coords *s, t_coords *c, t_coords *i, t_map *map)
**{
**	s->z = s->z / 1.5;
**	i->z = i->z / 1.5;
**}
*/
