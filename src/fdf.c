/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:07:25 by cpollich          #+#    #+#             */
/*   Updated: 2019/10/07 18:38:27 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "errors.h"

t_fdf		*init_fdf(t_map *map)
{
	t_fdf   *res;

	if (!(res = (t_fdf *)malloc(sizeof(t_fdf))))
		error(E_MALLOC);
	res->map = map;
	res->mlx = NULL;
	res->win = NULL;
	return (res);
}

t_map		*init_map()
{
	t_map	*res;

	if (!(res = (t_map *)malloc(sizeof(t_map))))
		error(E_MALLOC);
	res->coords = NULL;
	res->height = 0;
	res->width = 0;
	return (res);
}

t_coords	**coords_init(t_map *map)
{
	t_coords	**res;
	int			i;

	i = -1;
	if (!(res = (t_coords **)malloc(sizeof(t_coords *) * map->height)))
		error(E_MALLOC);
	while (++i < map->height)
		res[i] = NULL;
	return (res);
}
