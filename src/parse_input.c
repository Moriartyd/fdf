/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:15:47 by cpollich          #+#    #+#             */
/*   Updated: 2019/10/07 23:48:49 by cpollich         ###   ########.fr       */
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

static void	parse_line(char **line, t_map *map, int y)
{
	int	width;
	int	i;

	width = 0;
	i = -1;
	map->coords[y] = new_row(line, map);
	while (line[++i])
	{
		map->coords[y][i].z = ft_atoi(line[i]);
		if (!map->coords[y][i].z && *line[i] != '0')
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

	i = -1;
	while ((res = ft_gnl(fd, &line)) == 1)
	{
		if (!(coords_line = ft_strsplit(line, ' ')))
			error(E_MAP_READ);
		parse_line(coords_line, map, ++i);
		ft_doublestrdel(&coords_line);
		ft_strdel(&line);
	}
	return (res);
}