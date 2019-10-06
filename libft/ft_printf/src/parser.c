/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 20:26:15 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/04 17:52:30 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		begin_flag(int c)
{
	if (c == '-')
		return (F_MINUS);
	if (c == '0')
		return (F_ZERO);
	if (c == '+')
		return (F_PLUS);
	if (c == '#')
		return (F_SHARP);
	if (c == ' ')
		return (F_SPACE);
	return (0);
}

static int		length_flag(const char *f, int *i)
{
	if ((f[*i] == 'h' && f[*i + 1] == 'h')
				|| (f[*i] == 'l' && f[*i + 1] == 'l'))
	{
		*i += 2;
		return (f[*i - 1] == 'h' ? F_HH : F_LL);
	}
	else if (f[*i] == 'h' || f[*i] == 'l' || f[*i] == 'j' || f[*i] == 'z' ||
		f[*i] == 'L')
	{
		*i += 1;
		if (f[*i - 1] == 'h')
			return (F_H);
		if (f[*i - 1] == 'l')
			return (F_L);
		if (f[*i - 1] == 'j')
			return (F_J);
		if (f[*i - 1] == 'z')
			return (F_Z);
		if (f[*i - 1] == 'L')
			return (F_BL);
	}
	return (0);
}

static int		parse_tok(const char *form, t_token *token)
{
	int	i;
	int	flag;

	i = 0;
	while (form[i] && (flag = begin_flag(form[i])))
	{
		token->flags = token->flags | flag;
		i++;
	}
	while (form[i] && ft_isdigit(form[i]))
	{
		token->width = token->width * 10 + form[i] - '0';
		i++;
	}
	if (form[i] == '.')
		while (form[++i] && ft_isdigit(form[i]))
			token->precision == -1 ? (token->precision = form[i] - '0') :
				(token->precision = token->precision * 10 + form[i] - '0');
	if (form[i - 1] == '.' && token->precision == -1)
		token->precision = 0;
	if ((flag = length_flag(form, &i)))
		token->flags = token->flags | flag;
	ft_strchr("diouxXscpf%", form[i]) ? token->spec = form[i] : (0);
	return (token->spec ? i : -1);
}

int				do_tok(const char *form, va_list vargs, int *i)
{
	t_token token;

	token.width = 0;
	token.precision = -1;
	token.flags = 0;
	*i += parse_tok(form, &token) + 1;
	if (token.spec == S_CHAR)
		return (print_char(va_arg(vargs, int), &token));
	else if (token.spec == S_STRING)
		return (print_string(va_arg(vargs, char *), &token));
	else if (token.spec == S_PERCENT)
		return (print_char('%', &token));
	else if (token.spec == S_DECIMAL || token.spec == S_INTEGER)
		return (print_dec(va_arg(vargs, long long int), &token));
	else if (token.spec == S_POINTER)
		return (print_pointer(va_arg(vargs, unsigned long long int), &token));
	else if (token.spec == S_OCTAL)
		return (print_octal(va_arg(vargs, unsigned long int), &token));
	else if (token.spec == S_HEX || token.spec == S_BHEX)
		return (print_hex(va_arg(vargs, unsigned long int), &token));
	else if (token.spec == S_UNSIGNED)
		return (print_unsigned(va_arg(vargs, unsigned long long int), &token));
	else if (token.spec == S_FLOAT)
		return (parce_tok_float(token, vargs));
	return (0);
}

int				parce_tok_float(t_token token, va_list vargs)
{
	int	res;

	if (token.spec == S_FLOAT)
	{
		if ((token.flags & F_BL) == F_BL)
			res = long_float(&token, va_arg(vargs, long double));
		else
			res = default_float(&token, va_arg(vargs, double));
		return (res);
	}
	return (0);
}
