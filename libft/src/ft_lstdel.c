/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 19:42:20 by moriarty          #+#    #+#             */
/*   Updated: 2019/05/16 21:07:50 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*now;
	t_list	*tmp;

	if (!alst || !(*alst) || !del)
		return ;
	now = *alst;
	while (now)
	{
		tmp = now->next;
		ft_lstdelone(&now, del);
		now = tmp;
	}
	*alst = NULL;
}
