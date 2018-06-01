/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohosla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 13:54:41 by obohosla          #+#    #+#             */
/*   Updated: 2016/12/07 15:22:27 by obohosla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *str, size_t len)
{
	char	*cpy_str;
	size_t	i;

	i = -1;
	cpy_str = (char *)malloc(len + 1);
	if (!cpy_str)
		return (NULL);
	while (++i < len && str[i] != '\0')
		cpy_str[i] = str[i];
	cpy_str[i] = '\0';
	return (cpy_str);
}
