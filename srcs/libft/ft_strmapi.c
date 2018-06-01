/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohosla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 18:02:19 by obohosla          #+#    #+#             */
/*   Updated: 2016/12/07 17:34:16 by obohosla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	size_t			len;
	unsigned int	i;

	if (s)
	{
		i = -1;
		len = ft_strlen(s);
		str = (char *)malloc(len + 1);
		if (str)
		{
			while (++i < len)
				str[i] = f(i, s[i]);
			str[i] = '\0';
			return (str);
		}
	}
	return (NULL);
}
