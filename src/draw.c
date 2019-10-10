/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 21:17:24 by cpollich          #+#    #+#             */
/*   Updated: 2019/10/11 02:48:19 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso(t_coords *s, t_coords *c, t_coords *i, t_map *map)
{
	int	prev_x;
	int	prev_y;

	prev_x = s->x;
	prev_y = s->y;
	i->x = (prev_x - prev_y) * (-cos(0.523599));
	i->y = (s->z) + (prev_x + prev_y) * (-sin(0.523599));
}

void	for_each(t_map *len
				, void (*f)(t_coords *s, t_coords *c, t_coords *i, t_map *map))
{
	int	i;
	int	j;

	i = -1;
	while (++i < len->height)
	{
		j = -1;
		while (++j < len->width)
			(*f)(&len->s_c[i][j], &len->c_c[i][j]
				, &len->iso_c[i][j], len);
	}
}

void	draw_pic(t_fdf *fdf)
{
	int			i;
	int			j;
	t_coords	**arr;

	arr = fdf->map->c_c;
	i = -1;
	while (++i < fdf->map->height)
	{
		j = -1;
		while (++j < fdf->map->width)
		{
			if (j + 1 != fdf->map->width)
				draw_line(arr[i][j], arr[i][j + 1], fdf);
			if (i + 1 != fdf->map->height)
				draw_line(arr[i][j], arr[i + 1][j], fdf);
		}
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}

void	set_coords_in_screen_by_iso(t_coords *s, t_coords *c, t_coords *i, t_map *map)
{
	c->x = (WIDTH / 2 - i->x) + map->lr;
	c->y = (HEIGHT / 2 - i->y) + map->updown;
}

void	set_coords_in_screen_by_conic(t_coords *s, t_coords *c, t_coords *i, t_map *map)
{
	c->x = (WIDTH / 2 - s->x) + map->lr;
	c->y = (HEIGHT / 2 - s->y) + map->updown;
}

void	draw(t_fdf *fdf)
{
	for_each(fdf->map, iso);
	if (fdf->map->camera == CAM_ISO)
		for_each(fdf->map, set_coords_in_screen_by_iso);
	else if (fdf->map->camera == CAM_CONIC)
		for_each(fdf->map, set_coords_in_screen_by_conic);
	draw_pic(fdf);
}
