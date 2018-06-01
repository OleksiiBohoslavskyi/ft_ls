/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohosla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 13:07:30 by obohosla          #+#    #+#             */
/*   Updated: 2017/04/11 13:11:21 by obohosla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			fpf_isspec_c(char c, int i)
{
	char	*s;

	s = "#0+-.*cCidDoOuUxXsSpnb hlz123456789j";
	while (s[i] != '\0')
		if (s[i++] == c)
			return (1);
	return (0);
}

int			fpf_is_fl(char c, char *s, int i)
{
	while (s[i] != '\0')
		if (s[i++] == c)
			return (1);
	return (0);
}

int			fpf_is_digit(char c)
{
	if (c >= '1' && c <= '9')
		return (1);
	return (0);
}

int			fpf_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char		*fpf_fill_precision(va_list ap, char *s, t_flags *fl)
{
	if (*(s + 1) == '-')
	{
		fl->wd = 0;
		fl->dt = 0;
		fl->pr = 0;
		return (s);
	}
	fl->dt = 1;
	if (*(s + 1) == '*')
		fl->pr = va_arg(ap, int);
	else
	{
		fl->pr = fpf_atoi(++s);
		while (fpf_isdigit(*s))
			s++;
		s--;
		s--;
	}
	return (++s);
}
