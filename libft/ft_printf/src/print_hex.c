/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 16:12:16 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/03 14:16:06 by cpollich         ###   ########.fr       */
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

static char		*ft_itoa_uhex(size_t num, char spec)
{
	char	*alpha;
	char	*res;
	int		len;

	if (num == 0)
		return (ft_strdup("0"));
	alpha = "0123456789abcdef";
	if (spec == S_BHEX)
		alpha = "0123456789ABCDEF";
	len = ft_num_len_base(num, 16);
	if (!(res = ft_strnew(len--)))
		return (NULL);
	while (num)
	{
		res[len--] = alpha[num % 16];
		num /= 16;
	}
	return (res);
}

static void		parsing(size_t num, t_token *token, char **str, int len)
{
	char	*tmp;

	if (token->precision > len)
	{
		tmp = ft_nchjoinstr(*str, '0', token->precision - len);
		free(*str);
		*str = tmp;
		token->flags = token->flags & (~F_ZERO);
	}
	if ((token->flags & F_ZERO) == F_ZERO && token->precision == -1
		&& num != 0 && (token->flags & F_MINUS) != F_MINUS)
	{
		tmp = ft_nchjoinstr(*str, '0', token->width - len -
			((token->flags & F_SHARP) == F_SHARP) * 2);
		ft_strdel(str);
		*str = tmp;
	}
	if ((token->flags & F_SHARP) == F_SHARP && num)
	{
		tmp = ft_strjoin_leak((token->spec == S_BHEX) ? "0X" : "0x", *str);
		free(*str);
		*str = tmp;
		token->flags = token->flags & (~F_ZERO);
	}
}

int				print_hex(size_t n, t_token *token)
{
	char	*str;
	int		res;

	token->flags = token->flags & (~F_PLUS);
	token->flags = token->flags & (~F_SPACE);
	if (n == 0 && token->precision == 0)
		return (print_num("", token, 1));
	if (!(str = ft_itoa_uhex(cast_to_flag(n, token), token->spec)))
		return (0);
	parsing(n, token, &str, ft_strlen(str));
	if (token->precision != -1 && (token->flags & F_ZERO) == F_ZERO)
		token->flags = token->flags & ~F_ZERO;
	token->precision = -1;
	res = print_num(str, token, 1);
	ft_strdel(&str);
	return (res);
}
