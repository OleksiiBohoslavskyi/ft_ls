/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohosla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 18:01:22 by obohosla          #+#    #+#             */
/*   Updated: 2016/12/07 17:31:31 by obohosla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	len;
	size_t	i;

	if (s)
	{
		i = -1;
		len = ft_strlen(s);
		str = (char *)malloc(len + 1);
		if (str)
		{
			while (++i < len)
				str[i] = f(s[i]);
			str[i] = '\0';
			return (str);
		}
	}
	return (NULL);
}
