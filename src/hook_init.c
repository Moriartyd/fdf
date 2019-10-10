/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 20:48:12 by cpollich          #+#    #+#             */
/*   Updated: 2019/10/10 22:41:47 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_map.h"
#include "fdf.h"

void	big_z(t_coords *s, t_coords *c, t_coords *i)
{
	s->z = s->z + 1;
}

int		key_press(int key, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	ft_bzero(fdf->data_addr, WIDTH * HEIGHT * sizeof(int));
	if (key == K_ESC)
		exit(0);
	else if (key == K_PLUS || key == K_PLUS_NUM)
		zoom_in(fdf);
	else if (key == K_MINUS || key == K_MINUS_NUM)
		zoom_out(fdf);
	else if (key == K_I)
		fdf->map->camera = CAM_ISO;
	else if (key == K_P)
		fdf->map->camera = CAM_CONIC;
	else if (key == K_BOL)
	{
		for_each(fdf->map, big_z);
		for_each(fdf->map, iso);
	}
	draw(fdf);
	return (0);
}

int		close_fdf(void *param)
{
	(void)param;
	exit(0);
}

void	hook_init(t_fdf *fdf)
{
	mlx_hook(fdf->win, 2, 0L, key_press, fdf);
	mlx_hook(fdf->win, 17, 0L, close_fdf, fdf);
}
