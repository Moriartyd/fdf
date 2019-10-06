/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_dec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 12:50:27 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/09/03 17:41:17 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bignum		*dec_div(t_bignum *n)
{
	t_bignum	*res;
	int			i;

	i = -1;
	res = big_num_create();
	res->sign = n->sign;
	if (n->int_part->data[0] == '1')
	{
		big_num_destroy(&res);
		res = big_num_create_by_str(n->sign, "0", "5");
		return (res);
	}
	str_pushchar(res->int_part, '0');
	while (++i < n->frac_part->size)
		if (i > 0)
			str_pushchar(res->frac_part, ((n->frac_part->data[i] - 48) +
				(n->frac_part->data[i - 1] - 48) % 2 * 10) / 2 + 48);
		else
			str_pushchar(res->frac_part, (n->frac_part->data[i] - 48) / 2 + 48);
	str_pushchar(res->frac_part, (n->frac_part->data[i - 1]));
	return (res);
}

void			do_frac_part(t_bignum *num)
{
	int			i;
	char		*str;
	t_bignum	*sum;
	t_bignum	*temp;

	i = -1;
	sum = big_num_create_by_str('+', "0", "0");
	while (++i < num->frac_part->size)
	{
		str = ft_strdup(num->frac_part->data + i);
		str[1] = 0;
		temp = big_num_create_by_str('+', str, "0");
		ft_strdel(&str);
		pos_pow(&temp, i + 1, dec_div);
		sum = dec_sum(sum, temp, 3);
	}
	str_clean(&(num->frac_part));
	str_push_cs(num->frac_part, sum->frac_part);
	big_num_destroy(&sum);
}

void			str_rev(t_string *s)
{
	int		i;
	char	tmp;

	i = 0;
	while (i * 2 < str_len(s))
	{
		tmp = s->data[i];
		s->data[i] = s->data[str_len(s) - i - 1];
		s->data[str_len(s) - i - 1] = tmp;
		++i;
	}
}

void			swap_comp_str(t_string *s1, t_string *s2)
{
	t_string	tmp;

	if (str_len(s1) < str_len(s2))
	{
		tmp = *s1;
		*s1 = *s2;
		*s2 = tmp;
	}
}

char			frac_dec_mult(t_string *n, t_string *res)
{
	int			i;
	char		rem;
	char		num_res;

	rem = 0;
	i = str_len(n) - 1;
	while (i >= 0)
	{
		num_res = (rem + (str_at(n, i) - '0') * 2) % 10 + '0';
		rem = (rem + ((str_at(n, i) - '0') * 2)) / 10;
		str_pushchar(res, num_res);
		--i;
	}
	str_rev(res);
	return (rem);
}
