/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohosla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:45:15 by obohosla          #+#    #+#             */
/*   Updated: 2016/12/01 15:36:14 by obohosla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int r;

	r = n;
	if (r < 0)
	{
		r *= -1;
		ft_putchar_fd(45, fd);
	}
	if (r > 9)
	{
		ft_putnbr_fd(r / 10, fd);
	}
	ft_putchar_fd(r % 10 + 48, fd);
}
