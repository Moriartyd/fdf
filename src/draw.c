/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 21:17:24 by cpollich          #+#    #+#             */
/*   Updated: 2019/10/10 19:30:01 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		iso(t_coords *s, t_coords *c)
{
	int		prev_x;
	int		prev_y;

	prev_x = s->x;
	prev_y = s->y;
	s->x = (prev_x - prev_y) * (-cos(0.523599));
	s->y = (s->z) + (prev_x + prev_y) * (-sin(0.523599));
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
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}

void	multi(t_coords *s, t_coords *c)
{
	s->x = s->x * 1.1;
	s->y = s->y * 1.1;
}

void	set_coords_in_screen(t_coords *s, t_coords *c)
{
	c->x = WIDTH / 2 - s->x;
	c->y = HEIGHT / 2 - s->y;
}

void	draw(t_fdf *fdf)
{
	for_each(fdf->map, iso);
	for_each(fdf->map, set_coords_in_screen);
	draw_pic(fdf);
	ft_bzero(fdf->data_addr, WIDTH * HEIGHT * sizeof(long int));
	// for_each(fdf->map, multi);
	// for_each(fdf->map, set_coords_in_screen);
	// mlx_clear_window(fdf->mlx, fdf->win);
	draw_pic(fdf);
}