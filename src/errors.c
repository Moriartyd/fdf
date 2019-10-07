/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:09:59 by cpollich          #+#    #+#             */
/*   Updated: 2019/10/07 23:47:13 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "errors.h"

void    error(char *str)
{
    if (!errno)
        ft_putendl_fd(str, 2);
    else
        perror(str);
    exit(1);
}