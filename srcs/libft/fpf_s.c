/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohosla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:19:39 by obohosla          #+#    #+#             */
/*   Updated: 2017/04/13 15:35:58 by obohosla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			f_s(va_list ap, t_flags *fl, int l, int wl)
{
	char		*s;

	s = va_arg(ap, char *);
	if (s == NULL)
	{
		fpf_s(fl);
		return ;
	}
	l = fsl(s);
	if (fl->mn)
	{
		wl = (fl->dt && fl->pr < l) ? (fl->wd - fl->pr) : (fl->wd - l);
		if (fl->dt)
			while ((fl->pr-- > 0) && (l-- > 0) && (*s != '\0'))
				fpf_putchar(*s++, fl);
		if (!fl->dt)
			while (*s != '\0')
				fpf_putchar(*s++, fl);
		while (wl-- > 0)
			fpf_putchar(' ', fl);
	}
	else
		f_s2(s, fl, l, wl);
}

void			f_s2(char *s, t_flags *fl, int l, int wl)
{
	if (fl->dt)
	{
		wl = (((fl->pr < l) && (fl->pr >= 0)) ? fl->wd - fl->pr : fl->wd - l);
		while (wl-- > 0)
			fl->zr ? fpf_putchar('0', fl) : fpf_putchar(' ', fl);
		if (fl->pr > 0)
			while (fl->pr-- > 0 && l-- > 0 && *s)
				fpf_putchar(*s++, fl);
		else if (fl->pr != 0)
			while (*s)
				fpf_putchar(*s++, fl);
	}
	else
	{
		wl = fl->wd - l;
		while (wl-- > 0)
			(!fl->zr) ? fpf_putchar(' ', fl) : fpf_putchar('0', fl);
		while (*s)
			fpf_putchar(*s++, fl);
	}
}

void			fpf_s(t_flags *fl)
{
	int			wp;
	char		*s;

	s = "(null)";
	wp = fl->wd - fl->pr;
	if (fl->dt)
	{
		while (wp-- > 0)
			!fl->zr ? fpf_putchar(' ', fl) : fpf_putchar('0', fl);
		while ((fl->pr-- > 0) && (*s != '\0'))
			fpf_putchar(*(s++), fl);
	}
	else
		fpf_putstr(s, fl);
}
