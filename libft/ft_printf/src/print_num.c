/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 14:43:16 by cpollich          #+#    #+#             */
/*   Updated: 2019/07/24 18:34:33 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_pos(char *str, t_token *token)
{
	char	sign;
	char	*str_new;
	int		res;

	sign = '\0';
	res = 0;
	if ((token->flags & F_SPACE) == F_SPACE)
		sign = ' ';
	if ((token->flags & F_PLUS) == F_PLUS)
		sign = '+';
	if (((token->flags & F_ZERO) == F_ZERO) &&
		((token->flags & F_MINUS)) != F_MINUS)
	{
		sign != '\0' ? res += ft_putchar(sign) : (0);
		res += print_without_flag(str, token->width - (sign != '\0'), -1, '0');
	}
	else
	{
		str_new = ft_chjoinstr(sign, str);
		res += ((token->flags & F_MINUS) == F_MINUS) ?
			print_with_flag(str_new, token->width, -1, ' ') :
				print_without_flag(str_new, token->width, -1, ' ');
		ft_strdel(&str_new);
	}
	return (res);
}

static int	print_neg(char *str, t_token *token)
{
	int		res;

	res = 0;
	if (((token->flags & F_ZERO) == F_ZERO) &&
		((token->flags & F_MINUS) != F_MINUS))
	{
		res += ft_putchar('-');
		res += print_without_flag(str + 1, token->width - 1, -1, '0');
	}
	else
	{
		res += ((token->flags & F_MINUS) == F_MINUS) ?
			print_with_flag(str, token->width, -1, ' ') :
			print_without_flag(str, token->width, -1, ' ');
	}
	return (res);
}

static int	print_pos_prec(char *str, t_token *token)
{
	int		l;
	int		res;
	char	*temp;

	l = ft_strlen(str);
	if (str[l - 1] == '0' && token->precision == 0)
		return (print_pos("", token));
	token->flags = token->flags & (~F_ZERO);
	if (token->precision <= l)
		return (print_pos(str, token));
	temp = ft_nchjoinstr(str, '0', token->precision - l);
	res = print_pos(temp, token);
	ft_strdel(&temp);
	return (res);
}

static int	print_neg_prec(char *str, t_token *token)
{
	int		l;
	int		res;
	char	*temp;
	char	*temp1;

	token->flags = token->flags & (~F_ZERO);
	l = ft_strlen(str) - 1;
	if (token->precision <= l)
		return (print_neg(str, token));
	temp = ft_nchjoinstr(str + 1, '0', token->precision - l);
	temp1 = ft_chjoinstr('-', temp);
	res = print_neg(temp1, token);
	ft_strdel(&temp);
	ft_strdel(&temp1);
	return (res);
}

/*
**		SIGN:
**			1 - positive
**			0 - negative
*/

int			print_num(char *str, t_token *token, int sign)
{
	if (sign && token->precision == -1)
		return (print_pos(str, token));
	if (sign && token->precision != -1)
		return (print_pos_prec(str, token));
	if (!sign && token->precision != -1)
		return (print_neg_prec(str, token));
	return (print_neg(str, token));
}
