/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_uu.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohosla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:56:22 by obohosla          #+#    #+#             */
/*   Updated: 2017/04/12 21:04:22 by obohosla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			fpf_apply_md_u(va_list ap, t_flags *fl, uintmax_t tmp, char *s)
{
	if (fl->spec == 'u')
	{
		(fl->md == 0) ? tmp = va_arg(ap, unsigned int) : 0;
		(fl->md == 1) ? tmp = (unsigned char)va_arg(ap, unsigned int) : 0;
		(fl->md == 2) ? tmp = (unsigned short int)va_arg(ap, unsigned int) : 0;
		(fl->md == 3) ? tmp = va_arg(ap, unsigned long int) : 0;
		(fl->md == 4) ? tmp = va_arg(ap, unsigned long long int) : 0;
		(fl->md == 5) ? tmp = va_arg(ap, uintmax_t) : 0;
		(fl->md == 6) ? tmp = va_arg(ap, size_t) : 0;
	}
	else if (fl->spec == 'U')
		tmp = va_arg(ap, unsigned long int);
	s = fpf_uitoa(tmp);
	fpf_u(fl, s, 0, 0);
	free(s);
}

void			fpf_u(t_flags *fl, char *s, int pr_ln, int w_prln)
{
	int			ln;

	ln = fsl(s);
	pr_ln = fl->pr - ln;
	w_prln = fl->wd - ((pr_ln > 0) ? fl->pr : ln);
	if (*s == '0' && *(s + 1) == '\0')
		fpf_uzero(fl, 0);
	else if (fl->wd)
	{
		if (fl->mn)
			fpf_u2(fl, s, pr_ln, w_prln);
		else
			fpf_u3(fl, s, pr_ln, w_prln);
	}
	else if (fl->dt)
		fpf_u3(fl, s, pr_ln, w_prln);
	else
		fpf_putstr(s, fl);
}

void			fpf_u2(t_flags *fl, char *s, int pr_ln, int w_prln)
{
	while (pr_ln-- > 0)
		fpf_putchar('0', fl);
	fpf_putstr(s, fl);
	while (w_prln-- > 0)
		fpf_putchar(' ', fl);
}

void			fpf_u3(t_flags *fl, char *s, int pr_ln, int w_prln)
{
	if (fl->dt)
	{
		while ((fl->pl || fl->sp) ? (--w_prln > 0) : (w_prln-- > 0))
			fpf_putchar(' ', fl);
		fl->pl ? fpf_putchar('+', fl) : 0;
		fl->sp ? fpf_putchar(' ', fl) : 0;
		while (pr_ln-- > 0)
			fpf_putchar('0', fl);
		fpf_putstr(s, fl);
	}
	else
		fpf_u31(fl, s, w_prln);
}

void			fpf_u31(t_flags *fl, char *s, int w_prln)
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
