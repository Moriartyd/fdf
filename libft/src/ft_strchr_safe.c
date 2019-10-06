/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_safe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 18:24:15 by cpollich          #+#    #+#             */
/*   Updated: 2019/05/16 20:57:39 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr_safe(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*(unsigned char*)s != (unsigned char)c && *s)
		s++;
	if (*(unsigned char*)s != (unsigned char)c)
		return (NULL);
	else
		return ((char*)s);
}
