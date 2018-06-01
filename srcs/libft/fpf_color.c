/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohosla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:36:15 by obohosla          #+#    #+#             */
/*   Updated: 2017/04/13 19:49:00 by obohosla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*fpf_color(char *s, t_flags *fl, int i, int l)
{
	char		*tmp;

	while (s[l] != '}' && s[l] != '\0')
		l++;
	if (s[l] == '\0')
	{
		while (i < l)
			fpf_putchar(s[i++], fl);
		return (i + s);
	}
	l++;
	tmp = (char *)fpf_memalloc(sizeof(char) * (l + 1));
	i = l;
	while (--l >= 0)
		tmp[l] = s[l];
	if (fpf_color2(tmp))
	{
		free(tmp);
		return (i + s);
	}
	else
		fpf_putstr(tmp, fl);
	free(tmp);
	return (s + i);
}

int				fpf_color2(char *tmp)
{
	if (ft_strequ(tmp, BLACK) ? fpf_p_color(BLACK_COLOR) : 0)
		return (1);
	if (ft_strequ(tmp, RED) ? fpf_p_color(RED_COLOR) : 0)
		return (1);
	if (ft_strequ(tmp, GREEN) ? fpf_p_color(GREEN_COLOR) : 0)
		return (1);
	if (ft_strequ(tmp, BROWN) ? fpf_p_color(BROWN_COLOR) : 0)
		return (1);
	if (ft_strequ(tmp, BLUE) ? fpf_p_color(BLUE_COLOR) : 0)
		return (1);
	if (ft_strequ(tmp, MAGENTA) ? fpf_p_color(MAGENTA_COLOR) : 0)
		return (1);
	if (ft_strequ(tmp, CYAN) ? fpf_p_color(CYAN_COLOR) : 0)
		return (1);
	if (ft_strequ(tmp, GRAY) ? fpf_p_color(GRAY_COLOR) : 0)
		return (1);
	if (ft_strequ(tmp, DARK_GRAY) ? fpf_p_color(DARK_GRAY_COLOR) : 0)
		return (1);
	if (ft_strequ(tmp, LIGHT_RED) ? fpf_p_color(LIGHT_RED_COLOR) : 0)
		return (1);
	if (ft_strequ(tmp, LIGHT_GREEN) ? fpf_p_color(LIGHT_GREEN_COLOR) : 0)
		return (1);
	return (fpf_color3(tmp));
}

int				fpf_color3(char *tmp)
{
	if (ft_strequ(tmp, LIGHT_YELLOW) ? fpf_p_color(LIGHT_YELLOW_COLOR) : 0)
		return (1);
	if (ft_strequ(tmp, LIGHT_BLUE) ? fpf_p_color(LIGHT_BLUE_COLOR) : 0)
		return (1);
	if (ft_strequ(tmp, LIGHT_MAGENTA) ? fpf_p_color(LIGHT_MAGENTA_COLOR) : 0)
		return (1);
	if (ft_strequ(tmp, LIGHT_CYAN) ? fpf_p_color(LIGHT_CYAN_COLOR) : 0)
		return (1);
	if (ft_strequ(tmp, WHITE) ? fpf_p_color(WHITE_COLOR) : 0)
		return (1);
	if (ft_strequ(tmp, BLACKBROWN) ? fpf_p_color(BLACK_COLOR_BROWN) : 0)
		return (1);
	if (ft_strequ(tmp, BLUEBROWN) ? fpf_p_color(BLUE_COLOR_BROWN) : 0)
		return (1);
	if (ft_strequ(tmp, BLUECYAN) ? fpf_p_color(BLUE_COLOR_CYAN) : 0)
		return (1);
	if (ft_strequ(tmp, BLACKGREEN) ? fpf_p_color(BLACK_COLOR_GREEN) : 0)
		return (1);
	if (ft_strequ(tmp, EOC) ? fpf_p_color(EOC_COLOR) : 0)
		return (1);
	return (0);
}

int				ft_strequ(char const *s1, char const *s2)
{
	if (s1 && s2)
	{
		while (*s1 == *s2)
		{
			if (*s1 == '\0' && *s2 == '\0')
				return (1);
			s1++;
			s2++;
		}
	}
	return (0);
}
