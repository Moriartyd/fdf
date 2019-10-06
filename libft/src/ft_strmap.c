/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 19:25:57 by cpollich          #+#    #+#             */
/*   Updated: 2019/05/16 20:58:43 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	len;
	char	*str_fresh;
	char	*tmp;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	str_fresh = (char *)malloc(sizeof(char) * (len + 1));
	if (str_fresh == NULL)
		return (NULL);
	tmp = str_fresh;
	while (*s)
	{
		*str_fresh = f(*s);
		str_fresh++;
		s++;
	}
	*str_fresh = 0;
	return (tmp);
}
