/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_sign.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 12:48:16 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/09/03 14:13:47 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			width_insert(t_token *list, char **substr)
{
	int		width;
	char	c;
	char	*new_str;

	c = ' ';
	if ((list->flags & F_MINUS) == F_MINUS)
		list->flags = list->flags & ~F_ZERO;
	width = list->width - ft_strlen(*substr);
	if (width <= 0)
		return ;
	new_str = ft_strnew((ft_strlen(*substr) + width));
	if ((list->flags & F_ZERO) == F_ZERO)
		c = '0';
	if ((list->flags & F_MINUS) == F_MINUS)
		width_insert_right(&new_str, *substr, width, c);
	else
		width_insert_left(&new_str, *substr, width, c);
	ft_strdel(substr);
	*substr = new_str;
}

void			add_sign(char **str, char sign)
{
	char	*new_str;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(*str) + 1;
	new_str = ft_strnew(len);
	new_str[0] = sign;
	while (++i < len)
		new_str[i] = (*str)[i - 1];
	ft_strdel(str);
	*str = new_str;
}

void			add_sign_float(char sign, char **str, t_token *lst)
{
	if (sign == '-')
		add_sign(str, '-');
	else if (sign == '+')
		add_sign(str, '+');
	if (((lst->flags & F_SPACE) == F_SPACE) && sign != '-')
		add_sign(str, ' ');
}

char			*ft_strjoin_free(char *s1, char *s2, int n)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = -1;
	while (s2[++j])
		str[i + j] = s2[j];
	if (n == 1)
		ft_strdel(&s1);
	else if (n == 2)
		ft_strdel(&s2);
	else if (n == 3)
	{
		ft_strdel(&s1);
		ft_strdel(&s2);
	}
	return (str);
}

char			*cust_strdup(t_string *src)
{
	int			i;
	char		*new_s1;

	if (!src->size)
		return (NULL);
	i = 0;
	if (!(new_s1 = malloc(sizeof(char) * (src->size + 1))))
		return (0);
	while (i < src->size)
	{
		new_s1[i] = str_at(src, i);
		i++;
	}
	new_s1[i] = '\0';
	return (new_s1);
}
