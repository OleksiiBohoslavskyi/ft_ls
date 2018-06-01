/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohosla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 13:03:35 by obohosla          #+#    #+#             */
/*   Updated: 2017/04/13 15:40:49 by obohosla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*fpf_fill_width(va_list ap, char *s, t_flags *fl)
{
	if (*s == '*')
	{
		fl->wd = va_arg(ap, int);
		fl->wd < 0 ? fl->mn = 1 : 0;
		fl->wd < 0 ? fl->wd *= -1 : 0;
	}
	else
	{
		if (fl->wd == 0 || *(s - 1) == '*')
			fl->wd = fpf_atoi(s);
		while (fpf_isdigit(*s))
			s++;
		s--;
	}
	return (s);
}

char		*fpf_fill_flags(char *s, t_flags *fl)
{
	while (fpf_is_fl(*s, "# -+0", 0))
	{
		if ((*s == '#') ? fl->hs = 1 : 0)
			s++;
		if ((*s == '0') ? fl->zr = 1 : 0)
			s++;
		if ((*s == '-') ? fl->mn = 1 : 0)
			s++;
		if ((*s == '+') ? fl->pl = 1 : 0)
			s++;
		if ((*s == ' ') ? fl->sp = 1 : 0)
			s++;
	}
	return (--s);
}

void		fpf_start(va_list ap, t_flags *fl)
{
	if (fpf_isspec_c(fl->spec, 0))
	{
		if (fl->spec == 'i' || fl->spec == 'd' || fl->spec == 'D')
			fpf_apply_md_id(ap, fl, 0);
		else if (fl->spec == 'u' || fl->spec == 'U')
			fpf_apply_md_u(ap, fl, 0, 0);
		else if (fl->spec == 'x' || fl->spec == 'X')
			fpf_apply_md_xx(ap, fl);
		else if (fl->spec == 'o' || fl->spec == 'O')
			fpf_apply_md_oo(ap, fl);
		else if ((fl->spec == 'n') || (fl->spec == 'p'))
			(fl->spec == 'n') ? f_n(ap, fl, 0) : f_p(ap, fl, 0);
		else if (fl->spec == 'S' || (fl->spec == 's' && fl->md == 3))
			fpf_apply_md_sls(ap, fl);
		else if (fl->spec == 'c' && fl->md == 3)
			fpf_apply_md_clc(ap, fl);
		else if ((fl->spec == 's') || (fl->spec == 'c') || fl->spec == 'C')
			(fl->spec == 's') ? f_s(ap, fl, 0, 0) : f_c(ap, fl);
		else if (fl->spec == 'b')
			fpf_apply_md_b(va_arg(ap, intmax_t), -1);
	}
	else
		fpf_other(fl, 0);
}

char		*fpf_parsing(va_list ap, char *s, t_flags *fl)
{
	while (fpf_isspec_c(*s, 0) && (fl->spec == 0) && (*s != '\0'))
	{
		if (fpf_is_fl(*s, "# -+0", 0))
			s = fpf_fill_flags(s, fl);
		else if (*s == '*' || fpf_is_digit(*s))
			s = fpf_fill_width(ap, s, fl);
		else if (*s == '.')
			s = fpf_fill_precision(ap, s, fl);
		else if (fpf_is_fl(*s, "hljz", 0))
			s = fpf_fill_mod(s, fl);
		else if (fpf_is_fl(*s, "idDoOuUxXcCsSpnb", 0))
			fl->spec = *s;
		s++;
	}
	if ((fl->spec == 0) && (*s != '\0'))
		fl->spec = *(s++);
	if (fl->spec != 0)
		fpf_start(ap, fl);
	return (s);
}

int			ft_printf(char *s, ...)
{
	va_list	ap;
	t_flags	*fl;

	if (s == NULL)
		return (-1);
	fl = fpf_get_struck();
	va_start(ap, s);
	while (*s != '\0')
	{
		if (*s == '%')
		{
			s = fpf_parsing(ap, ++s, fl);
			fpf_clean_struct(fl);
		}
		if (*s == '{')
			s = fpf_color(s, fl, 0, 1);
		if (*s != '%' && *s != '\0' && *s != '{')
			fpf_putchar(*(s++), fl);
	}
	va_end(ap);
	free(fl);
	return (fl->bt);
}
