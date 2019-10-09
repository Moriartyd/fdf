/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 20:48:12 by cpollich          #+#    #+#             */
/*   Updated: 2019/10/09 22:27:04 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_map.h"
#include "fdf.h"

int		key_press(int key, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (key == K_ESC)
		exit(0);
	// else if (key == K_PLUS)
		// umnozh(fdf);
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