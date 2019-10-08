/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 21:17:24 by cpollich          #+#    #+#             */
/*   Updated: 2019/10/08 22:08:38 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	set_coords_by_center(t_coords **map, t_map *len, double a)
{
	int	i;
	int	j;

	i = -1;
	while (++i < len->height)
	{
		j = -1;
		while (++j < len->width)
		{
			map[i][j].x = 640 / 2 + j * a;
			map[i][j].y = 360 / 2 + i * a;
		}
	}
}

static void	draw_sharp(t_fdf *fdf)
{
	int			i;
	int			j;
	t_coords	**arr;

	arr = fdf->map->coords;
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

void	draw(t_fdf *fdf)
{
	double	a;

	a = fdf->map->height > fdf->map->width ? fdf->map->height : fdf->map->width;
	a = 360 / a;
	set_coords_by_center(fdf->map->coords, fdf->map, a);
	draw_sharp(fdf);
}