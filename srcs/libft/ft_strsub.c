/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohosla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 18:05:25 by obohosla          #+#    #+#             */
/*   Updated: 2016/12/02 16:27:41 by obohosla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (s)
	{
		str = (char *)ft_memalloc(len + 1);
		if (str)
		{
			return (ft_strncpy(str, s + start, len));
		}
	}
	return (NULL);
}
