/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_idd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohosla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 17:59:52 by obohosla          #+#    #+#             */
/*   Updated: 2017/04/12 18:08:22 by obohosla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			fpf_apply_md_id(va_list ap, t_flags *fl, intmax_t tmp)
{
	if (fl->spec == 'd' || fl->spec == 'i')
	{
		(fl->md == 0) ? tmp = va_arg(ap, int) : 0;
		(fl->md == 1) ? tmp = (char)va_arg(ap, int) : 0;
		(fl->md == 2) ? tmp = (short)va_arg(ap, int) : 0;
		(fl->md == 3) ? tmp = va_arg(ap, long int) : 0;
		(fl->md == 4) ? tmp = va_arg(ap, long long int) : 0;
		(fl->md == 5) ? tmp = va_arg(ap, intmax_t) : 0;
		(fl->md == 6) ? tmp = va_arg(ap, size_t) : 0;
	}
	else if (fl->spec == 'D')
		tmp = (long)va_arg(ap, intmax_t);
	fpf_id(fl, tmp, 0, 0);
}

void			fpf_id(t_flags *fl, intmax_t n, int pr_ln, int w_prln)
{
	int			ln;

	ln = fpf_count_n(n);
	(fl->pr < 0) ? (fl->pr = fl->wd) : 0;
	pr_ln = fl->pr - ln;
	w_prln = fl->wd - ((pr_ln > 0) ? fl->pr : ln);
	(n < 0 && pr_ln >= 0) ? w_prln-- : 0;
	if (n == 0)
		fpf_iddzero(fl, 0);
	else if (fl->wd)
	{
		if (fl->mn)
			fpf_id2(fl, n, pr_ln, w_prln);
		else
			fpf_id3(fl, n, pr_ln, w_prln);
	}
	else if (fl->dt)
		fpf_id3(fl, n, pr_ln, w_prln);
	else
	{
		(fl->pl && n > 0) ? fpf_putchar('+', fl) : 0;
		(!fl->pl && fl->sp && n > 0) ? fpf_putchar(' ', fl) : 0;
		fpf_putnbr(n, fl);
	}
}

void			fpf_id2(t_flags *fl, intmax_t n, int pr_ln, int w_prln)
{
	if (n > 0)
	{
		fl->pl ? fpf_putchar('+', fl) : 0;
		(!fl->pl && fl->sp) ? fpf_putchar(' ', fl) : 0;
		while (pr_ln-- > 0)
			fpf_putchar('0', fl);
		fpf_putnbr(n, fl);
		while ((fl->pl || fl->sp) ? (--w_prln > 0) : (w_prln-- > 0))
			fpf_putchar(' ', fl);
	}
	else if (n < 0)
	{
		fpf_putchar('-', fl);
		while (pr_ln-- >= 0)
			fpf_putchar('0', fl);
		fpf_putnbr((intmax_t)(n *= -1), fl);
		while ((pr_ln <= 0) ? w_prln-- > 0 : --w_prln > 0)
			fpf_putchar(' ', fl);
	}
}

void			fpf_id3(t_flags *fl, intmax_t n, int pr_ln, int w_prln)
{
	if (fl->dt)
	{
		if (n > 0)
		{
			while ((fl->pl || fl->sp) ? (--w_prln > 0) : (w_prln-- > 0))
				fpf_putchar(' ', fl);
			fl->pl ? fpf_putchar('+', fl) : 0;
			fl->sp ? fpf_putchar(' ', fl) : 0;
			while (pr_ln-- > 0)
				fpf_putchar('0', fl);
			fpf_putnbr(n, fl);
		}
		else if (n < 0)
		{
			while (fl->zr ? --w_prln >= 0 : w_prln-- > 0)
				fpf_putchar(' ', fl);
			fpf_putchar('-', fl);
			while (pr_ln-- >= 0)
				fpf_putchar('0', fl);
			fpf_putnbr(n *= -1, fl);
		}
	}
	else
		fpf_id31(fl, n, w_prln);
}

void			fpf_id31(t_flags *fl, intmax_t n, int w_prln)
{
	if (fl->zr)
	{
		if (n > 0)
		{
			fl->pl ? fpf_putchar('+', fl) : 0;
			(!fl->pl && fl->sp) ? fpf_putchar(' ', fl) : 0;
			while ((fl->pl || fl->sp) ? (--w_prln > 0) : (w_prln-- > 0))
				fpf_putchar('0', fl);
			fpf_putnbr(n, fl);
		}
		else if (n < 0)
		{
			fpf_putchar('-', fl);
			while (w_prln-- > 0)
				fpf_putchar('0', fl);
			fpf_putnbr((uintmax_t)(n *= -1), fl);
		}
	}
	else
		fpf_id32(fl, n, w_prln);
}
