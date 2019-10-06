/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 00:52:17 by moriarty          #+#    #+#             */
/*   Updated: 2019/05/16 20:59:32 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	int		i;
	char	*res;

	if (!s)
		return (NULL);
	start = 0;
	while (ft_iswhitespace(s[start]))
		start++;
	end = ft_strlen(s);
	while (ft_iswhitespace(s[--end]) && end >= start)
		;
	res = ft_strnew(end - start + 1);
	if (!res)
		return (NULL);
	i = -1;
	while (start <= end)
		res[++i] = s[start++];
	return (res);
}
