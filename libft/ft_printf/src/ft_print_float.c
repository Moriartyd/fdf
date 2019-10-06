/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 17:10:15 by mbeahan           #+#    #+#             */
/*   Updated: 2019/09/03 20:43:24 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				str_len(t_string *s)
{
	return (s->size);
}

t_bignum		*big_num_create(void)
{
	t_bignum	*num;

	num = (t_bignum *)malloc(sizeof(t_bignum));
	num->int_part = str_create_size(5);
	num->frac_part = str_create_size(5);
	return (num);
}

t_bignum		*get_the_bits(long double arg)
{
	int			i;
	int			byte;
	t_bignum	*num;
	int			test;

	i = 63;
	num = big_num_create();
	t.d_num = (long double)arg;
	str_pushchar(num->int_part, (t.t_double.mantissa >> 63 & 1) + 48);
	byte = 0;
	test = t.t_double.sign >> 0 & 1;
	if ((t.t_double.sign >> 0 & 1) == 0)
		num->sign = '+';
	else
		num->sign = '-';
	while (--i >= 0)
	{
		byte = t.t_double.mantissa >> i & 1;
		str_pushchar(num->frac_part, byte + 48);
	}
	if (t.t_double.exponent - 16383 > 0)
		pos_pow(&num, t.t_double.exponent - 16383, bin_mult);
	else
		pos_pow(&num, t.t_double.exponent - 16383, bin_div);
	return (num);
}

int				default_float(t_token *list, double arg)
{
	char		sign;
	t_bignum	*num;
	char		*str;
	size_t		res;

	if ((list->flags & F_PLUS) == F_PLUS)
		list->flags = list->flags & ~F_SPACE;
	if (check_for_kostyl(arg))
		return (kostyl(arg, list));
	sign = '\0';
	if (list->precision == -1)
		list->precision = 6;
	num = get_the_bits((long double)arg);
	bin_to_dec(num);
	rround(&num, list->precision);
	str = put_bignum_strings_into_one(num, list);
	if (num->sign == '-' || (list->flags & F_PLUS) == F_PLUS)
		sign = num->sign;
	add_sign_float(sign, &str, list);
	width_insert(list, &str);
	res = ft_putstr(str);
	big_num_destroy(&num);
	num = NULL;
	ft_strdel(&str);
	return (res);
}

int				long_float(t_token *list, long double arg)
{
	char		sign;
	t_bignum	*num;
	char		*str;
	size_t		res;

	if (check_for_kostyl(arg))
		return (kostyl(arg, list));
	sign = '\0';
	if (list->precision == -1)
		list->precision = 6;
	num = get_the_bits(arg);
	bin_to_dec(num);
	rround(&num, list->precision);
	str = put_bignum_strings_into_one(num, list);
	if (num->sign == '-' || (list->flags & F_PLUS) == F_PLUS)
		sign = num->sign;
	add_sign_float(sign, &str, list);
	width_insert(list, &str);
	res = ft_putstr(str);
	big_num_destroy(&num);
	num = NULL;
	ft_strdel(&str);
	return (res);
}
