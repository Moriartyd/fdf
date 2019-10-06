/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 18:15:51 by cpollich          #+#    #+#             */
/*   Updated: 2019/05/16 20:57:33 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *src, size_t prev_size, size_t new_size)
{
	void	*res;

	if (!(res = ft_memalloc(new_size)))
		return (NULL);
	res = ft_memcpy(res, src, prev_size > new_size ? new_size : prev_size);
	free(src);
	return (res);
}
