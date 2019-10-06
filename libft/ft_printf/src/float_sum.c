/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_sum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 12:51:17 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/09/03 17:04:58 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				int_sum(t_string *l, t_string *r, t_string *res, char rem)
{
	int				i;
	int				j;
	char			num_res;

	j = 0;
	swap_comp_str(l, r);
	i = str_len(l) - 1;
	j = str_len(r);
	while (--j >= 0)
	{
		num_res = (rem + (str_at(l, i) + str_at(r, j) - 2 * '0')) % 10 + '0';
		rem = (rem + str_at(l, i) + str_at(r, j) - 2 * '0') / 10;
		str_pushchar(res, num_res);
		--i;
	}
	while (i >= 0)
	{
		num_res = (rem + (str_at(l, i) - '0')) % 10 + '0';
		rem = (rem + str_at(l, i) - '0') / 10;
		str_pushchar(res, num_res);
		--i;
	}
	if (rem > 0)
		str_pushchar(res, rem + '0');
	str_rev(res);
}

char				frac_sum(t_string *l, t_string *r, t_string *res)
{
	int				i;
	char			rem;
	char			num_res;

	rem = 0;
	swap_comp_str(l, r);
	i = str_len(l);
	while (--i >= str_len(r))
		str_pushchar(res, str_at(l, i));
	while (i >= 0)
	{
		num_res = (rem + (str_at(l, i) - '0' +
							str_at(r, i) - '0')) % 10 + '0';
		rem = (rem + str_at(l, i) + str_at(r, i) - 2 * '0') / 10;
		str_pushchar(res, num_res);
		--i;
	}
	str_rev(res);
	return (rem);
}

t_bignum			*dec_mult(t_bignum *n)
{
	t_bignum	*res;
	char		rem;

	res = big_num_create();
	res->sign = n->sign;
	rem = frac_dec_mult(n->frac_part, res->frac_part);
	int_dec_mult(n->int_part, res->int_part, rem);
	return (res);
}

t_bignum			*dec_sum(t_bignum *l, t_bignum *r, int n)
{
	t_bignum		*res;
	char			rem;

	res = big_num_create();
	res->sign = l->sign;
	rem = frac_sum(l->frac_part, r->frac_part, res->frac_part);
	int_sum(l->int_part, r->int_part, res->int_part, rem);
	if (n == 1)
		big_num_destroy(&l);
	else if (n == 2)
		big_num_destroy(&r);
	else if (n == 3)
	{
		big_num_destroy(&l);
		big_num_destroy(&r);
	}
	return (res);
}

t_string			*str_create_str(char *s)
{
	t_string	*str;
	int			len;
	int			i;

	if (!(str = (t_string *)malloc(sizeof(t_string))))
		return (NULL);
	i = -1;
	len = ft_strlen(s);
	str->data = (char *)malloc(sizeof(char) * len * 3 / 2);
	str->size = len;
	str->capacity = len * 3 / 2;
	while (++i < len)
		str->data[i] = s[i];
	return (str);
}
