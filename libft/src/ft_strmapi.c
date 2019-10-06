/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 19:36:41 by cpollich          #+#    #+#             */
/*   Updated: 2019/05/16 20:58:48 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			len;
	char			*str_fresh;
	char			*tmp;
	unsigned int	index;

	index = 0;
	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	str_fresh = (char *)malloc(sizeof(char) * (len + 1));
	if (str_fresh == NULL)
		return (NULL);
	tmp = str_fresh;
	while (*s)
	{
		*str_fresh = f(index, *s);
		str_fresh++;
		s++;
		index++;
	}
	*str_fresh = 0;
	return (tmp);
}
