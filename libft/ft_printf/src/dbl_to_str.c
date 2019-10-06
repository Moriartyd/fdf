/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_to_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 19:47:06 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/03 14:12:18 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*dbl_transform_if(t_doubled *d)
{
	char	*res;

	if (!(res = ft_nchjoinstr(d->mantissa, '0', -(d->exponent))))
		return (NULL);
	res[1] = '.';
	res[-(d->exponent) + 1] = '1';
	res[-(d->exponent)] = '0';
	free(d->mantissa);
	d->mantissa = res;
	return (res);
}

static char			*dbl_transform(t_doubled *d)
{
	int		l;
	char	*res;

	if (d->sign == 0 && d->exponent == -1023 && !ft_strcmp(d->mantissa, "1."))
	{
		free(d->mantissa);
		d->mantissa = ft_strdup("0.0");
	}
	else if (d->exponent < 0)
		dbl_transform_if(d);
	else if (d->exponent > 0)
	{
		if (!(res = ft_strjoinnch(d->mantissa, '0',
			d->exponent - ft_strlen(d->mantissa) + 3)))
			return (NULL);
		free(d->mantissa);
		d->mantissa = res;
		l = 1;
		while ((d->exponent)-- > 0)
		{
			res[l] = res[l + 1];
			res[l++ + 1] = '.';
		}
	}
	return (d->mantissa);
}

static t_doubled	*get_double(double d)
{
	unsigned long	*n;
	int				i;
	int				l;
	t_doubled		*res;

	n = (unsigned long *)&d;
	if (!(res = (t_doubled *)malloc(sizeof(t_doubled))))
		return (NULL);
	res->sign = d < 0;
	res->exponent = (((*n) << 1) >> 53) - 1023;
	i = 0;
	while (((*n) >> i & 1) != 1 && i < 52)
		++i;
	l = 52 - i;
	if (!(res->mantissa = ft_strnew(l + 2)))
	{
		free(res);
		return (NULL);
	}
	while (l + 1 > 0)
		res->mantissa[l-- + 1] = '0' + ((((*n) >> i++) & 1) == 1);
	res->mantissa[0] = '1';
	res->mantissa[1] = '.';
	return (res);
}

char				*dbl_to_str(double d)
{
	char		*res;
	char		*frac;
	char		*inte;
	t_doubled	*dbl;

	dbl = get_double(d);
	dbl_transform(dbl);
	inte = ft_copyuntil(dbl->mantissa, '.');
	frac = ft_strchr(dbl->mantissa, '.');
	res = get_int_from_bin(inte);
	ft_strdel(&inte);
	inte = res;
	res = get_frac_from_bin(frac);
	frac = res;
	res = ft_strjoin(inte, frac);
	ft_strdel(&inte);
	free(frac);
	free(dbl->mantissa);
	free(dbl);
	return (res);
}
