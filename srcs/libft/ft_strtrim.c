/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohosla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 17:31:49 by obohosla          #+#    #+#             */
/*   Updated: 2016/12/09 18:00:33 by obohosla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char *end;
	char *rez;

	if (s)
	{
		while (*s == ' ' || *s == '\n' || *s == '\t')
			s++;
		end = ft_strchr(s, '\0');
		while ((*(end - 1) == ' ' || *(end - 1) == '\n' || *(end - 1) == '\t')\
			&& (end > s))
			end--;
		rez = (char *)ft_memalloc(end - s + 1);
		if (rez)
			ft_memmove(rez, s, (end - s));
		return (rez);
	}
	return (0);
}
