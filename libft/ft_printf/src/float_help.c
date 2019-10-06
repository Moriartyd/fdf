/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 12:52:12 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/09/03 17:44:30 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bignum		*big_num_create_by_str(char sign, char *int_part,\
char *frac_part)
{
	t_bignum	*num;

	num = (t_bignum *)malloc(sizeof(t_bignum));
	num->sign = sign;
	num->int_part = str_create_str(int_part);
	num->frac_part = str_create_str(frac_part);
	return (num);
}

void			do_int_part(t_bignum *num)
{
	int			i;
	char		*str;
	t_bignum	*tmp;
	t_bignum	*sum;

	i = -1;
	sum = big_num_create_by_str('+', "0", "0");
	while (++i < num->int_part->size)
	{
		str = ft_strdup(&num->int_part->data[i]);
		str[1] = 0;
		tmp = big_num_create_by_str('+', str, "0");
		ft_strdel(&str);
		pos_pow(&tmp, num->int_part->size - i - 1, dec_mult);
		sum = dec_sum(sum, tmp, 3);
	}
	str_clean(&(num->int_part));
	str_push_cs(num->int_part, sum->int_part);
	big_num_destroy(&sum);
}

void			bin_to_dec(t_bignum *num)
{
	do_int_part(num);
	do_frac_part(num);
}

void			str_push_cs(t_string *l, t_string *r)
{
	int i;

	i = -1;
	while (++i < str_len(r))
		str_pushchar(l, str_at(r, i));
}

t_string		*str_cut(t_string *str, int start, int end)
{
	t_string	*new_str;

	new_str = str_create_size(10);
	start--;
	while (++start < end && start < str_len(str))
		str_pushchar(new_str, str_at(str, start));
	return (new_str);
}
