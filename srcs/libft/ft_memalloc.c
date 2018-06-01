/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohosla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:35:23 by obohosla          #+#    #+#             */
/*   Updated: 2016/11/30 16:07:35 by obohosla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *mem_ar;

	mem_ar = (char *)malloc(size);
	if (mem_ar)
	{
		ft_bzero(mem_ar, size);
		return ((void *)mem_ar);
	}
	return (NULL);
}
