/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:10:03 by cpollich          #+#    #+#             */
/*   Updated: 2019/10/07 18:39:44 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "key_map.h"
#include "colors.h"
#include "errors.h"

int	close_pls(int key, void *param)
{
	if (key == K_ESC)
		exit(0);
	return (0);
}

int	get_rows(char **av)
{
	int		fd;
	char	*line;
	int		rows;
	int		res;

	rows = 0;
	if ((fd = open(av[1], O_RDONLY)) < 0)
		error(E_MAP_READ);
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
			ft_printf("%2d", map->coords[i][j].z);
			if (j + 1 != map->width)
				ft_putstr(" ");
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

	if (ac == 2)
	{
		map = init_map();
		map->height = get_rows(av);
		map->coords = coords_init(map);
		fd = open(av[1], O_RDONLY);
		if (parse_input(fd, map) == -1)
			error(E_MAP_READ);
		fdf = init_fdf(map);
		print_c(fdf->map);
		// mlx_loop(fdf->mlx);
	}
	return (0);
}
