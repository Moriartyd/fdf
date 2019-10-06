/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_round.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 12:49:44 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/09/03 18:00:30 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*cust_strjoin_left(t_string *s1, char *s2)
{
	char		*new_str;
	size_t		i;
	size_t		j;
	size_t		len;

	if (!s1->size || !s2)
		return (0);
	len = ft_strlen(s2);
	new_str = ft_strnew(s1->size + len);
	if (!new_str)
		return (0);
	i = -1;
	j = -1;
	while (++i < (size_t)s1->size)
		*(new_str + i) = str_at(s1, i);
	while (++j < len)
		*(new_str + i++) = *(s2 + j);
	*(new_str + i) = '\0';
	return (new_str);
}

char		*put_bignum_strings_into_one(t_bignum *num, t_token *lst)
{
	char	*str;
	char	*temp;
	char	*temp2;
	char	*temp3;

	if (lst->precision == 0)
	{
		str = cust_strdup(num->int_part);
		if (((lst->flags & F_SHARP) == F_SHARP) && lst->precision == 0)
			str = ft_strjoinch(&str, '.');
	}
	else
	{
		temp = cust_strjoin_left(num->int_part, ".");
		temp2 = cust_strdup(num->frac_part);
		temp3 = ft_strsub(temp2, 0, lst->precision);
		str = ft_strjoin_free(temp, temp3, 3);
		ft_strdel(&temp2);
	}
	return (str);
}

void		put_zeros(int precision, t_string *str)
{
	if (precision > str->size)
		while (precision != str->size)
			str_pushchar(str, '0');
}

int			find_digit(t_string *s, int start)
{
	while (start < str_len(s))
		if (s->data[start++] > '0')
			return (1);
	return (0);
}

void		rround(t_bignum **num, int precision)
{
	t_bignum	*temp;
	char		save_sign;

	save_sign = (*num)->sign;
	put_zeros(precision, (*num)->frac_part);
	if (((*num)->frac_part->size > precision &&
		(*num)->frac_part->data[precision] <= '4') ||
			!find_digit((*num)->frac_part, precision + 1))
		return ;
	if (precision == 0)
	{
		(*num)->int_part->data[(*num)->int_part->size - 1]++;
		return ;
	}
	temp = big_num_create();
	str_pushchar(temp->int_part, '0');
	while (precision-- > 1)
		str_pushchar(temp->frac_part, '0');
	str_pushchar(temp->frac_part, '1');
	*num = dec_sum(*num, temp, 3);
	(*num)->sign = save_sign;
}
