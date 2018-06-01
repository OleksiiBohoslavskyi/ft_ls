/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohosla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 11:57:39 by obohosla          #+#    #+#             */
/*   Updated: 2016/12/01 14:08:09 by obohosla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1ar;
	unsigned char	*s2ar;
	size_t			i;

	s1ar = (unsigned char *)s1;
	s2ar = (unsigned char *)s2;
	i = -1;
	while (++i < n)
		if (s1ar[i] != s2ar[i])
			return (s1ar[i] - s2ar[i]);
	return (0);
}
