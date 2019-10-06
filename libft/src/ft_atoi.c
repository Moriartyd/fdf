/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 16:58:52 by cpollich          #+#    #+#             */
/*   Updated: 2019/10/01 17:57:31 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	unsigned int	res;
	int				sign;
	int				i;

	res = 0;
	i = 0;
	sign = (str[0] == '-') ? -1 : 1;
	str[0] == '-' ? i++ : 0;
	while (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (res * 10 / 10 != res ||
			(res * 10 + str[i] - '0') % 10 != str[i] - '0')
			return (0);
		res = res * 10 + str[i] - '0';
		i++;
	}
	if ((res > 2147483648 && sign == -1) || (res > 2147483647 && sign == 1)
		|| (str[i] && str[i] < '0' && str[i] > '9'))
		return (0);
	return (sign * res);
}
