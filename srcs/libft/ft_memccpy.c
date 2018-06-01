/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohosla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 11:55:39 by obohosla          #+#    #+#             */
/*   Updated: 2016/11/30 17:58:04 by obohosla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest_ar, const void *src_ar, int c, size_t n)
{
	char	*dest;
	char	*src;
	size_t	i;

	dest = (char *)dest_ar;
	src = (char *)src_ar;
	i = 0;
	while (i < n)
	{
		*(dest + i) = *(src + i);
		if (*(src + i) == c)
			return ((void *)(++i + dest));
		i++;
	}
	return (NULL);
}
