/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_vyvid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohosla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:59:48 by obohosla          #+#    #+#             */
/*   Updated: 2017/04/12 20:01:28 by obohosla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			fpf_putchar(char c, t_flags *fl)
{
	fl->bt += write(1, &c, 1);
}

void			fpf_putnbr(intmax_t n, t_flags *fl)
{
	uintmax_t	r;

	(n < 0) ? fpf_putchar(45, fl) : 0;
	r = n < 0 ? (uintmax_t)(n *= -1) : (uintmax_t)n;
	if (r > 9)
		fpf_putnbr(r / 10, fl);
	fpf_putchar(((char)(r % 10 + 48)), fl);
}

void			fpf_putstr(char *s, t_flags *fl)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		fpf_putchar(s[i++], fl);
}

int				fpf_p_color(char *s)
{
	int i;

	i = -1;
	while (s[++i] != '\0')
		write(1, &s[i], 1);
	return (1);
}

void			fpf_clean_struct(t_flags *fl)
{
	fl->hs = 0;
	fl->zr = 0;
	fl->mn = 0;
	fl->pl = 0;
	fl->sp = 0;
	fl->wd = 0;
	fl->dt = 0;
	fl->pr = 0;
	fl->md = 0;
	fl->spec = 0;
}
