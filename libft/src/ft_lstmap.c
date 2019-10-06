/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 20:01:15 by cpollich          #+#    #+#             */
/*   Updated: 2019/05/16 21:10:10 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstpushback(t_list *head, t_list *elem)
{
	if (!head)
		return (elem);
	while (head->next)
		head = head->next;
	head->next = elem;
	return (head);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res;
	t_list	*node;

	if (!lst || !f || !(res = (*f)(lst)))
		return (NULL);
	while ((lst = lst->next))
	{
		node = (*f)(lst);
		if (!node)
		{
			ft_lstclr(res);
			return (NULL);
		}
		ft_lstpushback(res, node);
	}
	return (res);
}
