/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 14:43:58 by cpollich          #+#    #+#             */
/*   Updated: 2019/08/01 17:22:00 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_dec(long long int n, t_token *token)
{
	char	*print;
	int		ret;

	if ((token->flags & F_H) == F_H)
		print = ft_ltoa_base((short)n, 10);
	else if ((token->flags & F_HH) == F_HH)
		print = ft_ltoa_base((char)n, 10);
	else if ((token->flags & F_L) == F_L)
		print = ft_ltoa_base((long)n, 10);
	else if ((token->flags & F_LL) == F_LL)
		print = ft_ltoa_base((long long)n, 10);
	else if ((token->flags & F_J) == F_J)
		print = ft_ltoa_base((intmax_t)n, 10);
	else if ((token->flags & F_Z) == F_Z)
		print = ft_ltoa_base((size_t)n, 10);
	else
		print = ft_ltoa_base((int)n, 10);
	if (!print)
		return (0);
	ret = print_num(print, token, print[0] != '-');
	ft_strdel(&print);
	return (ret);
}
