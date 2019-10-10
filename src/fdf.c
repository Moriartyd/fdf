/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:07:25 by cpollich          #+#    #+#             */
/*   Updated: 2019/10/10 22:41:37 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "errors.h"

t_fdf	*init_fdf(t_map *map)
{
	t_fdf	*res;

	if (!(res = (t_fdf *)malloc(sizeof(t_fdf))))
		error(E_INIT);
	res->map = map;
	res->mlx = mlx_init();
	if (!(res->win = mlx_new_window(res->mlx, WIDTH, HEIGHT, "fdf")))
		error(E_INIT);
	if (!(res->img = mlx_new_image(res->mlx, WIDTH, HEIGHT)))
		error(E_INIT);
	res->data_addr = mlx_get_data_addr(res->img, &res->bpp,
				&res->size_line, &res->endian);
	return (res);
}

t_map	*init_map(void)
{
	t_map	*res;

	if (!(res = (t_map *)malloc(sizeof(t_map))))
		error(E_INIT);
	res->s_c = NULL;
	res->c_c = NULL;
	res->height = 0;
	res->width = 0;
	res->camera = CAM_CONIC;
	return (res);
}

void	coords_init(t_map *map)
{
	t_coords	**s_c;
	t_coords	**c_c;
	t_coords	**iso_c;
	int			i;

	i = -1;
	if (!(s_c = (t_coords **)malloc(sizeof(t_coords *) * map->height)))
		error(E_INIT);
	if (!(c_c = (t_coords **)malloc(sizeof(t_coords *) * map->height)))
		error(E_INIT);
	if (!(iso_c = (t_coords **)malloc(sizeof(t_coords *) * map->height)))
		error(E_INIT);
	while (++i < map->height)
	{
		s_c[i] = NULL;
		c_c[i] = NULL;
		iso_c[i] = NULL;
	}
	map->s_c = s_c;
	map->c_c = c_c;
	map->iso_c = iso_c;
}
