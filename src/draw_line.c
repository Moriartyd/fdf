/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:10:06 by cpollich          #+#    #+#             */
/*   Updated: 2019/10/07 16:10:07 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "colors.h"

void    draw_line(t_point s, t_point f, t_fdf *fdf)
{
	t_point	delta;
	t_point	sign;
	t_point	cur;
	int		deltae;
	int		error;

	delta.x = ft_abs(s.x - f.x);
	delta.y = ft_abs(s.y - f.y);
	sign.x = s.x < f.x ? 1 : -1;
	sign.y = s.y < f.y ? 1 : -1;
	deltae = delta.x - delta.y;
	cur = s;
	while (cur.x != f.x || cur.y != f.y)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, cur.x, cur.y, C_WHITE);
		if ((error = deltae * 2) > -delta.y)
		{
			deltae -= delta.y;
			cur.x += sign.x;
		}
		if (error < delta.x)
		{
			deltae += delta.x;
			cur.y += sign.y;
		}
	}
}