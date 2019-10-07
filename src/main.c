/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:10:03 by cpollich          #+#    #+#             */
/*   Updated: 2019/10/08 00:01:34 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "key_map.h"
#include "colors.h"
#include "errors.h"

int	get_rows(char **av)
{
	int		fd;
	char	*line;
	int		rows;
	int		res;

	rows = 0;
	if ((fd = open(av[1], O_RDONLY)) < 0)
		error(E_MAP);
	while ((res = ft_gnl(fd, &line)) == 1)
	{
		rows++;
		ft_strdel(&line);
	}
	if (res == -1)
		error(E_MAP_READ);
	close(fd);
	return (rows);
}

void	print_c(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			ft_printf("%5d", map->coords[i][j].z);
			j++;
		}
		ft_putstr("\n");
		i++;
	}
}

int	main(int ac, char **av)
{
	int			fd;
	t_map		*map;
	t_fdf		*fdf;

	errno = 0;
	if (ac == 2)
	{
		map = init_map();
		map->height = get_rows(av);
		map->coords = coords_init(map);
		fd = open(av[1], O_RDONLY);
		if (parse_input(fd, map) == -1)
			error(E_MAP_READ);
		fdf = init_fdf(map);
		mlx_loop(fdf->mlx);
	}
	error(E_USAGE);
	return (0);
}