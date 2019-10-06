/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_adding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 19:58:32 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/03 17:05:39 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*str_add_fraction(char **s1, char *s2)
{
	int		l1;
	int		l2;
	int		prev;
	char	*res;

	if (!s1 || !s2 || !*s1)
		return (NULL);
	l1 = ft_strlen(*s1);
	l2 = ft_strlen(s2);
	if (!(res = ft_strdup(l1 > l2 ? *s1 : s2)))
		return (NULL);
	l1 = l1 > l2 ? l2 : l1;
	prev = 0;
	while (res[--l1] != '.')
	{
		res[l1] = (*s1)[l1] + s2[l1] - '0' + prev;
		if ((prev = res[l1] > '9'))
			res[l1] -= 10;
	}
	ft_strdel(s1);
	return (res);
}

char		*str_add_int(char **s1, char *s2, int flag)
{
	int		l1;
	int		l2;
	int		i;
	int		prev;
	char	*res;

	l1 = ft_strlen(*s1);
	l2 = ft_strlen(s2);
	i = l1 > l2 ? l1 : l2 + 1;
	res = ft_strnew(i);
	prev = 0;
	while (--i >= 0)
	{
		res[i] = ((--l1 >= 0) ? (*s1)[l1] : '0') +
			((--l2 >= 0) ? s2[l2] : '0') - '0' + prev;
		if ((prev = res[i] > '9'))
			res[i] -= 10;
	}
	if (prev && res[0] == 0)
		res[0] = '1';
	else if (res[0] == 0 || res[0] == '0')
		res = ft_strshift(&res, 1);
	if (flag)
		ft_strdel(s1);
	return (res);
}

static int	div_nb(int i, char *res)
{
	char	now;

	now = res[i];
	if (now == '1' || now == '3' || now == '5' || now == '7' || now == '9')
	{
		now--;
		res[i + 1] += 5;
	}
	if (now == '.')
		return (1);
	if (now != '0')
		now = (now - '0') / 2 + '0';
	res[i] = now;
	return (0);
}

char		*str_div2(char **str)
{
	char	*res;
	int		i;

	if (ft_strcmp(".0", *str) == 0)
	{
		free(*str);
		return (ft_strdup(".5"));
	}
	if (!(res = ft_strjoinch(str, '0')))
		return (NULL);
	i = ft_strlen(res) - 1;
	while (--i >= 0)
	{
		if (div_nb(i, res))
			break ;
	}
	free(*str);
	*str = res;
	return (res);
}
