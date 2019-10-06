/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 18:04:39 by cpollich          #+#    #+#             */
/*   Updated: 2019/05/16 20:58:29 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_size;
	size_t	dst_size;
	char	*dst_tmp;
	size_t	tmp;

	tmp = size;
	dst_tmp = dst;
	src_size = ft_strlen(src);
	while (*dst && tmp--)
		dst++;
	dst_size = dst - dst_tmp;
	tmp = size - dst_size;
	if (!tmp)
		return (dst_size + src_size);
	while ((tmp - 1) && *src)
	{
		*dst = *src;
		tmp--;
		dst++;
		src++;
	}
	*dst = '\0';
	return (dst_size + src_size);
}
