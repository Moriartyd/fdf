/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:10:06 by cpollich          #+#    #+#             */
/*   Updated: 2019/10/10 19:36:01 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "colors.h"

static void	put_pixel(t_fdf *fdf, int x, int y, int color)
{
	int	a;

	if (y > 0 && y < HEIGHT && x > 0 && x < WIDTH)
	{
		a = (y * fdf->size_line) + (x * fdf->bpp / 8);
		fdf->data_addr[a] = color;
		fdf->data_addr[++a] = color >> 8;
		fdf->data_addr[++a] = color >> 16;
		fdf->data_addr[++a] = 0;
	}
}

static int	check_it(t_coords sign, t_coords cur, t_coords fin)
{
	if (sign.x > 0 && sign.y > 0)
		return ((int)cur.x < (int)fin.x || (int)cur.y < (int)fin.y);
	else if (sign.x < 0 && sign.y > 0)
		return ((int)cur.x > (int)fin.x || (int)cur.y < (int)fin.y);
	else if (sign.x < 0 && sign.y < 0)
		return ((int)cur.x > (int)fin.x || (int)cur.y > (int)fin.y);
	else if (sign.x > 0 && sign.y < 0)
		return ((int)cur.x < (int)fin.x || (int)cur.y > (int)fin.y);
	else
		return (0);
}

void    	draw_line(t_coords s, t_coords f, t_fdf *fdf)
{
	t_coords	delta;
	t_coords	sign;
	t_coords	cur;
	int			deltae;
	int			error;

	delta.x = ft_abs(s.x - f.x);
	delta.y = ft_abs(s.y - f.y);
	sign.x = s.x < f.x ? 1 : -1;
	sign.y = s.y < f.y ? 1 : -1;
	deltae = delta.x - delta.y;
	cur = s;
	while (check_it(sign, cur, f))
	{
		put_pixel(fdf, (int)cur.x, (int)cur.y, C_WHITE);
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
