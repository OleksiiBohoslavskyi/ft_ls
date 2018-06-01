/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohosla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 12:03:29 by obohosla          #+#    #+#             */
/*   Updated: 2016/12/01 17:21:19 by obohosla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*cp_str;
	size_t	len;
	int		i;

	i = -1;
	len = ft_strlen(str);
	cp_str = (char *)malloc(len + 1);
	if (!cp_str)
		return (NULL);
	while (str[++i] != '\0')
		cp_str[i] = str[i];
	cp_str[i] = '\0';
	return (cp_str);
}
