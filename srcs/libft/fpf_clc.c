/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_Clc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohosla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 16:33:47 by obohosla          #+#    #+#             */
/*   Updated: 2017/05/13 18:40:08 by obohosla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		fpf_apply_md_b(intmax_t num, int z)
{
	if (++z < 63)
		fpf_apply_md_b(num, z);
	if ((num >> z) & 0x1)
		write(1, "1", 1);
	else
		write(1, "0", 1);
	((z != 0) && !(z % 4)) ? write(1, " ", 1) : 0;
}

void		fpf_apply_md_clc(va_list ap, t_flags *fl)
{
	wchar_t	c;
	int		i;
	char	*d;

	c = va_arg(ap, wchar_t);
	i = fpf_wint(c);
	d = ft_utf(c, 0, 0);
	fpf_clc(fl, d, i, 0);
	free(d);
}

char		*ft_utf(wchar_t c, char *s, char *b)
{
	s = (char *)fpf_memalloc(sizeof(char) * 6);
	b = s;
	if ((1 << 7) > c)
		*b++ = (char)c;
	else if ((1 << 11) > c)
	{
		*b++ = (char)((c >> 6) | 192);
		*b++ = (char)((c & 63) | 128);
	}
	else if ((1 << 16) > c)
	{
		*b++ = (char)((c >> 12) | 224);
		*b++ = (char)(((c >> 6) & 63) | 128);
		*b++ = (char)((c & 63) | 128);
	}
	else if ((1 << 21) > c)
	{
		*b++ = (char)(((c >> 18)) | 240);
		*b++ = (char)(((c >> 12) & 63) | 128);
		*b++ = (char)(((c >> 6) & 63) | 128);
		*b++ = (char)((c & 63) | 128);
	}
	return (s);
}

void		fpf_clc(t_flags *fl, char *s, int i, int wl)
{
	if (fl->mn)
	{
		if (fl->wd)
		{
			wl = fl->wd - i;
			fpf_putstr(s, fl);
			while (wl-- > 0)
				fpf_putchar(' ', fl);
		}
		else
			fpf_putstr(s, fl);
	}
	else
	{
		if (fl->wd)
		{
			wl = fl->wd - i;
			while (wl-- > 0)
				!fl->zr ? fpf_putchar(' ', fl) : fpf_putchar('0', fl);
			*s != 0 ? fpf_putstr(s, fl) : 0;
			*s == 0 ? fpf_putchar(0, fl) : 0;
		}
		else
			*s != 0 ? fpf_putstr(s, fl) : fpf_putchar(0, fl);
	}
}

int			fpf_wint(wchar_t c)
{
	if ((1 << 7) > c)
		return (1);
	else if ((1 << 11) > c)
		return (2);
	else if ((1 << 16) > c)
		return (3);
	else if ((1 << 21) > c)
		return (4);
	return (0);
}
