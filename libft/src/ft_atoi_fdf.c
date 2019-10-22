/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_fdf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:51:32 by cpollich          #+#    #+#             */
/*   Updated: 2019/10/22 21:34:46 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_atoi_fdf(const char *s)
{
	int		i;
	int		res[2];
	int		pow;

	i = 1;
	pow = 5;
	res[0] = 0;
	res[1] = 0;
	while (s[++i])
	{
		if (s[i] >= 'a' && s[i] <= 'f')
			res[1] = s[i] - 87;
		else if (s[i] >= 'A' && s[i] <= 'F')
			res[1] = s[i] - 55;
		else if (s[i] >= '0' && s[i] <= '9')
			res[1] = s[i] - '0';
		res[0] += ft_intpower(16, pow) * res[1];
		pow--;
	}
	return (res[0]);
}
