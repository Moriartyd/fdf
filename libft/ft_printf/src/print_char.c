/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 22:04:53 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/03 14:15:53 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c, t_token *token)
{
	int w;
	int i;

	w = token->width;
	i = 1;
	if (w < 2)
		return (ft_putchar(c));
	if ((token->flags & F_MINUS) == F_MINUS)
	{
		token->flags = token->flags & ~F_ZERO;
		ft_putchar(c);
		while (i < w)
			i += ft_putchar((token->flags & F_ZERO) == F_ZERO ? '0' : ' ');
	}
	else
	{
		while (i < w)
			i += ft_putchar((token->flags & F_ZERO) == F_ZERO ? '0' : ' ');
		ft_putchar(c);
	}
	return (i);
}
