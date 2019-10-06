/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 12:46:47 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/08/01 17:18:44 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		int_dec_mult(t_string *n, t_string *res, char rem)
{
	int			i;
	int			j;
	char		num_res;

	j = 0;
	i = str_len(n);
	while (--i >= 0)
	{
		num_res = (rem + (str_at(n, i) - 48) * 2) % 10 + '0';
		rem = (rem + (str_at(n, i) - 48) * 2) / 10;
		str_pushchar(res, num_res);
	}
	if (rem > 0)
		str_pushchar(res, rem + '0');
	str_rev(res);
}

char		del_minus(char **str)
{
	int		i;
	int		len;
	char	sign;

	sign = **str;
	i = -1;
	len = ft_strlen(*str) - 1;
	while (++i < len)
		(*str)[i] = (*str)[i + 1];
	(*str)[i] = 0;
	return (sign);
}

void		width_insert_right(char **new_str, char *substr, int width, char c)
{
	int		i;
	char	sign;

	i = 0;
	if (*substr && c == '0' && (*substr == '-' ||\
	*substr == '+' || *substr == ' '))
		sign = del_minus(&substr);
	while (*substr)
		(*new_str)[i++] = *substr++;
	while (width-- > 0)
		(*new_str)[i++] = c;
	if (c == '0' && sign != -1)
	{
		add_sign(new_str, sign);
		i++;
	}
	(*new_str)[i] = '\0';
}

void		width_insert_left(char **new_str, char *substr, int width, char c)
{
	int		i;
	char	sign;

	i = 0;
	sign = -1;
	if (*substr && c == '0' && (*substr == '-' || *substr == '+' ||
													*substr == ' '))
		sign = del_minus(&substr);
	while (width-- > 0)
		(*new_str)[i++] = c;
	while (*substr)
		(*new_str)[i++] = *substr++;
	if (c == '0' && sign != -1)
	{
		add_sign(new_str, sign);
		i++;
	}
	(*new_str)[i] = '\0';
}
