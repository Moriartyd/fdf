/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 14:55:06 by cpollich          #+#    #+#             */
/*   Updated: 2019/05/16 20:56:37 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (!n)
		return (0);
	while (n && *(unsigned char*)s1 == *(unsigned char*)s2)
	{
		n--;
		s1++;
		s2++;
	}
	if (n)
		return (*(unsigned char*)s1 - *(unsigned char*)s2);
	else
		return (0);
}
