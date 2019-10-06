/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 20:41:57 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/30 20:25:04 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char const *str, int fd)
{
	int len;

	if (!str)
		return (0);
	len = (int)ft_strlen(str);
	write(fd, str, len);
	return (len);
}
