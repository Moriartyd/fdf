/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrows_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 01:09:53 by cpollich          #+#    #+#             */
/*   Updated: 2019/10/11 02:50:09 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "key_map.h"

void	arrow_control(t_fdf *fdf, int key)
{
	if (key == K_ARROW_RIGHT)
		fdf->map->lr += 5;
	if (key == K_ARROW_LEFT)
		fdf->map->lr -= 5;
	if (key == K_ARROW_UP)
		fdf->map->updown -= 5;
	if (key == K_ARROW_DOWN)
		fdf->map->updown += 5;
}