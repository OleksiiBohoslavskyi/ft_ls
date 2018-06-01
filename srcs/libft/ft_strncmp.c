/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohosla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 12:19:00 by obohosla          #+#    #+#             */
/*   Updated: 2016/12/22 13:50:37 by obohosla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *str1, const char *str2, size_t num)
{
	unsigned char	*s1ptr;
	unsigned char	*s2ptr;

	if (!num)
		return (num);
	s1ptr = (unsigned char *)str1;
	s2ptr = (unsigned char *)str2;
	while (*s1ptr == *s2ptr && *s1ptr && *s2ptr && num > 1)
	{
		s1ptr++;
		s2ptr++;
		num--;
	}
	return (*s1ptr - *s2ptr);
}
