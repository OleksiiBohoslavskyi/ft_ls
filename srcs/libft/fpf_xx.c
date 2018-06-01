/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_xx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohosla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 20:19:18 by obohosla          #+#    #+#             */
/*   Updated: 2017/05/13 18:39:35 by obohosla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			fpf_apply_md_xx(va_list ap, t_flags *fl)
{
	char		*s;

	s = 0;
	if (fl->spec == 'x' || fl->spec == 'X')
	{
		(fl->md == 0) ? s = ito(va_arg(ap, unsigned int), 16, fl) : 0;
		if (fl->md == 1)
			s = ito((unsigned char)va_arg(ap, unsigned), 16, fl);
		if (fl->md == 2)
			s = ito((unsigned short)va_arg(ap, unsigned), 16, fl);
		(fl->md == 3) ? s = ito(va_arg(ap, unsigned long), 16, fl) : 0;
		(fl->md == 4) ? s = ito(va_arg(ap, unsigned long long), 16, fl) : 0;
		(fl->md == 5) ? s = ito(va_arg(ap, uintmax_t), 16, fl) : 0;
		(fl->md == 6) ? s = ito(va_arg(ap, size_t), 16, fl) : 0;
	}
	fpf_xx(fl, s, 0, 0);
}

char			*ito(uintmax_t value, int b, t_flags *fl)
{
	char		*base;
	char		*result;
	uintmax_t	v;
	uintmax_t	tmp;
	int			len;

	len = 1;
	if (fl->spec == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	v = value;
	tmp = value;
	while ((tmp /= b))
		len++;
	result = (char *)fpf_memalloc(sizeof(char) * (len + 1));
	while (len--)
	{
		result[len] = base[v % b];
		v /= b;
	}
	return (result);
}

void			fpf_xx(t_flags *fl, char *s, int pr_ln, int w_prln)
{
	int			ls;

	(fl->hs || fl->spec == 'p') ? s = fpf_xplushash(s, fl, 0, 0) : 0;
	ls = fsl(s);
	pr_ln = fl->pr - ls;
	w_prln = fl->wd - ((pr_ln > 0) ? fl->pr : ls);
	if (*s == '0' && *(s + 1) == '\0')
		fpf_xzero(fl, 0);
	else if (fl->wd)
	{
		if (fl->mn)
			fpf_xx2(fl, s, pr_ln, w_prln);
		else
			fpf_xx3(fl, s, pr_ln, w_prln);
	}
	else if (fl->dt)
		fpf_xx3(fl, s, pr_ln, w_prln);
	else
		fpf_putstr(s, fl);
	free(s);
}

void			fpf_xx2(t_flags *fl, char *s, int pr_ln, int w_prln)
{
	while (pr_ln-- > 0)
		fpf_putchar('0', fl);
	fpf_putstr(s, fl);
	while (w_prln-- > 0)
		fpf_putchar(' ', fl);
}
