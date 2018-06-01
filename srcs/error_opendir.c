/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_opendir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohosla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 15:35:06 by obohosla          #+#    #+#             */
/*   Updated: 2017/05/13 18:21:09 by obohosla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_flg			*ls_zero_w(t_flg *flg)
{
	flg->blocks = 0;
	flg->w_lnk = 0;
	flg->w_uid = 0;
	flg->w_gid = 0;
	flg->is = 0;
	flg->w_mj = 0;
	flg->w_sz = 0;
	flg->w_nm = 0;
	return (flg);
}

int				ls_strlen(const char *s)
{
	int			len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

int				l(size_t n)
{
	int			size;

	size = 0;
	while (1)
	{
		n /= 10;
		size++;
		if (n == 0)
			break ;
	}
	return (size);
}

char			*ls_get_name_from_path(char *s)
{
	size_t		l;

	l = ft_strlen(s);
	s = s + (l - 1);
	while ((*s != '/') && l-- > 0)
		s--;
	return (++s);
}

int				ls_error_opendir(char *path)
{
	char		*str;

	str = ft_strjoin("ft_ls: ", ls_get_name_from_path(path));
	perror(str);
	free(str);
	return (1);
}
