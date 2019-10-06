/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kostyl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 19:26:21 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/03 14:52:00 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_for_kostyl(long double n)
{
	if (n == 1 / 0.0 || n == -1 / 0.0)
		return (1);
	else if (n != n)
		return (1);
	else if (!n)
		return (1);
	else
		return (0);
}

int	kostyl(long double n, t_token *tok)
{
	if (n == 1.0 / 0.0)
		return (print_string("inf", tok));
	if (n == -1.0 / 0.0)
		return (print_string("-inf", tok));
	if (n != n)
		return (print_string("nan", tok));
	if (!n)
		return (print_double(0.0, tok));
	return (0);
}
