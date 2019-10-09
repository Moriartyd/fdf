/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:07:25 by cpollich          #+#    #+#             */
/*   Updated: 2019/10/09 23:05:16 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "errors.h"

t_fdf	*init_fdf(t_map *map)
{
	t_fdf   *res;

	if (!(res = (t_fdf *)malloc(sizeof(t_fdf))))
		error(E_MALLOC);
	res->map = map;
	res->mlx = mlx_init();;
	res->win = mlx_new_window(res->mlx, 1280, 720, "fdf");
	return (res);
}

t_map	*init_map()
{
	t_map	*res;

	if (!(res = (t_map *)malloc(sizeof(t_map))))
		error(E_MALLOC);
	res->s_c = NULL;
	res->c_c = NULL;
	res->height = 0;
	res->width = 0;
	return (res);
}

void	coords_init(t_map *map)
{
	t_coords	**s_c;
	t_coords	**c_c;
	int			i;

	i = -1;
	if (!(s_c = (t_coords **)malloc(sizeof(t_coords *) * map->height)))
		error(E_MALLOC);
	if (!(c_c = (t_coords **)malloc(sizeof(t_coords *) * map->height)))
		error(E_MALLOC);
	while (++i < map->height)
	{
		s_c[i] = NULL;
		c_c[i] = NULL;
	}
	map->s_c = s_c;
	map->c_c = c_c;
}
