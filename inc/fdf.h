/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:09:55 by cpollich          #+#    #+#             */
/*   Updated: 2019/10/09 23:21:12 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "math.h"
# include "libft.h"
# include <errno.h>
# include <stdio.h>

typedef struct	s_coords
{
	double		x;
	double		y;
	double		z;
	int			color;
}				t_coords;

typedef struct	s_map
{
	t_coords	**s_c;
	t_coords	**c_c;
	int			width;
	int			height;
}				t_map;

typedef struct	s_fdf
{
	void		*mlx;
	void		*win;
	void		*img;
	t_map		*map;
}				t_fdf;

/*
**	Memory initialization
*/

t_map			*init_map();
t_fdf			*init_fdf(t_map *map);
void			coords_init(t_map *map);

void			draw_line(t_coords s, t_coords f, t_fdf *fdf);
void			draw(t_fdf *fdf);

int				parse_input(int fd, t_map *map);
void			error(char *str);

/*
**	KEYBOARD & MOUSE
*/

void			hook_init(t_fdf *fdf);
int				key_press(int key, void *param);
int				close_fdf(void *param);

#endif