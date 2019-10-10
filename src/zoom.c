/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 20:06:38 by cpollich          #+#    #+#             */
/*   Updated: 2019/10/10 21:25:26 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	multi(t_coords *s, t_coords *c, t_coords *i)
{
	s->x = s->x * 1.1;
	s->y = s->y * 1.1;
}

void	unmulti(t_coords *s, t_coords *c, t_coords *i)
{
	s->x = s->x / 1.1;
	s->y = s->y / 1.1;
}

void	zoom_in(t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx, fdf->win);
	ft_bzero(fdf->data_addr, WIDTH * HEIGHT * sizeof(long int));
	for_each(fdf->map, multi);
	if (fdf->map->camera == CAM_ISO)
	{
		for_each(fdf->map, iso);
		for_each(fdf->map, set_coords_in_screen_by_iso);
	}
	else if (fdf->map->camera == CAM_CONIC)
		for_each(fdf->map, set_coords_in_screen_by_conic);
}

void	zoom_out(t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx, fdf->win);
	ft_bzero(fdf->data_addr, WIDTH * HEIGHT * sizeof(long int));
	for_each(fdf->map, unmulti);
	if (fdf->map->camera == CAM_ISO)
	{
		for_each(fdf->map, iso);
		for_each(fdf->map, set_coords_in_screen_by_iso);
	}
	else if (fdf->map->camera == CAM_CONIC)
		for_each(fdf->map, set_coords_in_screen_by_conic);
}
