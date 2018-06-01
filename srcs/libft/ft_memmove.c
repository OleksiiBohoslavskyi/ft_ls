/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohosla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 11:59:24 by obohosla          #+#    #+#             */
/*   Updated: 2016/12/01 14:20:59 by obohosla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst >= src)
		while (len--)
			*((char *)dst + len) = *((char *)src + len);
	else
		ft_memcpy(dst, src, len);
	return ((void *)dst);
}
