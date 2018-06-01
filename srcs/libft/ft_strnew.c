/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohosla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 18:04:36 by obohosla          #+#    #+#             */
/*   Updated: 2016/11/29 18:05:01 by obohosla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*mem_ptr;

	mem_ptr = (char *)malloc(size + 1);
	if (mem_ptr)
	{
		ft_bzero(mem_ptr, size + 1);
		return (mem_ptr);
	}
	return (NULL);
}
