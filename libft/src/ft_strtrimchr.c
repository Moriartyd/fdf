/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimchr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 16:05:04 by cpollich          #+#    #+#             */
/*   Updated: 2019/05/16 20:59:35 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_char(const char s, char c)
{
	return ((s == c) ? (1) : (0));
}

char		*ft_strtrimchr(const char *s, char c)
{
	int		start;
	int		end;
	int		i;
	char	*res;

	if (!s)
		return (NULL);
	start = 0;
	while (is_char(s[start], c))
		start++;
	end = ft_strlen(s);
	while (is_char(s[--end], c) && end >= start)
		;
	res = ft_strnew(end - start + 1);
	if (!res)
		return (NULL);
	i = -1;
	while (start <= end)
		res[++i] = s[start++];
	return (res);
}
