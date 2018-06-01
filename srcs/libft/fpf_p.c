/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohosla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 18:37:56 by obohosla          #+#    #+#             */
/*   Updated: 2017/04/12 21:03:03 by obohosla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			f_p(va_list ap, t_flags *fl, char *s)
{
	if (fl->spec == 'p')
		s = ito(va_arg(ap, unsigned long), 16, fl);
	fpf_p(fl, s, 0, 0);
}

void			fpf_p(t_flags *fl, char *s, int pr_ln, int w_prln)
{
	int			ls;
	char		*r;

	r = fpf_pplushash(s, fl);
	ls = fsl(r);
	pr_ln = fl->pr - ls;
	w_prln = fl->wd - ((pr_ln > 0) ? fl->pr : ls);
	if (*r == '0' && *(r + 1) == '\0')
		fpf_pzero(fl, 0);
	else if (fl->wd)
	{
		if (fl->mn)
			fpf_p2(fl, r, pr_ln, w_prln);
		else
			fpf_p3(fl, r, pr_ln, w_prln);
	}
	else if (fl->dt)
		fpf_p3(fl, r, pr_ln, w_prln);
	else
		fpf_putstr(r, fl);
	free(r);
}

void			fpf_p2(t_flags *fl, char *s, int pr_ln, int w_prln)
{
	while (pr_ln-- > 0)
		fpf_putchar('0', fl);
	fpf_putstr(s, fl);
	while (w_prln-- > 0)
		fpf_putchar(' ', fl);
}

void			fpf_p3(t_flags *fl, char *s, int pr_ln, int w_prln)
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
		fpf_p31(fl, s, w_prln);
}

void			fpf_p31(t_flags *fl, char *s, int w_prln)
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
