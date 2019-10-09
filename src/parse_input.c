/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:15:47 by cpollich          #+#    #+#             */
/*   Updated: 2019/10/09 23:21:42 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "errors.h"

static t_coords	*new_row(char **line, t_map *map)
{
	int			w;
	t_coords	*res;

	w = map->width;
	if (!w)
		while (line[w])
			w++;
	if (!(res = (t_coords *)malloc(sizeof(t_coords) * w)) || !w)
		error(E_MALLOC);
	return (res);
}

static void	set_coords_by_center(t_coords **map, t_map *len, double a)
{
	int	i;
	int	j;
	int	midi;
	int	midj;

	i = -1;
	midi = len->height / 2;
	midj = len->width / 2;
	while (++i < len->height)
	{
		j = -1;
		while (++j < len->width)
		{
			map[i][j].x = -(midj - j) * a;
			map[i][j].y = -(midi - i) * a;
		}
	}
}

static void	parse_line(char **line, t_map *map, int y)
{
	int	width;
	int	i;

	width = 0;
	i = -1;
	map->s_c[y] = new_row(line, map);
	map->c_c[y] = new_row(line, map);
	while (line[++i])
	{
		map->s_c[y][i].z = ft_atoi(line[i]);
		map->c_c[y][i].z = map->s_c[y][i].z;
		map->s_c[y][i].y = y;
		map->c_c[y][i].y = y;
		map->s_c[y][i].x = i;
		map->c_c[y][i].x = i;
		if (!map->s_c[y][i].z && *line[i] != '0')
			error(E_MAP);
		width++;
	}
	if (!y)
		map->width = width;
	else if (map->width != width)
		error(E_MAP);
}

int			parse_input(int fd, t_map *map)
{
	char	*line;
	int		res;
	char	**coords_line;
	int		i;
	double	a;

	i = -1;
	while ((res = ft_gnl(fd, &line)) == 1)
	{
		if (!(coords_line = ft_strsplit(line, ' ')))
			error(E_MAP_READ);
		parse_line(coords_line, map, ++i);
		ft_doublestrdel(&coords_line);
		ft_strdel(&line);
	}
	a = map->height > map->width ? map->height : map->width;
	if (map->height >= map->width)
		a = 720 / (2 * a);
	else
		a = 1280 / (2 * a);
	set_coords_by_center(map->s_c, map, a);
	return (res);
}