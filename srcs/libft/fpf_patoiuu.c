/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patoiuu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohosla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 20:58:00 by obohosla          #+#    #+#             */
/*   Updated: 2017/05/13 18:42:58 by obohosla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			*fpf_memalloc(size_t size)
{
	char		*mem_ar;

	mem_ar = (char *)malloc(size);
	if (mem_ar)
	{
		fpf_bzero(mem_ar, size);
		return ((void *)mem_ar);
	}
	return (NULL);
}

char			*fpf_pplushash(char *s, t_flags *fl)
{
	char		*d;
	char		*t;
	int			i;
	int			j;
	int			z;

	i = -1;
	j = 0;
	z = 0;
	z = (fl->pr > fsl(s)) ? fl->pr : fsl(s);
	d = (char *)fpf_memalloc(sizeof(char) * (z + 3));
	t = (fl->spec == 'X') ? "0X" : "0x";
	while (++i < 2)
		d[i] = t[i];
	if (fl->dt && (fl->pr == 0) && (z == 1) && *s == '0')
		return (d);
	while ((fl->pr-- - fsl(s)) > 0)
		d[i++] = '0';
	while (s[j] != '\0')
		d[i++] = s[j++];
	free(s);
	return (d);
}

void			fpf_uzero(t_flags *fl, int w)
{
	if (!fl->wd && !fl->pr && fl->dt)
		return ;
	w = fl->dt ? fl->wd - fl->pr : fl->wd;
	if (fl->mn)
	{
		fl->pl ? w-- : 0;
		fl->pl ? fpf_putchar('+', fl) : 0;
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
		fl->pl ? fpf_putchar('+', fl) : 0;
		if (fl->dt && fl->pr)
			while (fl->pr-- > 0)
				fpf_putchar('0', fl);
		(!fl->dt) ? fpf_putchar('0', fl) : 0;
	}
}

void			fpf_pzero(t_flags *fl, int w)
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
	{
		if ((fl->wd && fl->dt && !fl->hs) ? 1 : 0)
			while (w-- > 0)
				fpf_putchar(' ', fl);
		else if ((fl->pl || (fl->wd && !fl->dt && !fl->hs)) ? 1 : 0)
			while (w-- > 0)
				fpf_putchar('0', fl);
		else if (fl->dt && fl->pr)
			while (fl->pr-- > 0)
				fpf_putchar('0', fl);
		!fl->dt ? fpf_putchar('0', fl) : 0;
	}
}
