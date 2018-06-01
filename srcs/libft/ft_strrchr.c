/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohosla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 12:21:06 by obohosla          #+#    #+#             */
/*   Updated: 2016/11/30 13:57:49 by obohosla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	while (*s)
		s++;
	while (1)
	{
		if (*s == c)
		{
			return ((char *)s);
		}
		else if (len == 0)
			break ;
		len--;
		s--;
	}
	return (NULL);
}
