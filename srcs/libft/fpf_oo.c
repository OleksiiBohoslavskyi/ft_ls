/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_oo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohosla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 18:18:27 by obohosla          #+#    #+#             */
/*   Updated: 2017/05/13 18:40:56 by obohosla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			fpf_apply_md_oo(va_list ap, t_flags *fl)
{
	char		*s;

	s = 0;
	if (fl->spec == 'o')
	{
		(fl->md == 0) ? s = it(va_arg(ap, unsigned), 8, fl) : 0;
		(fl->md == 1) ? s = it((unsigned char)va_arg(ap, unsigned), 8, fl) : 0;
		(fl->md == 2) ? s = it((unsigned short)va_arg(ap, unsigned), 8, fl) : 0;
		(fl->md == 3) ? s = it(va_arg(ap, unsigned long), 8, fl) : 0;
		(fl->md == 4) ? s = it(va_arg(ap, unsigned long long), 8, fl) : 0;
		(fl->md == 5) ? s = it((uintmax_t)va_arg(ap, uintmax_t), 8, fl) : 0;
		(fl->md == 6) ? s = it((size_t)va_arg(ap, size_t), 8, fl) : 0;
	}
	else if (fl->spec == 'O')
		s = it(va_arg(ap, unsigned long int), 8, fl);
	fpf_oo(fl, s, 0, 0);
}

char			*it(uintmax_t value, int b, t_flags *fl)
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

void			fpf_oo(t_flags *fl, char *s, int pr_ln, int w_prln)
{
	int			ls;

	(fl->hs && (fl->spec == 'o' || fl->spec == 'O')) ? s = fpf_oplushash(s) : 0;
	ls = fsl(s);
	pr_ln = fl->pr - ls;
	w_prln = fl->wd - ((pr_ln > 0) ? fl->pr : ls);
	if (*s == '0' && *(s + 1) == '\0')
		fpf_ozero(fl, 0);
	else if (fl->wd)
	{
		if (fl->mn)
			fpf_oo2(fl, s, pr_ln, w_prln);
		else
			fpf_oo3(fl, s, pr_ln, w_prln);
	}
	else if (fl->dt)
		fpf_oo3(fl, s, pr_ln, w_prln);
	else
		fpf_putstr(s, fl);
	free(s);
}

void			fpf_oo2(t_flags *fl, char *s, int pr_ln, int w_prln)
{
	while (pr_ln-- > 0)
		fpf_putchar('0', fl);
	fpf_putstr(s, fl);
	while (w_prln-- > 0)
		fpf_putchar(' ', fl);
}

void			fpf_oo3(t_flags *fl, char *s, int pr_ln, int w_prln)
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
		fpf_oo31(fl, s, w_prln);
}
