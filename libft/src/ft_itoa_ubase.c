/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ubase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 20:47:25 by cpollich          #+#    #+#             */
/*   Updated: 2019/07/24 18:25:14 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_len_base(unsigned long long int num, int base)
{
	int i;

	i = 1;
	while ((num = num / base) != 0)
		i++;
	return (i);
}

char		*ft_itoa_ubase(size_t num, int base)
{
	size_t	n;
	int		i;
	char	*str;

	if (!num)
		return (ft_strdup("0"));
	i = ft_num_len_base(num, base);
	n = num;
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i] = '\0';
	while (n)
	{
		str[i - 1] = (n % base >= 10) ? n % base + 55 : n % base + '0';
		n /= base;
		i--;
	}
	return (str);
}
