/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 20:26:27 by cpollich          #+#    #+#             */
/*   Updated: 2019/05/16 21:09:47 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*now;
	t_list	*temp;

	if (!lst || !f)
		return ;
	now = lst;
	while (now)
	{
		temp = now->next;
		(*f)(now);
		now = temp;
	}
}
