/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 18:25:50 by cpollich          #+#    #+#             */
/*   Updated: 2019/08/01 17:27:15 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_len_base(long long int num, int base)
{
	int i;

	i = (num < 0) ? 2 : 1;
	while ((num = num / base) != 0)
		i++;
	return (i);
}

char		*ft_ltoa_base(long long int n, int base)
{
	char			*hex;
	int				i;
	int				l;
	char			*res;

	if (n == (-9223372036854775807 - 1) && base == 10)
		return (ft_strdup("-9223372036854775808"));
	if (n == 0)
		return (ft_strdup("0"));
	i = 0;
	hex = "0123456789abcdef";
	l = ft_num_len_base(n > 0 ? n : -n, base) + ((n < 0 && base == 10) ? 1 : 0);
	if (!(res = ft_strnew(l)))
		return (NULL);
	(n < 0 && base == 10) ? res[i++] = '-' : (0);
	n < 0 ? n *= -1 : (0);
	while (n)
	{
		res[--l] = hex[n % base];
		n /= base;
	}
	return (res);
}
