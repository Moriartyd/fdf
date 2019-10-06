/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 15:32:01 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/07/24 18:34:10 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_unsigned(unsigned long long int u, t_token *token)
{
	char	*nbr;
	int		res;

	token->flags = token->flags & (~F_SPACE);
	token->flags = token->flags & (~F_PLUS);
	if ((token->flags & F_L) == F_L)
		nbr = ft_itoa_ubase((unsigned long)u, 10);
	else if ((token->flags & F_LL) == F_LL)
		nbr = ft_itoa_ubase(u, 10);
	else if ((token->flags & F_H) == F_H)
		nbr = ft_itoa_ubase((unsigned short)u, 10);
	else if ((token->flags & F_HH) == F_HH)
		nbr = ft_itoa_ubase((unsigned char)u, 10);
	else if ((token->flags & F_J) == F_J)
		nbr = ft_itoa_ubase((intmax_t)u, 10);
	else if ((token->flags & F_Z) == F_Z)
		nbr = ft_itoa_ubase((size_t)u, 10);
	else
		nbr = ft_itoa_ubase((unsigned int)u, 10);
	if (!nbr)
		return (0);
	res = print_num(nbr, token, 1);
	ft_strdel(&nbr);
	return (res);
}
