/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 17:45:29 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/03 17:45:42 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			str_clean(t_string **s)
{
	if (s && *s)
	{
		ft_strdel(&(*s)->data);
		(*s)->capacity = 0;
		(*s)->size = 0;
	}
}

void			str_destroy(t_string **s)
{
	if (s && *s)
	{
		ft_strdel(&(*s)->data);
		(*s)->capacity = 0;
		(*s)->size = 0;
		free(*s);
		*s = NULL;
	}
}
