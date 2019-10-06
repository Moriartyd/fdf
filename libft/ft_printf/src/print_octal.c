/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 16:11:30 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/03 14:16:14 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_num_len_base(size_t num, int base)
{
	int i;

	i = 1;
	while ((num = num / base) != 0)
		i++;
	return (i);
}

static char		*ft_itoa_uoct(size_t num)
{
	char	*alpha;
	char	*res;
	int		len;

	if (num == 0)
		return (ft_strdup("0"));
	alpha = "01234567";
	len = ft_num_len_base(num, 8);
	if (!(res = ft_strnew(len--)))
		return (NULL);
	while (num)
	{
		res[len--] = alpha[num % 8];
		num /= 8;
	}
	return (res);
}

int				print_octal(size_t n, t_token *token)
{
	int		res;
	char	*str;

	token->flags = token->flags & (~F_PLUS);
	token->flags = token->flags & (~F_SPACE);
	if (!(str = ft_itoa_uoct(cast_to_flag(n, token))))
		return (0);
	if ((token->flags & F_SHARP) == F_SHARP)
	{
		(n == 0 && token->precision == 0) ? token->precision = -1 : 0;
		if (n == 0)
			res = print_num("0", token, 1);
		else
		{
			str = ft_chjoinstr('0', str);
			res = print_num(str, token, 1);
		}
	}
	else
		res = print_num(str, token, 1);
	ft_strdel(&str);
	return (res);
}
