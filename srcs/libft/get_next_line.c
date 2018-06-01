/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohosla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 15:53:43 by obohosla          #+#    #+#             */
/*   Updated: 2017/04/19 16:16:21 by obohosla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list				*look(t_list *buff_arr, size_t fd)
{
	while (buff_arr && buff_arr->content_size != fd)
		buff_arr = buff_arr->next;
	return (buff_arr);
}

t_list				*ft_get_s_arr(t_list *stat_arr, char *buff_str, size_t fd)
{
	t_list			*buff_arr;
	t_list			*temp_arr;

	buff_arr = stat_arr;
	if (!(buff_arr = look(buff_arr, fd)))
	{
		buff_arr = ft_lstnew(buff_str, (size_t)fd);
		temp_arr = stat_arr->next;
		stat_arr->next = buff_arr;
		buff_arr->next = temp_arr;
		return (buff_arr);
	}
	return (buff_arr);
}

char				*ft_get_line(char *str, size_t l, int c)
{
	size_t			t;
	char			*line;

	c = !ft_strchr(str, '\n') ? '\0' : '\n';
	l = ft_strchr(str, c) - str;
	line = ft_strnew(l);
	line = ft_strncpy(line, str, l);
	t = (c == '\0') ? (ft_strlen(str) - l + 1) : (ft_strlen(str) - l);
	(c == '\0') ? ft_memmove(str, str + l, t) : ft_memmove(str, str + l + 1, t);
	return (line);
}

int					get_next_line(const int fd, char **line)
{
	static t_list	*stat_arr = 0;
	t_list			*b_a;
	char			*b_s;
	char			*temp_str;
	ssize_t			r_b;

	b_s = ft_strnew(BUFF_SIZE);
	if (fd < 0 || !line || read(fd, 0, 0) < 0 || BUFF_SIZE < 1)
		return (-1);
	!stat_arr ? stat_arr = ft_lstnew(b_s, (size_t)fd) : 0;
	b_a = ft_get_s_arr(stat_arr, b_s, fd);
	while ((!ft_strchr(b_a->content, '\n')) && (r_b = read(fd, b_s, BUFF_SIZE)))
	{
		b_s[r_b] = '\0';
		temp_str = ft_strjoin(b_a->content, b_s);
		free(b_a->content);
		b_a->content = temp_str;
	}
	if (!r_b && *((char *)b_a->content) == '\0')
		return (0);
	*line = ft_get_line(((char *)b_a->content), 0, 0);
	free(b_s);
	return (1);
}
