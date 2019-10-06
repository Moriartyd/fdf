/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 14:21:59 by cpollich          #+#    #+#             */
/*   Updated: 2019/05/16 20:55:55 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digits_num(int n)
{
	int num;

	num = 1;
	while (n / 10)
	{
		n = n / 10;
		num++;
	}
	return (num);
}

static void	fill_array(int n, char *array, int len)
{
	array[len] = '\0';
	if (n < 0)
	{
		array[0] = '-';
		if (n == -2147483648)
		{
			array[1] = '2';
			n = -147483648;
		}
		n = -n;
	}
	if (!n)
		array[--len] = '0';
	while (n)
	{
		len--;
		array[len] = 48 + (n % 10);
		n = n / 10;
	}
}

char		*ft_itoa(int n)
{
	char	*array;
	int		len;

	if (n < 0)
	{
		len = 1 + digits_num(n);
		array = (char*)malloc(sizeof(char) * (len + 1));
	}
	else
	{
		len = digits_num(n);
		array = (char*)malloc(sizeof(char) * (len + 1));
	}
	if (array == NULL)
		return (NULL);
	fill_array(n, array, len);
	return (array);
}
