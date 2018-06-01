/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohosla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 12:18:04 by obohosla          #+#    #+#             */
/*   Updated: 2016/12/01 17:21:15 by obohosla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict dst, const char *restrict src, size_t n)
{
	char *cp_str;

	cp_str = ft_strdup(src);
	*(cp_str + n) = '\0';
	ft_strcat(dst, cp_str);
	return (dst);
}
