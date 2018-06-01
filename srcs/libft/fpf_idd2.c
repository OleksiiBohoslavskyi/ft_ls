/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_idd2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohosla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 18:11:37 by obohosla          #+#    #+#             */
/*   Updated: 2017/04/12 18:14:34 by obohosla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			fpf_id32(t_flags *fl, intmax_t n, int w_prln)
{
	if (n > 0)
	{
		(!fl->pl && fl->sp) ? fpf_putchar(' ', fl) : 0;
		while ((fl->pl || fl->sp) ? (--w_prln > 0) : (w_prln-- > 0))
			fpf_putchar(' ', fl);
		fl->pl ? fpf_putchar('+', fl) : 0;
		fpf_putnbr(n, fl);
	}
	else if (n < 0)
	{
		while (w_prln-- > 0)
			fpf_putchar(' ', fl);
		fpf_putnbr((intmax_t)n, fl);
	}
}

void			fpf_iddzero(t_flags *fl, int w)
{
	if (!fl->wd && !fl->pr && fl->dt)
		return ;
	w = (fl->dt ? fl->wd - fl->pr : fl->wd);
	fl->pl ? w-- : 0;
	(fl->sp && w && !fl->pl) ? w-- : 0;
	if (fl->mn)
	{
		fl->pl ? fpf_putchar('+', fl) : 0;
		(fl->sp && w && !fl->pl) ? fpf_putchar(' ', fl) : 0;
		while (fl->pr-- > 0)
			fpf_putchar('0', fl);
		if (!fl->dt)
		{
			fpf_putchar('0', fl);
			w--;
		}
		while (w-- > 0)
			fpf_putchar(' ', fl);
	}
	else
		fpf_iddzero2(fl, w);
}

void			fpf_iddzero2(t_flags *fl, int w)
{
	if (!fl->zr)
	{
		(fl->sp && w && !fl->pl) ? fpf_putchar(' ', fl) : 0;
		while (--w > 0)
			fpf_putchar(' ', fl);
		fl->pl ? fpf_putchar('+', fl) : 0;
		if (fl->pr)
		{
			while (fl->pr-- > 0)
				fpf_putchar('0', fl);
			return ;
		}
		if (fl->dt)
			(fl->pr < 1) ? fpf_putchar(' ', fl) : 0;
		(fl->wd && !fl->dt && !fl->pl) ? fpf_putchar('0', fl) : 0;
		(!fl->wd) ? fpf_putchar('0', fl) : 0;
	}
	else
		fpf_iddzero3(fl, w);
}

void			fpf_iddzero3(t_flags *fl, int w)
{
	if (fl->pr)
	{
		while (w-- > 0)
			fpf_putchar(' ', fl);
		fl->pl ? fpf_putchar('+', fl) : 0;
		while (fl->pr-- > 0)
			fpf_putchar('0', fl);
	}
	else
	{
		(fl->sp && w && !fl->pl) ? fpf_putchar(' ', fl) : 0;
		if (fl->dt)
		{
			while (w-- > 0)
				fpf_putchar(' ', fl);
			fl->pl ? fpf_putchar('+', fl) : 0;
		}
		else
		{
			fl->pl ? fpf_putchar('+', fl) : 0;
			while (w-- > 0)
				fpf_putchar('0', fl);
			(!fl->wd) ? fpf_putchar('0', fl) : 0;
		}
	}
}

void			fpf_other(t_flags *fl, int i)
{
	if (fl->wd)
	{
		i = fl->wd - 1;
		if (fl->mn)
		{
			fpf_putchar(fl->spec, fl);
			while (i-- > 0)
				fpf_putchar(' ', fl);
		}
		else
		{
			while (i-- > 0)
				fl->zr ? fpf_putchar('0', fl) : fpf_putchar(' ', fl);
			fpf_putchar(fl->spec, fl);
		}
	}
	else
		fpf_putchar(fl->spec, fl);
}
