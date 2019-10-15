/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:09:55 by cpollich          #+#    #+#             */
/*   Updated: 2019/10/15 20:43:14 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "math.h"
# include "libft.h"
# include <errno.h>
# include <stdio.h>

# define CAM_ISO 1
# define CAM_PARALLEL 2
# define WIDTH	1000
# define HEIGHT	1000

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
}				t_point;

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
	t_coords	**iso_c;
	int			width;
	int			height;
	int			camera;
	int			updown;
	int			lr;
	int			color;
}				t_map;

typedef struct	s_fdf
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data_addr;
	int			bpp;
	int			size_line;
	int			endian;
	int			color;
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
void			draw_pic(t_fdf *fdf);

int				parse_input(int fd, t_map *map);
void			error(char *str);

void			for_each(t_map *len
					, void (*f)(t_coords *s, t_coords *c,
							t_coords *i, t_map *map));
void			set_coords_in_screen_by_iso(t_coords *s,
					t_coords *c, t_coords *i, t_map *map);
void			set_coords_in_screen_by_conic(t_coords *s,
					t_coords *c, t_coords *i, t_map *map);
void			zoom_in(t_fdf *fdf);
void			zoom_out(t_fdf *fdf);
void			iso(t_coords *s, t_coords *c, t_coords *i, t_map *map);

/*
**	KEYBOARD & MOUSE
*/

void			hook_init(t_fdf *fdf);
int				key_press(int key, void *param);
int				close_fdf(void *param);

void			arrow_control(t_fdf *fdf, int key);
void			z_control(t_fdf *fdf, int key);

void			print_c(t_map *map, t_coords **arr);

int				get_color(t_coords current, t_coords start,
						t_coords end, t_point delta);

#endif
