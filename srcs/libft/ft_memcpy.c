/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohosla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 11:58:51 by obohosla          #+#    #+#             */
/*   Updated: 2016/12/07 12:54:13 by obohosla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_ar;
	unsigned char	*src_ar;
	size_t			i;

	dst_ar = (unsigned char *)dst;
	src_ar = (unsigned char *)src;
	i = -1;
	while (++i < n)
		dst_ar[i] = src_ar[i];
	return ((void *)dst_ar);
}
