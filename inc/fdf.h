/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:09:55 by cpollich          #+#    #+#             */
/*   Updated: 2019/10/07 18:24:24 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "math.h"
# include "libft.h"
# include <errno.h>
# include <stdio.h>

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
	int			color;
}				t_point;

typedef struct	s_coords
{
	int			z;
	int			color;
}				t_coords;

typedef struct	s_map
{
	t_coords	**coords;
	int			width;
	int			height;
}				t_map;

typedef struct	s_fdf
{
	void		*mlx;
	void		*win;
	t_map		*map;
}				t_fdf;

/*
**	Memory initialization
*/

t_map			*init_map();
t_fdf			*init_fdf(t_map *map);
t_coords		**coords_init(t_map *map);

void			draw_line(t_point s, t_point f, t_fdf *fdf);

int				parse_input(int fd, t_map *map);
void			error(char *str);


#endif