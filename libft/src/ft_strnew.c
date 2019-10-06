/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:00:53 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/10/01 20:09:08 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*array;
	size_t	check;

	check = 0;
	if (size == check - 1)
		return (NULL);
	array = ft_memalloc((size + 1) * sizeof(char));
	if (!array)
		return (NULL);
	return (array);
}
