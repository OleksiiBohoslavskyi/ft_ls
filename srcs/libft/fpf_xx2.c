/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_xx2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohosla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 20:51:31 by obohosla          #+#    #+#             */
/*   Updated: 2017/05/13 18:39:03 by obohosla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			fpf_xx3(t_flags *fl, char *s, int pr_ln, int w_prln)
{
	if (fl->dt)
	{
		while (w_prln-- > 0)
			fpf_putchar(' ', fl);
		while (pr_ln-- > 0)
			fpf_putchar('0', fl);
		fpf_putstr(s, fl);
	}
	else
	{
		while (w_prln-- > 0)
			fl->zr ? fpf_putchar('0', fl) : fpf_putchar(' ', fl);
		fpf_putstr(s, fl);
	}
}

void			fpf_xzero(t_flags *fl, int w)
{
	if (!fl->wd && !fl->pr && fl->dt)
		return ;
	w = fl->dt ? fl->wd - fl->pr : fl->wd;
	if (fl->mn)
	{
		if (fl->dt && fl->pr)
			while (fl->pr-- > 0)
				fpf_putchar('0', fl);
		(!fl->dt) ? fpf_putchar('0', fl) : 0;
		while (--w > 0)
			fpf_putchar(' ', fl);
	}
	else
		fpf_xzero2(fl, w);
}

void			fpf_xzero2(t_flags *fl, int w)
{
	if ((fl->wd && fl->dt && !fl->hs) ? 1 : 0)
	{
		while (w-- > 0)
			fpf_putchar(' ', fl);
		while (fl->pr-- > 0)
			fpf_putchar('0', fl);
	}
	else if ((fl->pl || (fl->wd && !fl->dt && !fl->hs)) ? 1 : 0)
		while (--w > 0)
			(fl->pl || fl->zr) ? fpf_putchar('0', fl) : fpf_putchar(' ', fl);
	else if (fl->dt && fl->pr)
		while (fl->pr-- > 0)
			fpf_putchar('0', fl);
	(!fl->dt) ? fpf_putchar('0', fl) : 0;
}

char			*fpf_xplushash(char *s, t_flags *fl, int i, int j)
{
	char		*d;
	char		*t;
	int			z;

	z = 0;
	if (*s == '0' && *(s + 1) == '\0')
		return (s);
	if (!fl->dt && fl->wd && fl->zr && !fl->mn)
		z = fl->wd - fsl(s) - 2;
	if (fl->dt)
		z = fl->pr - fsl(s);
	d = (char *)fpf_memalloc(sizeof(char) * (fsl(s) + 3 + z));
	t = (fl->spec == 'X') ? "0X" : "0x";
	while (*t != '\0')
		d[i++] = *t++;
	while (z-- > 0)
		d[i++] = '0';
	while (s[j] != '\0')
		d[i++] = s[j++];
	t = d;
	free(s);
	return (t);
}

void			f_n(va_list ap, t_flags *fl, int *i)
{
	i = va_arg(ap, int *);
	*i = fl->bt;
}
