/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doublematrixdel.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 19:19:17 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/23 20:08:44 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_doublematrixdel(int ***matrix, int size)
{
	int i;

	i = -1;
	if (!matrix || !*matrix)
		return (0);
	while (++i < size)
		free((*matrix)[i]);
	free(*matrix);
	*matrix = NULL;
	return (0);
}
