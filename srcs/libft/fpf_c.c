/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohosla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 16:01:03 by obohosla          #+#    #+#             */
/*   Updated: 2017/05/13 18:41:55 by obohosla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		f_c(va_list ap, t_flags *fl)
{
	int		c;
	int		wl;

	c = va_arg(ap, int);
	if (fl->mn)
	{
		if (fl->wd)
		{
			wl = fl->wd - 1;
			fpf_putchar(c, fl);
			while (wl-- > 0)
				fpf_putchar(' ', fl);
		}
		else
			fpf_putchar(c, fl);
	}
	else
		f_c2(fl, 0, c);
}

void		f_c2(t_flags *fl, int wl, int c)
{
	if (fl->wd)
	{
		wl = fl->wd - 1;
		while (wl-- > 0)
			!fl->zr ? fpf_putchar(' ', fl) : fpf_putchar('0', fl);
		c != 0 ? fpf_putchar(c, fl) : 0;
		c == 0 ? fpf_putchar(0, fl) : 0;
	}
	else
		fpf_putchar(c, fl);
}

void		fpf_oo31(t_flags *fl, char *s, int w_prln)
{
	if (fl->zr)
	{
		while (w_prln-- > 0)
			fpf_putchar('0', fl);
		fpf_putstr(s, fl);
	}
	else
	{
		while (w_prln-- > 0)
			fpf_putchar(' ', fl);
		fpf_putstr(s, fl);
	}
}

void		fpf_ozero(t_flags *fl, int w)
{
	if (!fl->wd && !fl->pr && fl->dt && !fl->hs)
		return ;
	w = fl->dt ? fl->wd - fl->pr : fl->wd;
	if (fl->mn)
	{
		if (fl->dt && fl->pr)
			while (fl->pr-- > 0)
				fpf_putchar('0', fl);
		(!fl->dt) ? fpf_putchar('0', fl) : 0;
		while (w-- > 0)
			fpf_putchar(' ', fl);
	}
	else
	{
		(fl->pl || (fl->wd && !fl->dt)) ? w-- : 0;
		while (w-- > 0)
			fpf_putchar(' ', fl);
		if (fl->dt && fl->pr)
			while ((fl->hs ? --fl->pr : fl->pr--) > 0)
				fpf_putchar('0', fl);
		(!fl->dt || fl->hs) ? fpf_putchar('0', fl) : 0;
	}
}

char		*fpf_oplushash(char *s)
{
	char	*d;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (*s == '0')
		return (s);
	d = (char *)fpf_memalloc(sizeof(char) * (fsl(s) + 2));
	d[i++] = '0';
	while (s[j] != '\0')
		d[i++] = s[j++];
	d[i] = '\0';
	free(s);
	return (d);
}
