/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohosla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 12:02:05 by obohosla          #+#    #+#             */
/*   Updated: 2016/11/29 17:00:45 by obohosla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *str1, const char *str2)
{
	int				i;
	unsigned char	*s1ptr;
	unsigned char	*s2ptr;

	i = 0;
	s1ptr = (unsigned char *)str1;
	s2ptr = (unsigned char *)str2;
	while (s1ptr[i] == s2ptr[i] && s1ptr[i] && s2ptr[i])
		i++;
	return (s1ptr[i] - s2ptr[i]);
}
