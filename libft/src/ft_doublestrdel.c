/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doublestrdel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 20:49:34 by cpollich          #+#    #+#             */
/*   Updated: 2019/08/28 20:07:39 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_doublestrdel(char ***matrix)
{
	int i;

	i = -1;
	if (!matrix || !*matrix)
		return (0);
	while ((*matrix)[++i])
		free((*matrix)[i]);
	free(*matrix);
	*matrix = NULL;
	return (0);
}
