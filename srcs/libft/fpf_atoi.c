/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohosla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 18:37:21 by obohosla          #+#    #+#             */
/*   Updated: 2017/05/13 18:38:04 by obohosla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int				ft_is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' ||\
			c == '\v' || c == '\f' || c == '\r');
}

int						fpf_atoi(const char *str)
{
	size_t				i;
	int					sign;
	unsigned long int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (ft_is_whitespace(str[i]))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while ((str[i] != '\0') && fpf_isdigit(str[i]))
	{
		if ((result > 922337203685477580 || (result == 922337203685477580
						&& (str[i] - '0') > 7)) && sign == 1)
			return (-1);
		else if ((result > 922337203685477580 || (result == 922337203685477580
						&& (str[i] - '0') > 8)) && sign == -1)
			return (0);
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return ((int)(result * sign));
}

char					*fpf_uitoa(uintmax_t tmp)
{
	char				*str;
	size_t				l;
	size_t				i;
	uintmax_t			n1;

	i = 1;
	l = (fpf_count_u(tmp) + 1);
	str = (char *)fpf_memalloc(l);
	if (!str)
		return (0);
	str[l - 1] = '\0';
	n1 = tmp;
	while (l-- > i)
	{
		str[l - 1] = n1 % 10 + 48;
		n1 /= 10;
	}
	return (str);
}

size_t					fpf_count_u(uintmax_t n)
{
	size_t				size;

	size = 0;
	while (1)
	{
		n /= 10;
		size++;
		if (n == 0)
			break ;
	}
	return (size);
}

void					fpf_bzero(void *s, size_t length)
{
	char				*str;

	str = (char *)s;
	while (length-- > 0)
		*str++ = '\0';
}
