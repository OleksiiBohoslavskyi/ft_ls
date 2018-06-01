/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_sc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohosla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 17:01:25 by obohosla          #+#    #+#             */
/*   Updated: 2017/05/13 18:42:23 by obohosla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			fpf_apply_md_sls(va_list ap, t_flags *fl)
{
	wchar_t		*c;
	char		**arr;
	int			l;
	intmax_t	i;

	i = 0;
	c = va_arg(ap, wchar_t *);
	if (c == NULL)
	{
		fpf_ss(fl);
		return ;
	}
	l = fpf_sstrlen(c);
	arr = (char **)fpf_memalloc(sizeof(char *) * (l + 1));
	while (*c != '\0')
	{
		arr[i++] = ft_utf(*c, 0, 0);
		c++;
	}
	fpf_sls(fl, arr, l, 0);
	while (l-- > 0)
		free(arr[l]);
	free(arr);
}

int				fpf_sstrlen(wchar_t *c)
{
	int			l;

	l = 0;
	while (*c != '\0')
	{
		l++;
		c++;
	}
	return (l);
}

void			fpf_sls(t_flags *fl, char **arr, int l, int i)
{
	int			wl;

	if (fl->mn)
	{
		if (fl->dt)
		{
			wl = (fl->pr < l) ? fl->wd - fl->pr : fl->wd - l;
			while ((fl->pr >= fsl(arr[i])) &&
					fl->pr >= 0 && (arr[i] != '\0'))
			{
				fl->pr -= fsl(arr[i]);
				fpf_putstr(arr[i++], fl);
			}
		}
		else
		{
			wl = fl->wd - l;
			while (arr[i] != '\0')
				fpf_putstr(arr[i++], fl);
		}
		while (wl-- > 0)
			fpf_putchar(' ', fl);
	}
	else
		fpf_sls2(fl, arr, l, i);
}

void			fpf_sls2(t_flags *fl, char **arr, int l, int i)
{
	int			wl;

	if (fl->dt)
	{
		wl = (((fl->pr < l) && (fl->pr >= 0)) ? fl->wd - fl->pr : fl->wd - l);
		while (wl-- > 0)
			fl->zr ? fpf_putchar('0', fl) : fpf_putchar(' ', fl);
		if (fl->pr > 0)
			while ((fl->pr >= fsl(arr[i])) && fl->pr > 0 && (arr[i] != '\0'))
			{
				fl->pr -= fsl(arr[i]);
				fpf_putstr(arr[i++], fl);
			}
		else if (fl->pr != 0)
			while (arr[i] != '\0')
				fpf_putstr(arr[i++], fl);
	}
	else
	{
		wl = fl->wd - l;
		while (wl-- > 0)
			(!fl->zr) ? fpf_putchar(' ', fl) : fpf_putchar('0', fl);
		while (arr[i] != '\0')
			fpf_putstr(arr[i++], fl);
	}
}

void			fpf_ss(t_flags *fl)
{
	int			wp;
	char		*s;

	s = "(null)";
	wp = fl->wd - 6;
	if (fl->dt)
	{
		while (wp-- > 0)
			!fl->zr ? fpf_putchar(' ', fl) : fpf_putchar('0', fl);
		while ((fl->pr-- > 0) && (*s != '\0'))
			fpf_putchar(*(s++), fl);
	}
	else
	{
		while (wp-- > 0)
			!fl->zr ? fpf_putchar(' ', fl) : fpf_putchar('0', fl);
		while ((*s != '\0'))
			fpf_putchar(*(s++), fl);
	}
}
