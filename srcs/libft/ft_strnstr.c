/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohosla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 12:20:24 by obohosla          #+#    #+#             */
/*   Updated: 2016/11/29 17:05:13 by obohosla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*ptr;

	ptr = ft_strstr(big, little);
	if ((ptr - big) + ft_strlen(little) > len)
		return (0);
	return (ptr);
}
