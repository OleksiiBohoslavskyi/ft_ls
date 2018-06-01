/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohosla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 11:57:00 by obohosla          #+#    #+#             */
/*   Updated: 2016/12/01 12:42:58 by obohosla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*par;
	size_t	i;

	par = (char *)s;
	i = -1;
	while (++i < n)
	{
		if (*par == (char)c)
			return ((void *)par);
		par++;
	}
	return (NULL);
}
