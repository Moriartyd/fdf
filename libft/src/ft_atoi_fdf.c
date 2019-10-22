/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_fdf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:51:32 by cpollich          #+#    #+#             */
/*   Updated: 2019/10/22 18:46:15 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_atoi_fdf(const char *s)
{
	int		i;
	int		res;
	int		pow;
	char	*str;

	i = 1;
	str = "0123456789ABCDEF";
	pow = 5;
	res = 0;
	while (s[++i])
	{
		res += pow * (ft_strchr(str, s[i]) - str);
		pow--;
	}
	return (res);
}
