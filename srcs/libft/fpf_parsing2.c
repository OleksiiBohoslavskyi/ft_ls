/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_parsing2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohosla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 15:59:00 by obohosla          #+#    #+#             */
/*   Updated: 2017/05/13 18:41:16 by obohosla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		fpf_chmod(int i, t_flags *fl)
{
	if (fl->md < i)
		fl->md = i;
}

char		*fpf_fill_mod(char *s, t_flags *fl)
{
	while (fpf_is_fl(*s, "hljz", 0))
	{
		if ((*s == 'h' && *(s + 1) == ' ' && *(s + 2) == 'h') ||
				(*s == 'l' && *(s + 1) == ' ' && *(s + 2) == 'l'))
		{
			(*s == 'h') ? fpf_chmod(1, fl) : fpf_chmod(4, fl);
			s += 3;
		}
		if ((*s == 'h' && *(s + 1) == 'h') || (*s == 'l' && *(s + 1) == 'l'))
		{
			(*s == 'h') ? fpf_chmod(1, fl) : fpf_chmod(4, fl);
			s += 2;
		}
		if ((*s == 'h' && *(s + 1) != 'h') || (*s == 'l' && *(s + 1) != 'l'))
		{
			(*s == 'h') ? fpf_chmod(2, fl) : fpf_chmod(3, fl);
			s++;
		}
		if (*s == 'j' || *s == 'z')
		{
			(*s == 'j') ? fpf_chmod(5, fl) : fpf_chmod(6, fl);
			s++;
		}
	}
	return (--s);
}

int			fpf_count_n(intmax_t n)
{
	int		size;

	size = 0;
	if (n < 0)
		size++;
	while (1)
	{
		n /= 10;
		size++;
		if (n == 0)
			break ;
	}
	return (size);
}

int			fsl(const char *s)
{
	int		len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

t_flags		*fpf_get_struck(void)
{
	t_flags	*fl;

	fl = (t_flags *)fpf_memalloc(sizeof(t_flags));
	fl->hs = 0;
	fl->zr = 0;
	fl->mn = 0;
	fl->pl = 0;
	fl->sp = 0;
	fl->wd = 0;
	fl->dt = 0;
	fl->pr = 0;
	fl->md = 0;
	fl->spec = 0;
	fl->bt = 0;
	return (fl);
}
