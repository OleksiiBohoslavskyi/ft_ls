/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohosla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 12:21:29 by obohosla          #+#    #+#             */
/*   Updated: 2016/11/29 16:38:04 by obohosla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	char *ptr_s1;
	char *ptr_s2;

	if (*s2 == '\0' || *s2 == '\n')
		return ((char *)s1);
	while (*s1 != '\0')
	{
		ptr_s2 = (char *)s2;
		if (*s1 == *ptr_s2)
		{
			ptr_s1 = (char *)s1;
			while (*ptr_s1 == *ptr_s2 || !(*ptr_s2))
			{
				if (!(*ptr_s2))
					return ((char *)s1);
				ptr_s1++;
				ptr_s2++;
			}
		}
		s1++;
	}
	return (NULL);
}
