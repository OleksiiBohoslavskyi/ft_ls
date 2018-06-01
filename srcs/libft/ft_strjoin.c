/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohosla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 13:08:12 by obohosla          #+#    #+#             */
/*   Updated: 2016/12/08 15:11:05 by obohosla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*concat;
	int		i;

	i = -1;
	if (s1 && s2)
	{
		concat = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (!concat)
			return (0);
		while (s1[++i] != '\0')
			concat[i] = s1[i];
		ft_strcpy(concat + ft_strlen(s1), s2);
		return (concat);
	}
	return (0);
}
