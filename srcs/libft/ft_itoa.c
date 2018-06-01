/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_my.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohosla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 17:42:50 by obohosla          #+#    #+#             */
/*   Updated: 2016/12/09 17:41:11 by obohosla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*str;
	size_t			size;
	size_t			e;
	unsigned int	n1;

	e = 1;
	size = (ft_count_n(n) + 1);
	str = (char *)malloc(size);
	if (!str)
		return (0);
	str[size - 1] = '\0';
	n1 = n;
	if (n < 0)
	{
		e = 2;
		str[0] = '-';
		n1 = n * (-1);
	}
	while (size-- > e)
	{
		str[size - 1] = n1 % 10 + 48;
		n1 /= 10;
	}
	return (str);
}
