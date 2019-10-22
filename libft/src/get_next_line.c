/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:19:21 by moriarty          #+#    #+#             */
/*   Updated: 2019/10/22 20:48:29 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*
**	Удаляет статическую переменную
*/

static int		ft_lstdelfile(char **line, t_list **head, int fd, t_list *prev)
{
	t_list	*now;

	ft_strdel(line);
	if ((!head || !(now = *head) || fd < 0))
		return (0);
	if ((now->content_size == (size_t)fd) && !(prev = NULL))
	{
		free(now->content);
		*head = now->next;
		free(now);
		return (0);
	}
	while (now)
	{
		if (now->content_size == (size_t)fd)
		{
			free(now->content);
			prev ? (prev->next = now->next) : (0);
			free(now);
			return (0);
		}
		prev = now;
		now = now->next;
	}
	return (0);
}

/*
**	Создает статическую переменную
*/

static t_list	*t_list_create_file(int fd)
{
	t_list	*res;

	res = (t_list *)malloc(sizeof(t_list));
	if (!res)
		return (NULL);
	res->content = NULL;
	res->content_size = fd;
	res->next = NULL;
	return (res);
}

/*
**	Поиск статической переменной
*/

static t_list	*get_file(int fd, t_list **head)
{
	t_list	*now;

	if (!head)
		return (NULL);
	now = *head;
	while (now)
	{
		if (now->content_size == (size_t)fd)
			return (now);
		now = now->next;
	}
	now = t_list_create_file(fd);
	if (!now)
		return (NULL);
	ft_lstadd(head, now);
	return (now);
}

/*
**	Запись в *line
*/

static int		fillin_line(char **line, char *tmp,
		t_list *file, t_list **start)
{
	size_t	len;
	char	*strchr_tmp;
	char	*removen;

	len = ft_strlen(tmp);
	ft_strdel((char **)&file->content);
	if (!tmp)
		return (-1);
	tmp ? (strchr_tmp = ft_strchr(tmp, '\n')) : (0);
	!tmp ? (strchr_tmp = NULL) : (0);
	strchr_tmp ? (len = strchr_tmp - tmp) : (0);
	*line = ft_strnew(len);
	*line = ft_strncpy(*line, tmp, len);
	if (strchr_tmp)
	{
		removen = ft_strdup(strchr_tmp + 1);
		ft_strdel(&tmp);
		file->content = removen;
		if (!*line || (!**line && !strchr_tmp) || !file->content)
			return (ft_lstdelfile(line, start, file->content_size, file));
	}
	ft_strdel(&tmp);
	return ((!*line || (!**line && !strchr_tmp)) ?
	(ft_lstdelfile(line, start, file->content_size, file)) : (1));
}

int				ft_gnl(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	int				len;
	char			*t;
	static t_list	*start;
	t_list			*file;

	if (fd < 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	len = 1;
	if (!(file = get_file(fd, &start)))
		return (-1);
	while ((len = read(fd, buf, BUFF_SIZE)) > 0 ||
		(file->content && (char **)&file->content[0]))
	{
		buf[len] = '\0';
		t = (file->content) ? ft_strjoin(file->content, buf) : ft_strdup(buf);
		if ((t && ft_strchr(t, '\n')) || len <= 0)
			return (fillin_line(line, t, file, &start));
		free(file->content);
		file->content = t;
		if (!file->content)
			return (-1);
	}
	return (0);
}
