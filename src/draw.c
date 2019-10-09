/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 21:17:24 by cpollich          #+#    #+#             */
/*   Updated: 2019/10/09 23:24:40 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		iso(double *x, double *y, double *z)
{
	int	prev_x;
	int	prev_y;

	prev_x = *x;
	prev_y = *y;

	*x = (prev_x - prev_y) * cos(0.523599);
	*y = -*z + (prev_x + prev_y) * sin(0.523599);
}

void		for_each(t_map *len
				, void (*f)(t_coords *s, t_coords *c))
{
	int	i;
	int	j;

	i = -1;
	while (++i < len->height)
	{
		j = -1;
		while (++j < len->width)
			(*f)(&len->s_c[i][j], &len->c_c[i][j]);
	}
}

static void	draw_pic(t_fdf *fdf)
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
			if (i + 1!= fdf->map->height)
				draw_line(arr[i][j], arr[i + 1][j], fdf);
		}
	}
}

void	multi(t_coords *s, t_coords *c)
{
	s->x = s->x * 1.1;
	s->y = s->y * 1.1;
}

void	set_coords_in_screen(t_coords *s, t_coords *c)
{
	c->x = 640 - s->x;
	c->y = 320 - s->y;
}

void	draw(t_fdf *fdf)
{
	for_each(fdf->map, set_coords_in_screen);
	draw_pic(fdf);
	for_each(fdf->map, multi);
	for_each(fdf->map, set_coords_in_screen);
	draw_pic(fdf);
}